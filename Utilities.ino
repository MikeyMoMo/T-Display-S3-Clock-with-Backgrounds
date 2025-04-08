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
      Serial.println(pInfo[BGPic].picName);
    }
    // The callback knows where to put the picture.
    //  This just starts the process.
    // Load BG picture only.
    JPB_RC = TJpgDec.drawFsJpg(0, 0, pInfo[BGPic].picName, LittleFS);
    if (JPB_RC != JDR_OK) Serial.println(pInfo[BGPic].picName);

    spriteTime.fillSprite(TFT_BLACK);

    if (pInfo[BGPic].tHatch) {
      for (int i = 18; i < SPR_TIME_HEIGHT; i = i + 2) {
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

    if (pInfo[BGPic].dHatch) {
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
void BuildAndShow(bool doOutline)
/*******************************************************************************************/
{
  // Show a background picture. Draw the image, top left at 0,0.  Then put in the text
  //  fields with outlining except, as below.

  // I found that there is just not enough time to service the buttons fast enough with
  //  drawing in the outlining.  So, I turn off outlining for button presses to speed it up.

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

  int x = 3, y = 5;
  if (ShowFields) {
    sprintf(chBuffer, "%02i:%02i:%02i", iHour, iMinute, iSecond);
    if (pInfo[BGPic].oColor != 0) {  // Only do this if there is an outline color defined.
      if (doOutline == DO_OUTLINE) {
        spriteTime.setTextColor(pInfo[BGPic].oColor, TFT_BLACK);  // Load up the outline color.
        // Diagonals
        spriteTime.drawString(chBuffer, x - 2, y - 2);
        spriteTime.drawString(chBuffer, x + 2, y + 2);
        spriteTime.drawString(chBuffer, x + 2, y - 2);
        spriteTime.drawString(chBuffer, x - 2, y + 2);
        // Orthoginals
        spriteTime.drawString(chBuffer, x - 2, y);
        spriteTime.drawString(chBuffer, x + 2, y);
        spriteTime.drawString(chBuffer, x, y - 2);
        spriteTime.drawString(chBuffer, x, y + 2);
      }
    }
    spriteTime.setTextColor(pInfo[BGPic].tColor, TFT_BLACK);  // Load up the outline color.
    spriteTime.drawString(chBuffer, x, y);
    spriteTime.pushToSprite(&spriteBG, 18, 52, TFT_BLACK);
  }
  // Create and draw the date sprite onto the background sprite.

  nTemp = atoi(chDayOfMonth);
  if (nTemp < 10) sprintf(chDayOfMonth, "%2d", nTemp);

  // Update the date sprite
  if (ShowFields) {
    sprintf(chBuffer, "%s  %s %s, %i",
            String(chDayofWeek), String(chMonth),
            String(chDayOfMonth), iYear);
    ofr.setDrawer(spriteDate);
    ofr.setFontSize(SPR_DATE_FONT_SIZE);

    x = 18; y = 3;
    if (pInfo[BGPic].oColor != 0) {  // Only do this if there is an outline color defined.
      if (doOutline == DO_OUTLINE) {
        //        ofr.setFontColor(pInfo[BGPic].oColor, TFT_BLACK);  // Load up the outline color.
        spriteDate.setTextColor(pInfo[BGPic].oColor, TFT_BLACK);  // Load up the outline color.
        // Diagonals
        spriteDate.drawString(chBuffer, x - 2, y - 2);
        spriteDate.drawString(chBuffer, x + 2, y + 2);
        spriteDate.drawString(chBuffer, x + 2, y - 2);
        spriteDate.drawString(chBuffer, x - 2, y + 2);
        // Orthoginals
        spriteDate.drawString(chBuffer, x - 2, y);
        spriteDate.drawString(chBuffer, x + 2, y);
        spriteDate.drawString(chBuffer, x, y - 2);
        spriteDate.drawString(chBuffer, x, y + 2);
      }
    }
    spriteDate.setTextColor(pInfo[BGPic].dColor, TFT_BLACK);  // Load up the outline color.
    spriteDate.drawString(chBuffer, x, y);
    spriteDate.pushToSprite(&spriteBG, 20, 128, TFT_BLACK);
  }

  // Read the battery voltage.

  spriteBattBL.fillSprite(TFT_BLACK);

  // Update the battery sprite.
  if (millis() > BLChangeMillis + BRIGHTNESS_SHOW_MILLIS) {
    if (showVolts) {
      uVolt = (analogRead(4) * 2 * 3.3 * 1000) / 4096;
      sprintf(chBuffer, "%.2f VDC", uVolt / 1000.);
    } else {
      chBuffer[0] = '\0';  // Clear it out.
    }
  } else {
    sprintf(chBuffer, "Brightness: %i", tftBL_Lvl);
  }
  ofr.setDrawer(spriteBattBL);
  ofr.setFontSize(SPR_BATTERY_FONT_SIZE);
  ofr.setFontColor(pInfo[BGPic].bColor, TFT_BLACK); // spriteBattBL text colors
  ofr.setCursor(0, 0);
  ofr.printf(chBuffer);

  if (ShowFields)
    spriteBattBL.pushToSprite(&spriteBG, 4, 2, TFT_BLACK);
  spriteBG.pushSprite(0, 0); spriteBG.fillSprite(TFT_BLACK);
  delay(1);
}
/*******************************************************************************************/
void doMenu()
/*******************************************************************************************/
{
  int highlight = 1;
  //  Serial.printf("%lu - In menuing.\r\n", millis());

  tft.fillScreen(TFT_BLACK);

  // Now, wait for unpress of both buttons.
  while ((digitalRead(incrPin) == 0) || (digitalRead(decrPin) == 0));
  //  {
  //    Serial.println("Waiting for both buttons to be not pressed.");
  //  }

  menuHide = millis() + MENU_HIDE_TIME;

  while (millis() < menuHide) {
    spriteMenu.fillSprite(TFT_BLACK);
    if (highlight == 1)
      spriteMenu.setTextColor(TFT_BLACK, TFT_YELLOW);
    else
      spriteMenu.setTextColor(TFT_YELLOW, TFT_BLACK);
    spriteMenu.drawString("Toggle Battery Usage", 0, 10, 4);
    spriteMenu.drawFastHLine(0, SPR_MENU_HEIGHT - 1, tft.width(), TFT_YELLOW);
    spriteMenu.pushSprite(0, 10);

    spriteMenu.fillSprite(TFT_BLACK);
    if (highlight == 2)
      spriteMenu.setTextColor(TFT_BLACK, TFT_YELLOW);
    else
      spriteMenu.setTextColor(TFT_YELLOW, TFT_BLACK);
    spriteMenu.drawString("Toggle All Fields", 0, 10, 4);
    spriteMenu.drawFastHLine(0, SPR_MENU_HEIGHT - 1, tft.width(), TFT_YELLOW);
    spriteMenu.pushSprite(0, 50);

    spriteMenu.fillSprite(TFT_BLACK);
    if (highlight == 3)
      spriteMenu.setTextColor(TFT_BLACK, TFT_YELLOW);
    else
      spriteMenu.setTextColor(TFT_YELLOW, TFT_BLACK);
    spriteMenu.drawString("Toggle Battery Field", 0, 10, 4);
    spriteMenu.drawFastHLine(0, SPR_MENU_HEIGHT - 1, tft.width(), TFT_YELLOW);
    spriteMenu.pushSprite(0, 90);

    spriteMenu.fillSprite(TFT_BLACK);
    if (highlight == 4)
      spriteMenu.setTextColor(TFT_BLACK, TFT_YELLOW);
    else
      spriteMenu.setTextColor(TFT_YELLOW, TFT_BLACK);
    spriteMenu.drawString("Return to Clock", 0, 10, 4);
    spriteMenu.drawFastHLine(0, SPR_MENU_HEIGHT - 1, tft.width(), TFT_YELLOW);
    spriteMenu.pushSprite(0, 130);

    // Select item
    if (digitalRead(decrPin) == 0) {  // Bottom button pressed.
      delay(50);
      if (digitalRead(decrPin) == 0) {  // Still pressed?
        highlight++; if (highlight > 4) highlight = 1;
        menuHide = millis() + MENU_HIDE_TIME;  // Extend auto close time.
      }
      while (digitalRead(decrPin) == 0);  // Wait for unpress to avoid multiple actions.
    }

    // Execute selected
    if (digitalRead(incrPin) == 0) {  // Bottom button pressed.
      delay(50);
      if (digitalRead(incrPin) == 0) {  // Still pressed?
        switch (highlight)
        {
          case 1:  // case 'B':
            dRead = digitalRead(15);
            if (dRead == 0) {
              digitalWrite(15, 1);
              Serial.println("Battery usage state set to full power. There is no off state.");
            } else {
              digitalWrite(15, 0);
              Serial.println("Battery usage state set to partial power. There is no off state.");
            }
            while ((digitalRead(incrPin) == 0) || (digitalRead(decrPin) == 0));
            return;
            break;

          case 2:  // case 'F':
            ShowFields = !ShowFields;
            Serial.printf("Fields will%s be shown.\r\n", ShowFields ? "" : " not");
            while ((digitalRead(incrPin) == 0) || (digitalRead(decrPin) == 0));
            return;
            break;

          case 3:  // case 'V':
            showVolts = !showVolts;
            if (showVolts)
              Serial.println("Battery voltage will be shown.");
            else
              Serial.println("Battery voltage will not be shown.");
            showInputOptions();
            while ((digitalRead(incrPin) == 0) || (digitalRead(decrPin) == 0));
            return;
            break;

          case 4:  // Return to clock
            while ((digitalRead(incrPin) == 0) || (digitalRead(decrPin) == 0));
            return;
        }
      }
      menuHide = millis() + MENU_HIDE_TIME;  // Extend auto close time.
    }
  }
}
/*******************************************************************************************/
void CheckButtons()
/*******************************************************************************************/
{
  int pressLength = 0;

  if ((digitalRead(incrPin) == 0) && (digitalRead(decrPin) == 0)) {
    //    Serial.printf("%lu - 1 Both pressed, do menuing.\r\n", millis());
    doMenu();
    return;
  }

  // Allow the user to adjust backlight brightness.
  while ((digitalRead(incrPin) == 0) &&
         (tftBL_Lvl <= MAX_BRIGHTNESS))
  {

    if (digitalRead(decrPin) == 0) {
      //      Serial.printf("%lu - 2 Both pressed, do menuing.\r\n", millis());
      return;
    }

    // Increase.
    pressLength++;
    if (pressLength > 10) BLchange = 8;
    else if (pressLength > 5) BLchange = 4;
    else BLchange = 2;
    tftBL_Lvl += BLchange;

    if (tftBL_Lvl > 9)
      tftBL_Lvl = MAX_BRIGHTNESS;

    ledcWrite(TFT_BL, tftBL_Lvl);
    //    Serial.printf("+tft brightness now %i\r\n", tftBL_Lvl);
    BLChangeMillis = millis();
    BuildAndShow(NO_OUTLINE);
    delay(100);
  }
  while ((digitalRead(decrPin)) == 0 &&
         (tftBL_Lvl >= MIN_BRIGHTNESS))
  {
    if (digitalRead(incrPin) == 0) {
      //      Serial.printf("%lu - 3 Both pressed, do menuing.\r\n", millis());
      doMenu();
      return;
    }

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
    BuildAndShow(NO_OUTLINE);
    delay(100);
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
    //  time(&now);
    //  if (now > 100000) {
    // It is now taking more than 1/2 second to update the screen so I will fudge
    //  one second to try to make up for it.
    // now++;
    // localtime_r(&now, &timeinfo);

    strftime(chDayofWeek, sizeof(chDayofWeek), "%A", &timeinfo);
    strftime(chDayOfMonth, sizeof(chDayOfMonth), "%d", &timeinfo);
    strftime(chMonth, sizeof(chMonth), "%B", &timeinfo);
    // Get the big 6 in integer format, too.
    iDOM    = timeinfo.tm_mday;
    iDOW    = timeinfo.tm_wday;   // Watch out: days since Sunday (0-6)
    iMonth  = timeinfo.tm_mon;    // Watch out: months since January (0-11)
    iYear   = timeinfo.tm_year + 1900;
    iHour   = timeinfo.tm_hour;
    iMinute = timeinfo.tm_min;
    iSecond = timeinfo.tm_sec;
  } else {  // No joy getting time.  See what can be done.
    Serial.println("Time not available.");
    delay(5000);  // A short rest then restart sNTP.
    Serial.println("Restarting sNTP service.");
    sntp_restart();
    delay(5000);  // A short rest then retry.
    if (!getLocalTime(&timeinfo)) {  // Still no joy.  Wait then reboot.
      delay(30000);
      if (!getLocalTime(&timeinfo)) ESP.restart();  // Still bad?  Reboot!
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
  //  Serial.printf("Hourdance derived brightness level for hour %i of %i\r\n",
  //                iHour, tftBL_Lvl);
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

  if (WakeupHour > SleepHour)
    WakeUp = (iHour >= WakeupHour || iHour <= SleepHour);
  else
    WakeUp = (iHour >= WakeupHour && iHour <= SleepHour);

  if (!WakeUp) tftBL_Lvl = 0;
  if (tftBL_Lvl == 1000) tftBL_Lvl = defaultBright;
  ledcWrite(TFT_BL, tftBL_Lvl);  // Activate whatever was decided on.
  Serial.printf("%02i:%02i:%02i - Brightness level for hour %i set to %i\r\n",
                iHour, iMinute, iSecond, iHour, tftBL_Lvl);
}
/*******************************************************************************************/
void SaveOptions()
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

    preferences.begin("UserPrefs", RW_MODE);
    bool bTemp = preferences.getBool("showVolts", false);
    if (bTemp != showVolts) {
      preferences.putBool("showVolts", showVolts);
      Serial.printf("%02i:%02i:%02i - Saved new showVolts setting: %s.\r\n",
                    iHour, iMinute, iSecond, showVolts ? "true" : "false");
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
  while (iYear < 2025) {
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
/*******************************************************************************************/
void showInputOptions()
/*******************************************************************************************/
{
  Serial.println("\r\nEnter B or b to toggle battery usage state (full or partial).");
  Serial.println("Enter F or f to toggle showing time/date/battery fields.");
  Serial.println("Enter P or p for the name of the current BG Pic.");
  Serial.println("Enter V or v to toggle battery voltage display on and off.");
  Serial.println("Enter ? for this list.  Upper or Lower case OK.\r\n");
}
