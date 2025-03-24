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

//#define CONFIG_FOR_JOE
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

#include "TFT_eSPI.h"
// I wanted to use WiFiManager but it disrupts SPIFFS.  For now, I have to use SPIFFS
//  because the JPG decoder uses it.  More on that, later.
#include <WiFi.h>
#include "esp_sntp.h"      // Get UTC epoch here.
#include "Free_Fonts.h"    // Include the header file attached to this sketch
#include "OpenFontRender.h"
OpenFontRender ofr;
#include "MyFonts.h"

// Include the jpeg decoder library
#include <TJpg_Decoder.h>

//#include "SPIFFS.h" // ESP32 only
#include <LITTLEFS.h>
//#define SPIFFS LittleFS
#define FORMAT_LittleFS_IF_FAILED true

#include "Preferences.h"
Preferences preferences;
#define RO_MODE true   // Preferences calls Read-only mode
#define RW_MODE false  // Preferences calls Read-write mode
// this function determines the minimum of two numbers
#define minimum(a,b) (((a)<(b)) ? (a):(b))
// When you press a brightness button (either up or down), a little text appears in the top
//  left corner to show you what brightness you have selected.  After you stop pressing the
//  button, the text will remain there a short while.  This value is the number of milli-
//  seconds to continue to show that text.  I chose 3000 (3 seconds).
#define BRIGHTNESS_SHOW_MILLIS 3000

// WiFi.
String      stringIP;                        // IP address.
#if defined CONFIG_FOR_JOE
const char* chSsid     = "N_Port";           // Your router SSID.
const char* chPassword = "helita1943";         // Your router password.
#else
const char* chSsid     = "MikeysWAP";        // Your router SSID.
const char* chPassword = "Noogly99";         // Your router password.
#endif

/*******************************************************************************************/
//
// Global constants..
//
/*******************************************************************************************/

// Display.

#define RGB565(r,g,b) ((((r>>3)<<11) | ((g>>2)<<5) | (b>>3)))
#define MAX_BRIGHTNESS  252  // T-Display-S3 display brightness maximum.
#define MIN_BRIGHTNESS  0    // T-Display-S3 display brightness minimum.
#define PicChgFreq 10        // Number of minutes to wait to change the BG picture.

// Sprites.

#define     SPR_BATTERY_FONT_SIZE 26  // Battery sprite font size.
#define     SPR_BATTERY_HEIGHT    30  // Battery sprite height in pixels.
#define     SPR_BATTERY_WIDTH    200  // Battery sprite width in pixels.

#define     SPR_DATE_FONT_SIZE    30  // Date sprite ofr font size.
#define     SPR_DATE_HEIGHT       36  // Date sprite height in pixels.
#define     SPR_DATE_WIDTH       210  // Date sprite width in pixels.

#define     SPR_TIME_FONT_SIZE    66  // Time sprite ofr font size.
#define     SPR_TIME_HEIGHT       70  // Time sprite height in pixels.
#define     SPR_TIME_WIDTH       300  // Time sprite width in pixels.

/*******************************************************************************************/
//
// Global variables.
//
/*******************************************************************************************/

// Pictures

struct picDef
{
  char picName[30];
  unsigned int tColor;  // Text Color for Time
  unsigned int dColor;  // Text Color for Date
  unsigned int bColor;  // Text Color for Brightness
  bool tHatch;          // True or False, do hatching for Time string
  bool dHatch;          // True or False, do hatching for Date string
};
struct picDef PixInfo[250];
bool   veriPix = false;  // If this is true, it will list out the tabled pic names.

// Battery.

uint32_t    uVolt;                           // Battery voltage.

// Display  (T-Display-S3 lcd display).

TFT_eSPI    tft = TFT_eSPI();                // T-Display-S3 tft.
int         tftBL_Lvl, prevBL_Lvl = -1;      // tft brightness, prev brightness.

// Sprites.

TFT_eSprite spriteBG = TFT_eSprite(&tft);        // Background sprite. This one gets pushed to the display.
TFT_eSprite spriteBattBL = TFT_eSprite(&tft);    // Battery sprite.
TFT_eSprite spriteTime = TFT_eSprite(&tft);      // Time sprite.
TFT_eSprite spriteDate = TFT_eSprite(&tft);      // Date sprite.

// Time.
char        chDayOfMonth[3];                 // Day of month (0 through 31).
char        chDayofWeek[4];                  // Day of week (Sun to Sat).
char        chHour[3];                       // Hour.
char        chMonth[4];                      // Month.
char        chBuffer[100];                   // Work area for sprintf, etc.
const char* chNtpServer = "pool.ntp.org";    // NTP time server.
int         nTemp, defaultBright = 28;
int         iLooper, pixInLittleFS, iTemp = -1;
int         prev_sec = -1;                   // The once second update gate.
int         prev_BL_Hour;                    // We have the BL for this hour
int         BLchange;                        // Backlight change amount
JRESULT     JPB_RC;                          // Return code from drawing BG pic
uint16_t    w = 0, h = 0;
bool        displayOn = true;
time_t      workTime, UTC, startMillis, BLChangeMillis = 0;
time_t      TS_Epoch = 0;  // Set by Time Sync, printed by loop if not 0.
struct tm   timeinfo;
byte        iHour, iMinute, iSecond;
int         iDOM, iDOW, iMonth, iYear, BGPic, prev_BGPic = -1;

int randSelections;  // Will be filled in by counting pictures + graphics.

