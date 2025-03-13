# T-Display-S3-Clock-with-Backgrounds
This is a little clock for the TTGO T-Display S3 with multiple background pictures and dimming.

This is a very greatly modified version of a clock originally found here: https://www.instructables.com/T-Display-S3-NTP-Clock/

I have added many features to this original code.  Very little of the original code is left.

I added:
Multiple background pictures with individual colors for each of the 3 text fields.
A grid to optionally draw behind the time text in case there is not a good font color and it needs a little darkening of the picture behind the digits so that the font will be more easily readable.  You can pick any color you want but match it to the backing picture so it is readable.  You don't want a yellow font on a primarily yellow background picture!

There are 37 background pictures included and you can make your own.  Anything 320x170 works.  Just remember to load them into SPIFFS then modify the BuildAndShow routine to list the names and colors to use for the fonts and whether to use the darkening grid or not.

There is a default display brightness and if you change it, it will be saved and used the next day for the same hour in which you made the change.  If you do not change anything, the display will go dark at 11pm (2300) and come back on at 10am (1000).  This was done to save the display.  The dark times are easily changed or can also be easily disabled so that the display stays on all of the time.  I have heard that these displays will wear quickly (OLED) if kept on all of the time, so I keep them dim by default and turn it off at night.  The brightness is changable via the two buttons on the T-Display.  Initially, it changes by 2 then if you hold the button longer, it changes by 4 then, later, will change to steps of 8 until you release the button.  The brightness is shown at the top of the display and that display will disappear a few seconds after you release the button.

TBD:
Make the optional darkening grid for the other two fields for when they are hard to see.
Who knows what else.  Send me suggestions.  I like to hear about new and fun stuff I can do.

THanks for downloading.  Please send any bug reports or suggestions for additions.  I don't get upset about problem reports and love enhancement requests.

Mike Morrow

Pictures will appear here tomorrow...
