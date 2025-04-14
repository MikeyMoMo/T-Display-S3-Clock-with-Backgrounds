/*******************************************************************************************/
//
//                         T-Display-S3 Clock
//                         Resolution 170x320
//
//                        Copyright © 2023 by
//                      Zumwalt Properties, LLC.
//                        All Rights Reserved.
//
//             This software is for NON COMMERCIAL USE ONLY
//             in accordance with the licensing agreement.
//
//             The original can be found here:
//         https://www.instructables.com/T-Display-S3-NTP-Clock/
//
//             Thanks for the Instructable, I leaned about transparent
//             sprites and how to use them.  Then...
//             HEAVILY modified by Mike Morrow (GitHub: MikeyMoMo)
//             The most current uploaded version can be found at:
//         https://github.com/MikeyMoMo/T-Display-S3-Clock-with-Backgrounds

// See included file "Working settings for the Clock with BG.jpg" for IDE setup info.

/*******************************************************************************************/
//
// T-Display-S3 Clock Parts List.
//
//  1) One lilygo T-Display-S3.
//  2) One 3.7V 1000ma lithium rechargable battery with
//      2 pin JST1.25 connector. (optional)
//
/*******************************************************************************************/
//
// Included files.
//
/*******************************************************************************************/
#include "User_Defines.h";

#include "TFT_eSPI.h"
// I wanted to use WiFiManager but it disrupts SPIFFS.  For now, I have to use SPIFFS
//  because the JPG decoder uses it.  More on that, later.  Changed to LittleFS.  May
//  try WiFiManager again.
#include <WiFi.h>
#include "esp_sntp.h"      // Get UTC epoch here.
#include "Free_Fonts.h"    // Include the header file attached to this sketch
#include "MyFonts.h"

// Include the jpeg decoder library
#include <TJpg_Decoder.h>

#include <LITTLEFS.h>
#define FORMAT_LittleFS_IF_FAILED true

#include "Preferences.h"
Preferences preferences;
#define RO_MODE true   // Preferences calls Read-only mode
#define RW_MODE false  // Preferences calls Read-write mode

#define NO_OUTLINE false  // Don't put in outline this time.
#define DO_OUTLINE true   // Do outline as per normal.

// this function determines the minimum of two numbers
#define minimum(a,b) (((a)<(b)) ? (a):(b))

// When you press a brightness button (either up or down), a little text appears in the top
//  left corner to show you what brightness you have selected.  After you stop pressing the
//  button, the text will remain there a short while.  This value is the number of milli-
//  seconds to continue to show that text.  I chose 3000 (3 seconds).

// Press both buttons together to get a little two-button menu of things you can change.
// I did the buttons myself rather than invoke a library.  If I ever think of any other
//  function, I might use button2 library but, for now, this is all I want to do with the
//  menu.  If you don't press a button, it will clear after 15 seconds and go back to the
//  clock.  There is a menu option to return to the clock earlier than that.  Any time you
//  press a button, it extends the 15 seconds again so it will not go away right under you.

// WiFi.
String      stringIP;                        // IP address.

/*******************************************************************************************/
//
// Global constants..
//
/*******************************************************************************************/

// Display.

#define RGB565(r,g,b) ((((r>>3)<<11) | ((g>>2)<<5) | (b>>3)))

/*******************************************************************************************/
//
// Global variables.
//
/*******************************************************************************************/
// Sprites.

#define     SPR_BATTERY_FONT_SIZE 26  // Battery sprite ofr font size.
#define     SPR_BATTERY_HEIGHT    30  // Battery sprite height in pixels.
#define     SPR_BATTERY_WIDTH    200  // Battery sprite width in pixels.

#define     SPR_DATE_FONT_SIZE    30  // Date sprite ofr font size.
#define     SPR_DATE_HEIGHT       30  // Date sprite height in pixels.
#define     SPR_DATE_WIDTH       210  // Date sprite width in pixels.

#define     SPR_TIME_FONT_SIZE    66  // Time sprite ofr font size.
#define     SPR_TIME_HEIGHT       75  // Time sprite height in pixels.
#define     SPR_TIME_WIDTH       300  // Time sprite width in pixels.

#define     SPR_MENU_FONT_SIZE     4  // Menu sprite uses builtin font 4
#define     SPR_MENU_HEIGHT       40  // Menu sprite height is 42 pixels
#define     SPR_MENU_WIDTH       320  // Menu sprite width is the display width

// Pictures

