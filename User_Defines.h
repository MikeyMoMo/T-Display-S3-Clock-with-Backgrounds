//#define CONFIG_FOR_JOE  // A second user with a different SSID & PW

// This sets the orientation of the screen and the function of the two buttons.
// The brighten button will always be on the top.  The decrease brightness button
//  will always be on the bottom.
#define ORIENT_POWER_RIGHT 1
#define ORIENT_POWER_LEFT  3

#if defined CONFIG_FOR_JOE  // My friend's WAP credentials

const char* chSsid     = "N_Port";           // Your router SSID.
const char* chPassword = "helita1943";         // Your router password.
int WakeupHour = 10;  // Default turn on display time
int SleepHour = 23;  // Default turn off display time
// How often to change the background picture.
#define PicChgFreq 10        // Number of minutes to wait to change the BG picture.
// This is the time in milliseconds to show the brightness on screen after a button
//  is released.
#define BRIGHTNESS_SHOW_MILLIS 3000
bool  veriPix = false;  // If this is true, it will list out the tabled pic names & numbers.
int defaultBright = 28;
#define MENU_HIDE_TIME 15000  // With no button press, menu will disappear in this many ms.
int myOrientation = ORIENT_POWER_LEFT;

#else                       // My WAP credentials.

const char* chSsid     = "MikeysWAP";        // Your router SSID.
const char* chPassword = "Noogly99";         // Your router password.
int WakeupHour = 10;  // Default turn on display time
int SleepHour = 23;  // Default turn off display time
// How often to change the background picture.
#define PicChgFreq 10        // Number of minutes to wait to change the BG picture.
// This is the time in milliseconds to show the brightness on screen after a button
//  is released.
#define BRIGHTNESS_SHOW_MILLIS 3000
bool veriPix = false;  // If this is true, it will list out the tabled pic names & numbers.
int defaultBright = 32;
#define MENU_HIDE_TIME 15000  // With no button press, menu will disappear in this many ms.
int myOrientation = ORIENT_POWER_LEFT;

#endif
