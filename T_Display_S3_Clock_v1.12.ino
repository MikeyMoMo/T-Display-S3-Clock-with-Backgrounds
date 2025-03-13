/****************************************************************************/
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
//             https://www.instructables.com/T-Display-S3-NTP-Clock/
//
//             Thanks for the Instructable, I leaned about transparent
//             sprites and how to use them.  Then...
//             HEAVILY modified by Mike Morrow (GitHub: MikeyMoMo)
//
/****************************************************************************/
//
// T-Display-S3 Clock Parts List.
//
//  1) One lilygo T-Display-S3.
//  2) One 3.7V 1000ma lithium rechargable battery with
//      2 pin JST1.25 connector. (optional)
//
/****************************************************************************/
//
// Included files.
//
/****************************************************************************/

#include "TFT_eSPI.h"
#include <WiFi.h>
#include "esp_sntp.h"      // Get UTC epoch here.
#include "Free_Fonts.h"    // Include the header file attached to this sketch
#include "OpenFontRender.h"
OpenFontRender ofr;
#include "MyFonts.h"

// Include the jpeg decoder library
#include <TJpg_Decoder.h>

// Include SPIFFS
#define FS_NO_GLOBALS
#include <FS.h>
#ifdef ESP32
#include "SPIFFS.h" // ESP32 only
#endif

#include "Preferences.h"
Preferences preferences;
#define RO_MODE true   // Preferences calls Read-only mode
#define RW_MODE false  // Preferences calls Read-write mode
// this function determines the minimum of two numbers
#define minimum(a,b) (((a)<(b)) ? (a):(b))
#define BRIGHTNESS_SHOW_MILLIS 3000
//#define DO_GRAPHICS_BACKGROUND  // If commented, use BG SPIFFS picture.
/****************************************************************************/
//
// Global constants..
//
/****************************************************************************/

// Display.

#define RGB565(r,g,b) ((((r>>3)<<11) | ((g>>2)<<5) | (b>>3)))
#define     MAX_BRIGHTNESS  252  // T-Display-S3 display brightness maximum.
#define     MIN_BRIGHTNESS  0    // T-Display-S3 display brightness minimum.

// Sprites.

#define     SPRITE_BATTERY_FONT_SIZE  4  // Battery sprite font size.
#define     SPRITE_BATTERY_HEIGHT    30  // Battery sprite height in pixels.
#define     SPRITE_BATTERY_WIDTH    200  // Battery sprite width in pixels.

#define     SPRITE_DATE_FONT_SIZE     4  // Date sprite font size.
#define     SPRITE_DATE_HEIGHT       30  // Date sprite height in pixels.
#define     SPRITE_DATE_WIDTH       210  // Date sprite width in pixels.

#define     SPRITE_TIME_FONT_SIZE     6  // Time sprite font size.
#define     SPRITE_TIME_HEIGHT       70  // Time sprite height in pixels.
#define     SPRITE_TIME_WIDTH       300  // Time sprite width in pixels.

/****************************************************************************/
//
// Global variables.
//
/****************************************************************************/

// Battery.

uint32_t    uVolt;                           // Battery voltage.

// Display (T-Display-S3 lcd display).

TFT_eSPI    tft = TFT_eSPI();                // T-Display-S3 tft.
int         tftBL_Lvl;                       // tft brightness.

// Sprites.

TFT_eSprite spriteBG = TFT_eSprite(&tft);    // Background sprite.
TFT_eSprite spriteBatt = TFT_eSprite(&tft);  // Battery sprite.
TFT_eSprite spriteDate = TFT_eSprite(&tft);  // Date sprite.
TFT_eSprite spriteTime = TFT_eSprite(&tft);  // Time sprite.

// Time.
char        chDayOfMonth[3];                 // Day of month (0 through 31).
char        chDayofWeek[4];                  // Day of week (Sun to Sat).
char        chHour[3];                       // Hour.
char        chMonth[4];                      // Month.
char        chBuffer[100];                   // Work area for sprintf, etc.
const char* chNtpServer = "pool.ntp.org";    // NTP time server.
int         nTemp, defaultBright = 28;
int         iLooper, pixInSPIFFS, iTemp = -1;
int         prev_sec = -1;                   // The once second update gate.
int         BLchange;                        // Backlight change amount

uint16_t    w = 0, h = 0;
bool        displayOn = true;
time_t      workTime, UTC, startMillis, BLChangeMillis = 0;
time_t      TS_Epoch = 0;  // Set by Time Sync, printed by loop if not 0.
struct tm   timeinfo;
byte        iHour, iMinute, iSecond;
int         iDOM, iDOW, iMonth, iYear, BGPic, prev_BGPic = -1;

int randSelections;  // Will be filled in by counting pictures + graphics.

// WiFi.
String      stringIP;                        // IP address.
const char* chSsid     = "MikeysWAP";        // Your router SSID.
const char* chPassword = "Noogly99";         // Your router password.