struct picDef
{
  char picName[30];
  unsigned int tColor;   // Text Color for Time
  unsigned int dColor;   // Text Color for Date
  unsigned int bColor;   // Text Color for Brightness
  unsigned int oColor;   // Outline Color
  bool tHatch;           // True or False, do hatching for Time string
  bool dHatch;           // True or False, do hatching for Date string
};
struct picDef pInfo[300];
bool   veriPix = true;  // If this is true, it will list out the tabled pic names.

// Battery.

uint32_t    uVolt;       // Battery voltage reading
#define VOLT_AVG_CT 10    // How many seconds to average
// Trailing average of the battery voltage
uint32_t    iVoltHist[VOLT_AVG_CT] = {0, 0, 0, 0, 0};
byte    voltSamples = 0;
// If true, will show battery voltage at the top left or the screen.  Else, blank.
bool showVolts;

// Display  (T-Display-S3 lcd display).

TFT_eSPI    tft = TFT_eSPI();                // T-Display-S3 tft.
int         tftBL_Lvl, prevBL_Lvl = -1;      // tft brightness, prev brightness.

// Sprites.

// This is the one that gets pushed to the display.
// The Momma. The Big Kahuna. The Big Cheese. The Boss!
TFT_eSprite spriteBG = TFT_eSprite(&tft);        // Background sprite.
// These are intermediary sprites to implement invisibility for the fonts.  Spooky!!!!
TFT_eSprite spriteBattBL = TFT_eSprite(&tft);    // Battery sprite.
TFT_eSprite spriteTime   = TFT_eSprite(&tft);    // Time sprite.
TFT_eSprite spriteDate   = TFT_eSprite(&tft);    // Date sprite.
TFT_eSprite spriteMenu   = TFT_eSprite(&tft);    // Menu sprite.

// Time and other stuff.

char        chDayOfMonth[3];               // Day of month (0 through 31).
char        chDayofWeek[4];                // Day of week (Sun to Sat).
char        chHour[3];                     // Hour.
char        chMonth[4];                    // Month.
char        chBuffer[100];                 // Work area for sprintf, etc.
char        input;                         // Read in place for Serial.read()
const char* chNtpServer = "pool.ntp.org";  // NTP time server.
int         nTemp, defaultBright = 28;
int         iLooper, pixInLittleFS, iTemp = -1;
int         prev_sec = -1;                 // The once second update gate.
int         prev_BL_Hour;                  // We have the BL for this hour
int         BLchange;                      // Backlight change amount
int         dRead;                         // Reading from digitalRead.
int         x, y;                          // For setCursor use.
int         iUserPic = -1;                 // Picture req'd by the user on Serial monitor
JRESULT     JPB_RC;                        // Return code from drawing BG pic.
uint16_t    w = 0, h = 0;
bool        displayOn = true;
bool        WakeUp;
bool        displayInverted = true;        // Just a little test.
bool        ShowFields = true;
time_t      workTime, UTC, startMillis, BLChangeMillis = 0;
time_t      menuHide;
time_t      TS_Epoch = 0;  // Set by Time Sync, printed by loop if not 0.
struct tm   timeinfo;
time_t      now;
byte        iHour, iMinute, iSecond;
int         iDOM, iDOW, iMonth, iYear, BGPic, prev_BGPic = -1;

int randSelections;  // Will be filled in by counting pictures + graphics.

