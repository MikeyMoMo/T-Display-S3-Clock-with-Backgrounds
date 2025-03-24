/*******************************************************************************************/
void SetPic_Colors()
/*******************************************************************************************/
{
  // The input parm order is really messed up.  I was not thinking when I added the first
  //  bool but, later, when I added other one, I should have done the right thing but I
  //  just appended it on the end.  Maybe, someday, I will fix it.  LOTS of busywork to do!

  // Note filenames must be preceded with "/"

  // Just if you want to see the size of the picture.
  //  TJpgDec.getFsJpgSize(&w, &h, "/MistyValley.jpg");
  //  Serial.print("Width = "); Serial.print(w); Serial.print(", height = ");
  //  Serial.println(h);

//  BGPic = 14;  // Force a specific BG pic for testing something.

  if (BGPic == 0) {
    if (prev_BGPic != BGPic)
      Serial.printf("%02i:%02i:%02i Showing Red Graphic\r\n", iHour, iMinute, iSecond);
    drawRedGraphic();
  }
  else if (BGPic == 1) {
    if (prev_BGPic != BGPic)
      Serial.printf("%02i:%02i:%02i Showing Blue Graphic\r\n", iHour, iMinute, iSecond);
    drawBlueGraphic();
  }
  else if (BGPic == 2) {
    if (prev_BGPic != BGPic)
      Serial.printf("%02i:%02i:%02i Showing Green Graphic\r\n", iHour, iMinute, iSecond);
    drawGreenGraphic();
  }
  else {
    if (prev_BGPic != BGPic) {
      Serial.printf("%02i:%02i:%02i Loading: ", iHour, iMinute, iSecond);
      Serial.println(PixInfo[BGPic].picName);
    }
    // The callback knows where to put the picture.
    //  This just starts the process.
    // Load BG picture only.
    JPB_RC = TJpgDec.drawFsJpg(0, 0, PixInfo[BGPic].picName, LittleFS);
    if (JPB_RC != JDR_OK) Serial.println(PixInfo[BGPic].picName);

    spriteTime.fillSprite(TFT_BLACK);

    if (PixInfo[BGPic].tHatch) {
      for (int i = 20; i < SPR_TIME_HEIGHT; i = i + 2) {
        // Draw almost black lines across the time digits area.
        // I tried (1, 1, 1) but it seems to have considered it still to
        //  be hidden and drew nothing.
        spriteTime.drawFastHLine(0, i, SPR_TIME_WIDTH - 23, RGB565(5, 5, 5));
      }
      for (int i = 0; i < tft.width(); i = i + 2) {
        // Cut holes in the almost black lines to make it semi-transparent.
        spriteTime.drawFastVLine(i, 18, SPR_TIME_HEIGHT - 19, TFT_BLACK);
      }
    }

    spriteDate.fillSprite(TFT_BLACK);

    if (PixInfo[BGPic].dHatch) {
      for (int i = 7; i < SPR_DATE_HEIGHT - 8; i = i + 2) {
        // Draw almost black lines across the time digits area.
        // I tried (1, 1, 1) but it seems to have considered it still to
        //  be hidden and drew nothing.
        spriteDate.drawFastHLine(30, i, tft.width() - 55, RGB565(5, 5, 5));
      }
      for (int i = 0; i < tft.width(); i = i + 2) {
        // Cut holes in the almost black lines to make it semi-transparent.
        spriteDate.drawFastVLine(i, 0, SPR_DATE_HEIGHT - 7, TFT_BLACK);
      }
    }
  }
  prev_BGPic = BGPic;
}
/************** ****************************************************************************/
void BuildAndShow()
/*******************************************************************************************/
{
  // Show a background picture. Draw the image, top left at 0,0

  //  BGPic = 66;  // Testing hatching

  SetPic_Colors();  // Put up the picture and set the text colors.

  /* I have had a lot of trouble with some of the pictures I made to be
      used as backgrounds because of the colors.  For some of them, no
      font color I could set would look right.  So, the cure I came up
      with it to make a mask behind the time digits and in front of the
      background picture so it would darken the area just under the time
      and make the digits more readable. I fill the sprite with black
      (the invisible color) and then draw brown lines ever 2 pixels across
      the sprite.  I then draw black lines ever 4 pixels, vertically.  This
      makes a grid of brown and that darkens it.  I like 2 pixel separation
      verticlly, too, but that does not darken the area enough so I had to
      leave more brown in there.  Maybe I can try an almost black and
      a spacing of 2 again to see.  The spacing of 4 leaves a visible grid
      in front of the background picture.  Well, I tried it.  Seems to
      work.  Time for bed!
  */

  ofr.setDrawer(spriteTime);
  ofr.setFontSize(SPR_TIME_FONT_SIZE);
  ofr.setFontColor(PixInfo[BGPic].tColor, TFT_BLACK);  // spriteTime text colors
  ofr.setCursor(0, 5);
  sprintf(chBuffer, "%02i:%02i:%02i", iHour, iMinute, iSecond);
  ofr.printf(chBuffer);
  spriteTime.pushToSprite(&spriteBG, 20, 38, TFT_BLACK);

  // Create and draw the date sprite onto the background sprite.
  // Leading zero supression for the day of monthmonth.

  nTemp = atoi(chDayOfMonth);
  if (nTemp < 10) sprintf(chDayOfMonth, "%2d", nTemp);

  // Update the date sprite
  sprintf(chBuffer, "%s  %s %s, %i",
          String(chDayofWeek), String(chMonth),
          String(chDayOfMonth), iYear);
  ofr.setDrawer(spriteDate);
  ofr.setFontSize(SPR_DATE_FONT_SIZE);
  ofr.setFontColor(PixInfo[BGPic].dColor, TFT_BLACK);  // spriteTime text colors
  ofr.setCursor(tft.width() / 2 + 2, 0);
  ofr.cprintf(chBuffer);
  spriteDate.pushToSprite(&spriteBG, 0, 128, TFT_BLACK);

  // Read the battery voltage.

  spriteBattBL.fillSprite(TFT_BLACK);

  // Update the battery sprite.
  if (millis() > BLChangeMillis + BRIGHTNESS_SHOW_MILLIS) {
    uVolt = (analogRead(4) * 2 * 3.3 * 1000) / 4096;
    sprintf(chBuffer, "%.2f VDC", uVolt / 1000.);
  } else {
    sprintf(chBuffer, "Brightness: %i", tftBL_Lvl);
  }
  ofr.setDrawer(spriteBattBL);
  ofr.setFontSize(SPR_BATTERY_FONT_SIZE);
  ofr.setFontColor(PixInfo[BGPic].bColor, TFT_BLACK); // spriteBattBL text colors
  ofr.setCursor(0, 0);
  ofr.printf(chBuffer);

  spriteBattBL.pushToSprite(&spriteBG, 4, 2, TFT_BLACK);
  spriteBG.pushSprite(0, 0); spriteBG.fillSprite(TFT_BLACK);
  delay(1);
}
/*******************************************************************************************/
void CheckButtons()
/*******************************************************************************************/
{
  int pressLength = 0;
  // Allow the user to adjust backlight brightness.
  while ((digitalRead(incrPin) == 0) &&
         (tftBL_Lvl <= MAX_BRIGHTNESS))
  {
    // Increase.
    pressLength++;
    if (pressLength > 10) BLchange = 8;
    else if (pressLength > 5) BLchange = 4;
    else BLchange = 2;
    tftBL_Lvl += BLchange;

    if (tftBL_Lvl > MAX_BRIGHTNESS)
      tftBL_Lvl = MAX_BRIGHTNESS;

    ledcWrite(TFT_BL, tftBL_Lvl);
    //    Serial.printf("+tft brightness now %i\r\n", tftBL_Lvl);
    BLChangeMillis = millis();
    BuildAndShow();
    delay(150);
  }
  while ((digitalRead(decrPin)) == 0 &&
         (tftBL_Lvl >= MIN_BRIGHTNESS))
  {
    // Decrease.
    pressLength++;
    if (pressLength > 10) BLchange = 8;
    else if (pressLength > 5) BLchange = 4;
    else BLchange = 2;
    tftBL_Lvl -= BLchange;

    if (tftBL_Lvl < MIN_BRIGHTNESS)
      tftBL_Lvl = MIN_BRIGHTNESS;

    ledcWrite(TFT_BL, tftBL_Lvl);
    //    Serial.printf("-tft brightness now %i\r\n", tftBL_Lvl);
    BLChangeMillis = millis();
    BuildAndShow();
    delay(150);
  }
}
/*******************************************************************************************/
void GetCurrentTime()
/*******************************************************************************************/
{
  // Check for time and date availability.
  if (getLocalTime(&timeinfo))
  {
    // Time and date available, obtain hours, minutes and seconds.
    // Then obtain day of week, day of month, month and year.
    strftime(chDayofWeek, sizeof(chDayofWeek), "%A", &timeinfo);
    strftime(chDayOfMonth, sizeof(chDayOfMonth), "%d", &timeinfo);
    strftime(chMonth, sizeof(chMonth), "%B", &timeinfo);
    // Get the big 3 in integer format, too.
    iDOM    = timeinfo.tm_mday;
    iDOW    = timeinfo.tm_wday;   // Watch out: days since Sunday (0-6)
    iMonth  = timeinfo.tm_mon;    // Watch out: months since January (0-11)
    iYear   = timeinfo.tm_year + 1900;
    iHour   = timeinfo.tm_hour;
    iMinute = timeinfo.tm_min;
    iSecond = timeinfo.tm_sec;
  } else {  // No joy getting time.  See what can be done.
    Serial.println("Time not available.");
    delay(5000);  // A short rest then retry.
    sntp_restart();
    delay(5000);  // A short rest then retry.
    if (!getLocalTime(&timeinfo)) {  // Still no joy.  Wait then reboot.
      delay(30000);
      ESP.restart();
    }
  }
}
/*******************************************************************************************/
void HourDance()
/*******************************************************************************************/
{
  Serial.printf("It is now %02i:00\r\n", iHour);

  // Do HourDance after updating the display to xx:00:00
  for (int i = 0; i < 4; i++) {
    tft.invertDisplay(false); delay(200);
    tft.invertDisplay(true); delay(200);
  }
  setHourBrightness();
  Serial.printf("Hourdance derived brightness level for hour %i of %i\r\n",
                iHour, tftBL_Lvl);
}
/*******************************************************************************************/
void setHourBrightness()
/*******************************************************************************************/
{
  // For normal operation, use this one.
  //  if (prev_BL_Hour == iHour) return;
  //  prev_BL_Hour = iHour;
  preferences.begin("Hourlys", RO_MODE);
  // To clear out all of the hourly readings, use the following two instead.
  //  preferences.begin("Hourlys", RW_MODE);
  //  preferences.clear();

  // If this hour has not been set, 1000 will be returned.  If it is
  //  and it is late, turn off the display.  It can be turned back on
  //  if anyone is awake and want to set it to be on for the hour.
  sprintf(chHour, "%d", iHour);
  tftBL_Lvl = preferences.getInt(chHour, 1000);  // Never been set?
  Serial.printf("Read brightness level for hour %i of %i\r\n",
                iHour, tftBL_Lvl);
  preferences.end();
  if ((iHour >= 23 || iHour < 10) && tftBL_Lvl == 1000)
    tftBL_Lvl = 0;
  if (tftBL_Lvl == 1000) tftBL_Lvl = defaultBright;
  ledcWrite(TFT_BL, tftBL_Lvl);  // Activate whatever was decided on.
  Serial.printf("Brightness level for hour %i set to %i\r\n", iHour, tftBL_Lvl);

}
/*******************************************************************************************/
void SaveBrightness()
/*******************************************************************************************/
{
  // On the modulo 10 minute plus 10 seconds, see if saving the brightness
  //  value is needed.  Also on the second to last second of the hour.
  if ((iMinute > 0 && iMinute % 10 == 0 && iSecond == 0) ||
      (iMinute == 59 && iSecond == 58)) {
    preferences.begin("Hourlys", RW_MODE);
    sprintf(chHour, "%d", iHour);
    nTemp = preferences.getInt(chHour, defaultBright);
    if (nTemp != tftBL_Lvl) {
      preferences.putInt(chHour, tftBL_Lvl);
      Serial.printf("%02i:%02i:%02i - Saved BL level for hour %2i: %i\r\n",
                    iHour, iMinute, iSecond, iHour, tftBL_Lvl);
    }
    preferences.end();
  }
}
/*******************************************************************************************/
void initTime()
/*******************************************************************************************/
{
  sntp_set_sync_interval(86405432);  // 1 day in ms plus a little.
  sntp_set_time_sync_notification_cb(timeSyncCallback);
  sntp_set_sync_mode(SNTP_SYNC_MODE_SMOOTH);
#if defined CONFIG_FOR_JOE
  configTzTime("PST8PDT,M3.2.0,M11.1.0", "time.nist.gov");
#else
  configTzTime("PHT-8", "time.nist.gov");
#endif
  Serial.print("Waiting for correct time...");

  strftime(chBuffer, sizeof(chBuffer), "%Y", localtime(&UTC));
  iYear = atoi(chBuffer);
  int iLooper = 0;
  while (iYear < 2024) {
    Serial.print(".");
    time(&UTC);
    strftime (chBuffer, 100, "%Y", localtime(&UTC));
    iYear = atoi(chBuffer);
    if (iLooper++ > 30) {
      Serial.println("\r\nCannot get time set. Rebooting.");
      ESP.restart();
    }
    delay(2000);
  }
  Serial.println();
  getLocalTime(&timeinfo);
  iMonth = timeinfo.tm_mon + 1;
  iDOM   = timeinfo.tm_mday;
  iYear  = timeinfo.tm_year + 1900;
  iHour  = timeinfo.tm_hour;
  Serial.println(localtime(&UTC), "Local %a %m/%d/%Y %T %Z");
}
/*******************************************************************************************/
void timeSyncCallback(struct timeval * tv)
/*******************************************************************************************/
{
  //  struct timeval {  // Instantiated as "*tv"
  //    Number of whole seconds of elapsed time.
  //   time_t      tv_sec;
  //    Number of microseconds of rest of elapsed time minus tv_sec.
  //     Always less than one million.
  //   long int    tv_usec;
  //  Serial.print("\n** > Time Sync Received at ");
  //  Serial.println(ctime(&tv->tv_sec));
  TS_Epoch = tv->tv_sec;
}
/*******************************************************************************************/
void drawRedGraphic()
/*******************************************************************************************/
{
  // These four graphics statements draw a series of rectangles
  //  (well, sorta) from the outside to the middle getting darker red
  //  with each line.  It is actually not a rectangle but probably
  //  should be.  Will check it out some day...  It puts the time in
  //  front of a darker area.  I like the effect.  Do you?
  // The difference is that with the four statements, I can set a
  //  different color change profile for the horizontal and vertical
  //  line segments. With a rectangle call, they must all be the same.
  //  So they don't match, really.  I will probably go back to the
  //  fours statements.  They don't take long to execute and I have
  //  better control of the color fading.
  spriteTime.fillSprite(TFT_BLACK);
  for (int i = 0; i <= tft.height() / 2; i++) {
    spriteBG.drawFastHLine(i, i, tft.width() - i * 2,
                           RGB565(255 - i * 2, 0, 0));
    spriteBG.drawFastHLine(i, tft.height() - i, tft.width() - i * 2,
                           RGB565(255 - i * 2, 0, 0));
    spriteBG.drawFastVLine(i, i, tft.height() - i * 2,
                           RGB565(255 - i * 2, 0, 0));
    spriteBG.drawFastVLine(tft.width() - i, i,
                           1 + (tft.height() - i * 2),
                           RGB565(255 - i * 2, 0, 0));
    spriteBG.drawRect(i, i, tft.width() - i * 2, tft.height() - i * 2,
                      RGB565(255 - int(i * 2.5), 0, 0));
  }
  //  ofr.setFontColor(TFT_GREENYELLOW, TFT_BLACK);
}
/*******************************************************************************************/
void drawBlueGraphic()
/*******************************************************************************************/
{
  // These four graphics statements draw a series of rectangles
  //  (well, sorta) from the outside to the middle getting darker red
  //  with each line.  It is actually not a rectangle but probably
  //  should be.  Will check it out some day...  It puts the time in
  //  front of a darker area.  I like the effect.  Do you?
  // The difference is that with the four statements, I can set a
  //  different color change profile for the horizontal and vertical
  //  line segments. With a rectangle call, they must all be the same.
  //  So they don't match, really.  I will probably go back to the
  //  fours statements.  They don't take long to execute and I have
  //  better control of the color fading.
  spriteTime.fillSprite(TFT_BLACK);
  for (int i = 0; i <= tft.height() / 2; i++) {
    spriteBG.drawFastHLine(i, i, tft.width() - i * 2,
                           RGB565(0, 0, 255 - i * 2));
    spriteBG.drawFastHLine(i, tft.height() - i, tft.width() - i * 2,
                           RGB565(0, 0, 255 - i * 2));
    spriteBG.drawFastVLine(i, i, tft.height() - i * 2,
                           RGB565(0, 0, 255 - i * 2));
    spriteBG.drawFastVLine(tft.width() - i, i,
                           1 + (tft.height() - i * 2),
                           RGB565(0, 0, 255 - i * 2));
    spriteBG.drawRect(i, i, tft.width() - i * 2, tft.height() - i * 2,
                      RGB565(0, 0, 255 - int(i * 2.5)));
  }
  //  ofr.setFontColor(TFT_GREENYELLOW, TFT_BLACK);
}
/*******************************************************************************************/
void drawGreenGraphic()
/*******************************************************************************************/
{
  // These four graphics statements draw a series of rectangles
  //  (well, sorta) from the outside to the middle getting darker red
  //  with each line.  It is actually not a rectangle but probably
  //  should be.  Will check it out some day...  It puts the time in
  //  front of a darker area.  I like the effect.  Do you?
  // The difference is that with the four statements, I can set a
  //  different color change profile for the horizontal and vertical
  //  line segments. With a rectangle call, they must all be the same.
  //  So they don't match, really.  I will probably go back to the
  //  fours statements.  They don't take long to execute and I have
  //  better control of the color fading.
  spriteTime.fillSprite(TFT_BLACK);
  for (int i = 0; i <= tft.height() / 2; i++) {
    spriteBG.drawFastHLine(i, i, tft.width() - i * 2,
                           RGB565(0, 255 - i * 2, 0));
    spriteBG.drawFastHLine(i, tft.height() - i, tft.width() - i * 2,
                           RGB565(0, 255 - i * 2, 0));
    spriteBG.drawFastVLine(i, i, tft.height() - i * 2,
                           RGB565(0, 255 - i * 2, 0));
    spriteBG.drawFastVLine(tft.width() - i, i,
                           1 + (tft.height() - i * 2),
                           RGB565(0, 255 - i * 2, 0));
    spriteBG.drawRect(i, i, tft.width() - i * 2, tft.height() - i * 2,
                      RGB565(0, 255 - int(i * 2.5), 0));
  }
  //  ofr.setFontColor(TFT_RED, TFT_BLACK);
}