#define ORIENT_POWER_RIGHT 1
#define ORIENT_POWER_LEFT  3
int myOrientation = ORIENT_POWER_LEFT;
int incrPin, decrPin;  // Will be set depending on board orientation.
/****************************************************************************/
void setup()
/****************************************************************************/
{
  Serial.begin(115200); delay(4000);
  Serial.println("This is T-Display S3 Visual Clock, running from:");
  Serial.println(__FILE__);

  // Analog.
  analogReadResolution(12);

  // Initialise SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS initialisation failed!");
    while (1) yield(); // Stay here twiddling thumbs waiting
  }

  // SPIFFS.remove("/BubblyBackground170x320.jpg");

  pixInSPIFFS = 0;
  File root = SPIFFS.open("/");
  File file = root.openNextFile();
  while (file) {
    //    Serial.print("Found SPIFFS file: /");
    //    Serial.println(file.name());
    pixInSPIFFS++;
    file = root.openNextFile();
  }
  Serial.println("SPIFFS Initialization done.");
  Serial.printf("There are %i pictures in use plus 2 graphics.\r\n",
                pixInSPIFFS);

  TJpgDec.setSwapBytes(true); // We need to swap the colour bytes (endianess)
  // The jpeg image can be scaled by a factor of 1, 2, 4, or 8
  TJpgDec.setJpgScale(1);
  // The decoder must be given the exact name of the rendering function above
  TJpgDec.setCallback(spr_output);

  // Note name preceded with "/"
  // Just if you want to see the size of the picture.
  //  TJpgDec.getFsJpgSize(&w, &h, "/MistyValley.jpg");
  //  Serial.print("Width = "); Serial.print(w); Serial.print(", height = ");
  //  Serial.println(h);

  // Init the display.
  tft.init();

  tft.setRotation(myOrientation);
  if (myOrientation = ORIENT_POWER_LEFT) {
    incrPin = 0; decrPin = 14;
  } else {
    incrPin = 14; decrPin = 0;
  }

  // These two work prior to board 3.x.x
  //  ledcSetup(0, 10000, 8);
  //  ledcAttachPin(38, 0);
  // This one needs to be used after 3.x.x is installed.
  ledcAttach(38, 5000, 8);
  ledcWrite(38, defaultBright);  // Get the display on for init messages.

  // Sprites.
  // Background sprite.
  tft.fillScreen(TFT_BLACK);
  tft.drawString("Allocating Sprites.", 0, 0, 4);
  spriteBG.createSprite(tft.width(), tft.height());
  spriteBG.setSwapBytes(false);
  spriteBG.setTextColor(TFT_WHITE, TFT_BLACK);

  // Time sprite.
  spriteTime.createSprite(tft.width(), SPRITE_TIME_HEIGHT);
  spriteTime.setSwapBytes(true);
  spriteTime.setTextDatum(TL_DATUM);
  ofr.setDrawer(spriteTime);
  ofr.unloadFont();
  if (ofr.loadFont(ArialRoundedMTBold, sizeof(ArialRoundedMTBold))) {
    Serial.println("Render loadFont error for ArialRoundedMTBold.");
    while (1);
  }
  ofr.setFontSize(66);

  // Date sprite.
  spriteDate.createSprite(SPRITE_DATE_WIDTH, SPRITE_DATE_HEIGHT);
  spriteDate.setSwapBytes(true);

  // Battery.
  spriteBatt.createSprite(SPRITE_BATTERY_WIDTH, SPRITE_BATTERY_HEIGHT);
  spriteBatt.setSwapBytes(true);
  spriteBatt.setTextColor(TFT_YELLOW, TFT_BLACK);
  // Enable the module to operate from an external LiPo battery.

  pinMode(15, OUTPUT);
  digitalWrite(15, 1);

  // Start WiFi.
  tft.fillScreen(TFT_BLACK);
  tft.drawString("Awaiting WiFi connection...", 0, 0, 4);
  Serial.print("Awaiting WiFi connection...");
  WiFi.begin(chSsid, chPassword);
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

  pickHourBrightness();
  Serial.printf("Setup setting brightness level for hour %i of %i\r\n",
                iHour, tftBL_Lvl);

  randSelections = pixInSPIFFS + 2;
  BGPic = int(random(randSelections)); prev_BGPic = -1;

  tft.fillRect(0, 0, tft.width(), tft.height(), TFT_BLACK);
  // And we are off to the races!
}
/****************************************************************************/
void loop()
/****************************************************************************/
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

  if (tftBL_Lvl == 0) {
    delay(100);
    return;
  }

  // Note: If the sketch is started on a 0 brightness hour, then the
  //       display will be blank.  When you turn it up, there will be
  //       a background picture already there.  The random for it was
  //       done in setup and as soon as tftBL_Lvl gets to 2, it will be
  //       loaded.  You won't even notice.  I promise!  So nothing
  //       special needs to be done here.  BuildAndShow will pick up on
  //       it and we are off to the races.  Giddy Up, Old Paint! Yee Hah!!
  if (iMinute % 10 == 0 & iSecond == 0) {
    BGPic = int(random(randSelections));
    while (iTemp == BGPic) BGPic = int(random(randSelections));
    iTemp = BGPic; prev_BGPic = -1;  // Force one pass thru file name display.
  }

  // This runs repetitively.  Pic change will show up next run.
  BuildAndShow();
  if (iMinute == 0 && iSecond == 0) HourDance();
  delay(1);

  if (iMinute == 20 && iSecond < 5)
    Serial.printf("Time for loop: %lu\r\n", millis() - startMillis);
}
