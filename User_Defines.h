//#define CONFIG_FOR_JOE  // A second user with a different SSID & PW

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

#endif

// This sets the orientation of the screen and the function of the two buttons.
// The brighten button will always be on the top.  The decrease brightness button
//  will always be on the bottom.
#define ORIENT_POWER_RIGHT 1
#define ORIENT_POWER_LEFT  3
int myOrientation = ORIENT_POWER_LEFT;

// The maximum brightness that the button will allow.
#define MAX_BRIGHTNESS  254  // T-Display-S3 display brightness maximum.
// The minimum brightness that the button will allow.
#define MIN_BRIGHTNESS  0    // T-Display-S3 display brightness minimum.

#define MENU_HIDE_TIME 15000  // With no button press, menu will disappear in this many ms.
