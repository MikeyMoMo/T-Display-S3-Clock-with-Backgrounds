# T-Display-S3-Clock-with-Backgrounds
This is a little clock for the TTGO T-Display S3 with multiple background pictures and memory dimming.  I have added outlining of the text for time and date so they are easier to read against some more colorful and/or brighter background images.

I have learned a bit about installing this for the first time.  I had a friend do it and figured out I needed to add in these steps to help you get it right.  This is a slightly complicated install.  Take them, one at a time, in order.  Each step is easy.  Nothing really complicated.

1. Upgrade to ESP32 board level 3.1.3 or higher.

2. You will need to upload in LittleFS format.  To do that, install a new esp32fs.jar file from here:
   https://randomnerdtutorials.com/esp32-littlefs-arduino-ide/.  There is a different procedure for Arduino IDE v1 and v2.

3. Set your dark hours.  Look for DARK_START and DARK_END.  These are defaults and can be overridden by
   pressing the buttons to turn the display on during any of these hours.  You can also change the brightness for other hours of
   the day or night and the setting will be remembered for the same hour every day.

4. Setup your Tools menu per the .jpg included in the zip file then compile, load and run the program.  No pictures are loaded yet.  It will find no pix and use only the three built-in 
   graphics backgrounds, red, green and blue until pix are loaded.  Wait till you see time and date.  Be sure to set it to 16M.  There is no error message for this but if you forget to change to 16M, it will not honor the partitions.csv and it won't be able to load the background pictures.  I changed to a T7 board with 4M and when I came back to the T-Display, I had trouble because I forgot to change it back to 16M.  Silly me!

5. The first time it is run, it might take a while to get around to making a display.
   During this time, it is formatting the spiffs/littlefs partition to accept the LittleFS background pictures.
   You can turn on the Serial Monitor and watch the error message repeat every 0 to 5ms for 
   the entire time it is formatting the spiffs area.  Using SPIFFS, it took 5.8 minutes.  It is faster with LittleFS.

6. When you get a display, close the Serial Monitor window.  It interferes with the pictures upload.  They forgot to disable
   the Serial Monitor window during picture upload.  It is done during compile but not during file uploading.  That's a bug!

7. Select Tools>ESP32 Sketch Data Upload from the menu, then select LittleFS and press OK.  It will create a compressed file and
   send it to the spiffs partition on the board.  When done, it will reboot, all by itself, and should start working normally.

8. The partition definitions file MUST be named "partitions.csv" or it will be ignored.  Don't change the name.  I could not find any
   documentation that specifies that requirement but it is required.  And, it must be in the sketch folder.  The alternative is to edit
   the boards.txt file but that is messy and it means that any time you upgrade or reinstall, you will lose that change.  Better to just
   put it in the sketch folder and be done with it.

9. If you choose to add pictures, create them at 320x170 (w x h) pixels and save then in the data folder.  Then add them to the
   array named "FillPixArray".  As of this writing, there are 194 pictures so the next one should be 120.  The info in the array consists of:
   
      Color of the time characters, Color of the data characters, Color of the backlight characters (only on screen while changing the brightness of the screen)
      and two hatching control bools (true or false)  If true, add a darkening screen behind the time characters to lower the brightness of the
      background.

10. The files are normal .jpg files.  You do not have to create bitmaps for them.  Just copy your picture into the data file.  Thank
    the creator of the jpg library for giving us an easy way to get jpg's onto the screen without having to turn them into hex code!
    Also thanks for enabling pulling them from the data partition rather than SD card.  Made the project a lot easier!

11. Be sure to change your WiFi credentials.  Look for chSsid.

12. In the TFT_eSPI folder, edit the User_Setup_Select.h and use this setup file if you will be using the T-Display S3:
    "Setup206_LilyGo_T_Display_S3.h>  // Setup file for T-Display ESP32-S3"
    
This is a very greatly modified version of a clock originally found here: https://www.instructables.com/T-Display-S3-NTP-Clock/

I have added many features to this original code.  Very little of the original code is left.

I added:
Multiple background pictures with individual colors for each of the 3 text fields.
A grid to optionally draw behind the time text in case there is not a good font color and it needs a little darkening of the picture behind the digits so that the font will be more easily readable.  You can pick any color you want but match it to the backing picture so it is readable.  You don't want a yellow font on a primarily yellow background picture!

There are over 100 background pictures included and you can make your own.  Any jpg of 320x170 works.  Just remember to load them into LittleFS then modify the BuildAndShow routine to list the names and colors to use for the fonts and whether to use the darkening grid or not.

There is a default display brightness and if you change it, it will be saved and used the next day for the same hour in which you made the change.  If you do not change anything, the display will go dark at 11pm (2300) and come back on at 10am (1000).  This was done to save the display.  The dark times are easily changed or can also be easily disabled so that the display stays on all of the time.  I have heard that these displays will wear quickly (TFT) if kept on all of the time, so I keep them dim by default and turn it off at night.  The brightness is changable via the two buttons on the T-Display.  Initially, it changes by 2 then if you hold the button longer, it changes by 4 then, later, will change to steps of 8 until you release the button.  The brightness is shown at the top of the display and that display will disappear a few seconds after you release the button.

TBD:
Make the optional darkening grid for the brightness text field for when they are hard to see.  So far, it has not been needed so not done.
Who knows what else.  Send me suggestions.  I like to hear about new and fun stuff I can do.

Thanks for downloading.  Please send any bug reports or suggestions for additions.  I don't get upset about problem reports and love enhancement requests.

Mike Morrow

![20250321_203144](https://github.com/user-attachments/assets/1b244125-952e-4804-a90f-3337932dc1a8)
![20250321_204006](https://github.com/user-attachments/assets/344ec8c0-d894-47e9-a8b6-2c46fbbdb959)