#define ORIENT_POWER_RIGHT 1
#define ORIENT_POWER_LEFT  3
int myOrientation = ORIENT_POWER_LEFT;
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

  // Analog.
  analogReadResolution(12);

  // Initialise LittleFS
  if (!LittleFS.begin(FORMAT_LittleFS_IF_FAILED)) {
    Serial.println("LittleFS initialisation failed!");
    while (1) yield(); // Stay here twiddling thumbs waiting
  }

  //  LittleFS.remove("/Marsmallows.jpg");

  pixInLittleFS = 0;
  File root = LittleFS.open("/");
  File file = root.openNextFile();
  while (file) {
    fileLen = strlen(file.name());
    // The default max filename length in LittleFS is 255 bytes for ESP32.  This can be changed in lfs.h
    //  in the library.  Look for #define "LFS_NAME_MAX 255" in that file.  255 is a lot and if you 
    //  increase it, it will add to the memory used to store the files.  It is a trivial amount, however.
    //    Serial.print("The filename "); Serial.print(file.name());
    //    Serial.printf(" is %i bytes long.\r\n", fileLen);
    fileName = file.name();
    extension = &fileName[strlen(fileName) - 4];
    if (strcmp(extension, ".jpg") == 0) pixInLittleFS++;
    file = root.openNextFile();
  }
  Serial.println("LittleFS Initialization done.");
  Serial.printf("There are %i pictures in use plus 3 graphics.\r\n",
                pixInLittleFS);

  // These are only for ESP32 only.
  //  Serial.println("\r\nLittleFS Info:");
  Serial.printf("LittleFS Total Bytes: %u\r\n", LittleFS.totalBytes());
  Serial.printf("LittleFS Used Bytes:  %u\r\n", LittleFS.usedBytes());
  Serial.printf("LittleFS Free Bytes:  %u\r\n",
                LittleFS.totalBytes() - LittleFS.usedBytes());

  // Init the display.
  tft.init();

  tft.setRotation(myOrientation);
  if (myOrientation = ORIENT_POWER_LEFT) {
    incrPin = 0; decrPin = 14;
  } else {
    incrPin = 14; decrPin = 0;
  }

  // These two work prior to board 3.x.x
  //  ledcSetup(0, 10000, 8);   // Defines PWM timer 0 as PWM output.
  //  ledcAttachPin(TFT_BL, 0);
  // This one needs to be used after 3.x.x is installed.
  ledcAttach(TFT_BL, 5000, 8);  // PWM timer automatically assigned.
  ledcWrite(TFT_BL, defaultBright);  // Turn the display on for init messages.

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
  ofr.setDrawer(spriteTime);
  ofr.unloadFont();
  if (ofr.loadFont(ArialRoundedMTBold, sizeof(ArialRoundedMTBold))) {
    Serial.println("Render loadFont error for ArialRoundedMTBold.");
    while (1);
  }

  // Date sprite.
  spriteDate.createSprite(tft.width(), SPR_DATE_HEIGHT);
  spriteDate.setSwapBytes(true);
  spriteDate.setSwapBytes(false);

  ofr.setDrawer(spriteDate);
  ofr.unloadFont();
  if (ofr.loadFont(ArialRoundedMTBold, sizeof(ArialRoundedMTBold))) {
    Serial.println("Render loadFont error for ArialRoundedMTBold.");
    while (1);
  }

  // Battery.
  spriteBattBL.createSprite(SPR_BATTERY_WIDTH, SPR_BATTERY_HEIGHT);
  spriteBattBL.setSwapBytes(true);
  ofr.setDrawer(spriteBattBL);
  ofr.unloadFont();
  if (ofr.loadFont(ArialRoundedMTBold, sizeof(ArialRoundedMTBold))) {
    Serial.println("Render loadFont error for ArialRoundedMTBold.");
    while (1);
  }

  // Enable the module to operate from an external LiPo battery.
  pinMode(15, OUTPUT);  // Battery Control
  digitalWrite(15, 1);  // 1 to stop using battery ?  1 to use ?

  FillPixArray();  // Load the picture names and colors into the array.
  // There are 3 digital graphics that are first (so they will run if no p ix loaded)
  //  so that has to be accounted for in the following statement.  BGPic is really the
  //  sum of the number of pix plus the 3 graphics for the random selection to be able
  //  to pick from all available backgrounds.
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
  stringIP = WiFi.localIP().toString();
  Serial.printf("\nWiFi connected to %s at %s\r\n", chSsid, stringIP);
  tft.fillScreen(TFT_BLACK);
  tft.drawString("WiFi connected to:", 0, 0, 4);
  tft.drawString(stringIP, 0, 30, 4);
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
  // And we are off to the races!
}
/*******************************************************************************************/
void loop()
/*******************************************************************************************/
{
  startMillis = millis();

  GetCurrentTime();
  if ((iDOW == 0) && (iHour == 4) && (iMinute == 2) && (iSecond == 10))
    ESP.restart();
  CheckButtons();
  SaveBrightness();

  if (prev_sec == iSecond) return;
  prev_sec = iSecond;

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
      Serial.printf("%02i:%02i:%02i - DISPOFF command issued.\r\n",
                    iHour, iMinute, iSecond);
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
    Serial.printf("%02i:%02i:%02i - DISPON command issued.\r\n",
                  iHour, iMinute, iSecond);
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
  BuildAndShow();
  if (iMinute == 0 && iSecond == 0) HourDance();
  delay(1);

  if (iMinute == 20 && iSecond < 5)
    Serial.printf("Time for loop: %lu\r\n", millis() - startMillis);
}