int incrPin, decrPin;  // Will be set depending on board orientation.
/*******************************************************************************************/
void setup()
/*******************************************************************************************/
{
  int fileLen;
  const char* fileName;
  const char* extension;

  Serial.begin(115200); delay(5000);
  Serial.println("This is T-Display S3 Visual Clock, running from:");
  Serial.println(__FILE__);
  Serial.println("For the T-Display S3 target board, use tft_espi config# 206");

  // Analog.
  analogReadResolution(12);  // For battery voltage reading.

  // Initialise LittleFS
  Serial.println("Initializing LittleFS.");
  if (!LittleFS.begin(FORMAT_LittleFS_IF_FAILED)) {
    Serial.println("LittleFS initialisation failed!");
    while (1) yield(); // Stay here twiddling thumbs waiting
  }

  //  LittleFS.remove("/Marsmallows.jpg");

  Serial.println("Counting .jpg files in LittleFS.");
  pixInLittleFS = 0;
  File root = LittleFS.open("/");
  File file = root.openNextFile();
  while (file) {
    fileLen = strlen(file.name());
    // The default max filename length in LittleFS is 255 bytes for ESP32.
    // This can be changed in lfs.h in the library. Look for #define "LFS_NAME_MAX 255" in
    //  that file.  255 is a lot and if you increase it, it will add to the memory used to
    //  store the files.  It is a trivial amount, however, comparted to file data size.
    //  Serial.print("The filename "); Serial.print(file.name());
    //  Serial.printf(" is %i bytes long.\r\n", fileLen);  // Verify filename byte length.
    fileName = file.name();  // Get it somewhere usable, locally.
    extension = &fileName[strlen(fileName) - 4];  // Get the last 4 bytes of the filename.
    if (strcmp(extension, ".jpg") == 0)  // Is this a jpeg file (.jpg)?
      pixInLittleFS++;  // If so, count it.
    file = root.openNextFile();  // Next file, please.  There are no folder used here.
  }
  Serial.println("LittleFS Initialization done.");  // Whew!
  // These are only for ESP32 only.
  Serial.printf("LittleFS Total Bytes: %8u\r\n", LittleFS.totalBytes());
  Serial.printf("LittleFS Used Bytes:  %8u\r\n", LittleFS.usedBytes());
  Serial.printf("LittleFS Free Bytes:  %8u\r\n",
                LittleFS.totalBytes() - LittleFS.usedBytes());

  tft.init();  // Init the display.  What else?

  tft.setRotation(myOrientation);
  if (myOrientation = ORIENT_POWER_LEFT) {  // Asjust pins based on display orientation.
    incrPin = 0; decrPin = 14;  // Increase brightness is always on top, and...
  } else {
    incrPin = 14; decrPin = 0;  // Decrease brightness is always on the bottom button.
  }

  // These two work prior to board 3.x.x  There are other changes needed if this is used.
  //  ledcSetup(0, 10000, 8);   // Defines PWM timer 0 as PWM output.
  //  ledcAttachPin(TFT_BL, 0);

  // This one needs to be used after 3.x.x is installed.
  // The big change is that you no longer specify a PWM channel.  It chooses one for you.
  // You reference the pin and it uses the associated PWM channel that it picked for you.
  ledcAttach(TFT_BL, 5000, 8);  // PWM timer automatically assigned.
  ledcWrite(TFT_BL, defaultBright);  // Turn the display on bigly for init messages.

  // Sprites.

  // Background sprite.

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Allocating Sprites.", 0, 0, 4);

  spriteBG.createSprite(tft.width(), tft.height());
  spriteBG.setSwapBytes(false);
  spriteBG.setTextColor(TFT_WHITE, TFT_BLACK);

  // Time sprite.
  spriteTime.createSprite(tft.width(), SPR_TIME_HEIGHT);
  spriteTime.setSwapBytes(true);
  spriteTime.setTextDatum(TL_DATUM);
  spriteTime.loadFont(BritanicBold66);

  // Date sprite.
  spriteDate.createSprite(tft.width(), SPR_DATE_HEIGHT);
  spriteDate.setSwapBytes(true);
  //  spriteDate.setSwapBytes(false);
  spriteDate.loadFont(BritanicBold36);
  spriteDate.setTextDatum(TL_DATUM);

  spriteMenu.createSprite(tft.width(), SPR_MENU_HEIGHT);
  spriteMenu.setSwapBytes(true);
  //  spriteMenu.setSwapBytes(false);
  spriteMenu.setTextDatum(TL_DATUM);

  // Battery and Brightness.  Or look for SHOW_BATT_VOLTS and comment that #define to not
  //  show battery voltage.  It will still show your Brightness selection when you are
  //  pressing either button.

  spriteBattBL.createSprite(SPR_BATTERY_WIDTH, SPR_BATTERY_HEIGHT);
  spriteBattBL.setSwapBytes(true);
  spriteBattBL.loadFont(BritanicBold26);
  spriteBattBL.setTextDatum(TL_DATUM);

  preferences.begin("UserPrefs", RO_MODE);
  showVolts = preferences.getBool("showVolts", false);  // Never been set? False!
  preferences.end();
  if (showVolts)
    Serial.println("Battery voltage will be shown.");
  else
    Serial.println("Battery voltage will not be shown.");

  // Enable the module to operate from an external LiPo battery.
  pinMode(15, OUTPUT);  // Battery Control
  digitalWrite(15, 1);  // 0 to stop using battery (sorta) or 1 to use it.
  // There is NO BLEEDING SWITCH!!!!!!  What a junky design!!!
  delay(1000);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Fill Pictures Array.", 0, 0, 4);
  FillPixArray();  // Load the picture names and colors into the array.
  // There are 3 digital graphics that are first (so they will run if no p ix loaded)
  //  so that has to be accounted for in the following statement.  BGPic is really the
  //  sum of the number of pix plus the 3 graphics for the random selection to be able
  //  to pick from all available backgrounds.
  Serial.printf("There are %i jpg pictures in LittleFS + 3 Digital Graphics.\r\n",
                pixInLittleFS);
  Serial.printf("I loaded %i pictures into the table + 3 Digital Graphics.\r\n", BGPic - 3);

  // Start WiFi.
  tft.fillScreen(TFT_BLACK);
  tft.drawString("Awaiting WiFi connection to", 0, 0, 4);
  tft.drawString(chSsid, 0, 30, 4);
  Serial.print("Awaiting WiFi connection to "); Serial.print(chSsid);
  WiFi.begin(chSsid, chPassword); delay(1500);
  // Wait for a connection.
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  // Connected.
  tft.fillScreen(TFT_BLACK);
  stringIP = WiFi.localIP().toString();
  Serial.printf("\nWiFi connected to %s at %s\r\n", chSsid, stringIP);
  tft.drawString("WiFi connected to:", 0, 0, 4);
  tft.drawString(stringIP, 0, 30, 4);
  Serial.print("Wifi RSSI = "); Serial.println(WiFi.RSSI());
  String myMACAddress = WiFi.macAddress();
  Serial.print("MAC Address = "); Serial.println(myMACAddress);

  stringIP = WiFi.gatewayIP().toString();
  Serial.printf("WiFi Gateway IP %s\r\n", stringIP);
  stringIP = WiFi.dnsIP(0).toString();
  Serial.printf("WiFi DNS #1 %s\r\n", stringIP);
  stringIP = WiFi.dnsIP(1).toString();
  Serial.printf("WiFi DNS #2 %s\r\n", stringIP);

  delay(2000);

  // Time.
  tft.fillScreen(TFT_BLACK);
  tft.drawString("Awaiting correct time...", 0, 0, 4);
  initTime();

  pinMode(incrPin, INPUT_PULLUP);
  pinMode(decrPin, INPUT_PULLUP);

  setHourBrightness();
  Serial.printf("Setup setting brightness level for hour %i of %i\r\n",
                iHour, tftBL_Lvl);

  randSelections = pixInLittleFS + 3;  //R, G and B rectangles added to pix count
  BGPic = int(random(randSelections));

  TJpgDec.setSwapBytes(true); // We need to swap the colour bytes (endianess)
  // The jpeg image can be scaled by a factor of 1, 2, 4, or 8
  TJpgDec.setJpgScale(1);
  // The decoder must be given the exact name of the rendering function.
  TJpgDec.setCallback(spr_output);

  tft.fillRect(0, 0, tft.width(), tft.height(), TFT_BLACK);
  Serial.println(); showInputOptions();
  // And we are off to the races!
}
/*******************************************************************************************/
void loop()
/*******************************************************************************************/
{
  startMillis = millis();

  while (Serial.available() > 0) { // Check if data is available to read
    char input = Serial.read(); // Read one character from the serial input
    input = toupper(input); // Convert the character to uppercase
    //    Serial.print("Received char: "); Serial.println(input); Serial.flush();
    // In use: B - Change battery usage state
    //         F - Toggle all fields
    //         I - (Testing) Invert display colors
    //         P - Print name of current picture on Serial Monitor
    //         R - (Testing) Change random selection of picture (change background pic)
    //         V - Toggle battery voltage display
    switch (input) {
      case '#':  // Start the user picture selection number entry
        iUserPic = 0; break;
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        if (iUserPic > -1) {
          iUserPic = iUserPic * 10 + int(input - '0');
          // Serial.printf("iUserPic now %i\r\n", iUserPic);
        } else {
          Serial.println("Unexpected number input.");
        }
        break;
      case '+':
        BGPic++;
        if (BGPic == randSelections) {
          Serial.println("Picture selection number too high.  Resetting to 0.");
          BGPic = 0;
        }
        break;
      case '-':
        BGPic--;
        if (BGPic < 0) {
          Serial.println("Picture selection number too low.  Resetting to 0.");
          BGPic = 0;
        }
        break;
      case 'R':  // Change BG pic
        BGPic = int(random(randSelections));  // Name will be shown by SetPic_Colors.
        iUserPic = -1;
        break;
      case 'P':  // Name current BG pic
        iUserPic = -1;
        Serial.print("\r\nPicture showing is: ");
        Serial.print(pInfo[BGPic].picName);
        Serial.printf(", with brightness of %i/255.\r\n", tftBL_Lvl);
        showInputOptions();
        break;
      case 'V':  // Toggle showing battery voltage
        iUserPic = -1;
        showVolts = !showVolts;
        Serial.printf("\r\Battery voltage will%s be shown.\r\n", showVolts ? "" : " not");
        showInputOptions();
        break;
      case 'B':  // Toggle battery usage state
        iUserPic = -1;
        dRead = digitalRead(15);
        if (dRead == 0) {
          digitalWrite(15, 1);
          Serial.println("\r\nBattery usage state set to full power. There is no off state.");
        } else {
          digitalWrite(15, 0);
          Serial.println("\r\nBattery usage state set to partial power. There is no off state.");
        }
        showInputOptions();
        break;
      case 'F':  // Toggle showing all fields
        iUserPic = -1;
        ShowFields = !ShowFields;
        Serial.printf("\r\nFields will%s be shown.\r\n", ShowFields ? "" : " not");
        showInputOptions();
        break;
      case '?':
        iUserPic = -1;
        showInputOptions();
        break;
      case 'I':  // Invert screen
        iUserPic = -1;
        if (displayInverted) {
          tft.invertDisplay(false);
          displayInverted = false;
        } else {
          tft.invertDisplay(true);
          displayInverted = true;
        }
        break;    // Optional here. Included for completeness.
      case '\r':  // Ignore
      case '\n':  // Ignore
        if (iUserPic > randSelections) {
          Serial.println("Picture selection number too high.");
          iUserPic = -1;
        }
        if (iUserPic > -1) BGPic = iUserPic;
        iUserPic = -1;
        break;
      default:
        iUserPic = -1;
        Serial.printf("\r\nUnknown input \'%c\'!", input);  // Handle unknown input
        showInputOptions();
        break;
    }
  }

  GetCurrentTime();
  if ((iDOW == 0) && (iHour == 4) && (iMinute == 2) && (iSecond == 10))
    ESP.restart();

  CheckButtons();

  if (prev_sec == iSecond) return;
  prev_sec = iSecond;

  SaveOptions();

  if (TS_Epoch > 0) {
    Serial.print("\n**> Time Sync Received at ");
    Serial.println(ctime(&TS_Epoch));
    TS_Epoch = 0;
  }

  if (prev_BL_Hour != iHour) {
    prev_BL_Hour = iHour;
    setHourBrightness();  // This is called by HourDance, too.
  }

  if (iMinute % PicChgFreq == 0 & iSecond == 0) {
    iTemp = int(random(randSelections));
    while (iTemp == BGPic) iTemp = int(random(randSelections));
    BGPic = iTemp;
  }

  if (tftBL_Lvl == 0) {
    delay(100);
    if (prevBL_Lvl != 0) {
      prevBL_Lvl = 0;
      tft.fillRect(0, 0, tft.width(), tft.height(), TFT_BLACK);
      tft.writecommand(ST7789_DISPOFF); //turn off lcd display
      //      Serial.printf("%02i:%02i:%02i - DISPOFF command issued.\r\n",
      //                    iHour, iMinute, iSecond);
    }
    return;
  }

  // It only falls through to here if the BL level is > 0.  First time?  Turn on the display.
  // When you want to turn it back on you can use the below.
  // In my experience you need to reinitialize the screen.
  if (prevBL_Lvl == 0) {
    prevBL_Lvl = tftBL_Lvl;
    // tft.init();  // Not needed.  Less visual noise without it and it works OK.
    tft.writecommand(ST7789_DISPON); //turn on display
    //    Serial.printf("%02i:%02i:%02i - DISPON command issued.\r\n",
    //                  iHour, iMinute, iSecond);
    ledcAttach(TFT_BL, 5000, 8);   // PWM timer automatically assigned to pin# (TFT_BL).
    ledcWrite(TFT_BL, tftBL_Lvl);  // Activate at required level again by pin# (TFT_BL).
  }

  // Note: If the sketch is started on a 0 brightness hour, then the
  //       display will be blank.  When you turn it up, there will be
  //       a background picture already there.  The random for it was
  //       done in setup and as soon as tftBL_Lvl gets to 2, it will be
  //       loaded.  You won't even notice.  I promise!  So nothing
  //       special needs to be done here.  BuildAndShow will pick up on
  //       it and we are off to the races.  Giddy Up, Old Paint! Yee Hah!!
  // This runs repetitively if the BL level is > 0.
  // BG Pic change will show up next pass through here.
  BuildAndShow(DO_OUTLINE);
  if (iMinute == 0 && iSecond == 0) HourDance();
  delay(1);

  //  if (iSecond < 5)  // Show every minute.
  if (iMinute == 20 && iSecond < 5)  // Show once per hour.
    Serial.printf("Time for loop: %lu\r\n", millis() - startMillis);
}
