/*******************************************************************************************/
JRESULT SetPic_Colors()
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
      Serial.printf("%02i:%02i:%02i Showing #000: Red Graphic\r\n",
                    iHour, iMinute, iSecond);
    drawRedGraphic();
  }
  else if (BGPic == 1) {
    if (prev_BGPic != BGPic)
      Serial.printf("%02i:%02i:%02i Showing #001: Blue Graphic\r\n",
                    iHour, iMinute, iSecond);
    drawBlueGraphic();
  }
  else if (BGPic == 2) {
    if (prev_BGPic != BGPic)
      Serial.printf("%02i:%02i:%02i Showing #002: Green Graphic\r\n",
                    iHour, iMinute, iSecond);
    drawGreenGraphic();
  }
  else {
    if (prev_BGPic != BGPic) {
      Serial.printf("%02i:%02i:%02i Loading ", iHour, iMinute, iSecond);
      Serial.flush();
      printPicName(BGPic, pInfo[BGPic].picName);
      Serial.flush();
    }
    // The callback knows where to put the picture.  This just starts the process.
    // Load BG picture only.
    JPB_RC = TJpgDec.drawFsJpg(0, 0, pInfo[BGPic].picName, LittleFS);
    if (JPB_RC != JDR_OK) {
      Serial.println("Picture load failed for ");
      Serial.println(pInfo[BGPic].picName);
      iTemp = int(random(randSelections));
      // If the same, pick a new number.
      while (iTemp == BGPic) iTemp = int(random(randSelections));
      BGPic = iTemp;
      return JPB_RC;  // Stop the insanity... NOW!
    }
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
  return JDR_OK;
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

  JPB_RC = JDR_INTR;  // Setup the condition to force calling SetPic_Colors.
  while (JPB_RC != JDR_OK)
    JPB_RC = SetPic_Colors(); // Put up the picture and set the text colors.

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

  // Read the Battery voltage.

  if (ShowFields) {
    spriteBattBL.fillSprite(TFT_BLACK);

    // Update the battery sprite.
    if (millis() > BLChangeMillis + BRIGHTNESS_SHOW_MILLIS) {
      if (showVolts) {
        uVolt = (analogRead(4) * 2 * 3.3 * 1000) / 4096;
        // Move existing ones left by 1
        int iVoltAvg = 0;
        for (int i = 0; i < VOLT_AVG_CT - 1; i++) {
          iVoltHist[i] = iVoltHist[i + 1];
          iVoltAvg += iVoltHist[i];
        }
        iVoltHist[VOLT_AVG_CT - 1] = uVolt; // Remember current sample
        iVoltAvg += uVolt;  // Add current sample
        voltSamples++;      // Count this sample
        if (voltSamples >= VOLT_AVG_CT) voltSamples = VOLT_AVG_CT;
        iVoltAvg /= voltSamples;
        // Serial.printf("Voltage total %i, Samples %i\r\n", iVoltAvg, voltSamples);
        uVolt = iVoltAvg;
        sprintf(chBuffer, "%.2f VDC", uVolt / 1000.);
      } else {
        chBuffer[0] = '\0';  // Clear it out.
      }
    } else {
      sprintf(chBuffer, "Brightness: %i", tftBL_Lvl);
    }

    // Update the Battery sprite

    x = 5; y = 3;
    if (pInfo[BGPic].obColor != 0) {  // Only do this if there is an outline color defined.
      // First, do the outlining.
      if (doOutline == DO_OUTLINE) {
        // Load up the outline color.
        spriteBattBL.setTextColor(pInfo[BGPic].obColor, TFT_BLACK);
        // Diagonals
        spriteBattBL.drawString(chBuffer, x - 2, y - 2);
        spriteBattBL.drawString(chBuffer, x + 2, y + 2);
        spriteBattBL.drawString(chBuffer, x + 2, y - 2);
        spriteBattBL.drawString(chBuffer, x - 2, y + 2);
        // Orthoginals
        spriteBattBL.drawString(chBuffer, x - 2, y);
        spriteBattBL.drawString(chBuffer, x + 2, y);
        spriteBattBL.drawString(chBuffer, x, y - 2);
        spriteBattBL.drawString(chBuffer, x, y + 2);
      }
    }
    spriteBattBL.setTextColor(pInfo[BGPic].bColor, TFT_BLACK); // spriteBattBL text colors
    // Now, put in the actual, readable text for the battery voltage.
    spriteBattBL.drawString(chBuffer, x, y);
    spriteBattBL.pushToSprite(&spriteBG, 0, 0, TFT_BLACK);
  }

  // Update the Time sprite

  int x = 3, y = 5;
  if (ShowFields) {
    sprintf(chBuffer, "%02i:%02i:%02i", iHour, iMinute, iSecond);
    if (pInfo[BGPic].otColor != 0) {  // Only do this if there is an outline color defined.
      // First, do the outlining.
      if (doOutline == DO_OUTLINE) {
        // Load up the outline color.
        spriteTime.setTextColor(pInfo[BGPic].otColor, TFT_BLACK);
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
    // Now, put in the actual, readable text for the time.
    spriteTime.drawString(chBuffer, x, y);
    spriteTime.pushToSprite(&spriteBG, 18, 52, TFT_BLACK);
  }

  // Create and draw the Date sprite onto the background sprite.

  nTemp = atoi(chDayOfMonth);
  if (nTemp < 10) sprintf(chDayOfMonth, "%2d", nTemp);

  // Update the Date sprite

  if (ShowFields) {
    sprintf(chBuffer, "%s  %s %s, %i",
            String(chDayofWeek), String(chMonth),
            String(chDayOfMonth), iYear);

    x = 5; y = 3;
    if (pInfo[BGPic].odColor != 0) {  // Only do this if there is an outline color defined.
      // First, do the outlining.
      if (doOutline == DO_OUTLINE) {
        // Load up the outline color.
        spriteDate.setTextColor(pInfo[BGPic].odColor, TFT_BLACK);
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
    // Now, put in the actual, readable text for the time.
    spriteDate.drawString(chBuffer, x, y);
    spriteDate.pushToSprite(&spriteBG, 14, 128, TFT_BLACK);
  }

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
              Serial.println("Battery usage state set to full power. "
                             "There is no off state.");
            } else {
              digitalWrite(15, 0);
              Serial.println("Battery usage state set to partial power. "
                             "There is no off state.");
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
  int prevBL = tftBL_Lvl;

  if ((digitalRead(incrPin) == 0) && (digitalRead(decrPin) == 0)) {
    //    Serial.printf("%lu - 1 Both pressed, do menuing.\r\n", millis());
    doMenu();
    return;
  }

  // Allow the user to adjust backlight brightness.
  while ((digitalRead(incrPin) == 0) &&
         (tftBL_Lvl <= MAX_BRIGHTNESS))
  {
    delay(50);
    if (digitalRead(decrPin) == 0) {
      doMenu();
      return;
    }

    // Increase.
    pressLength++;
    if (pressLength > 10) BLchange = 8;
    else if (pressLength > 5) BLchange = 4;
    else BLchange = 2;
    tftBL_Lvl += BLchange;
    if (prevBL == 0) {
      tft.writecommand(ST7789_DISPON);  // Turn on display hardware.
      prevBL = tftBL_Lvl;
    }
    if (tftBL_Lvl > MAX_BRIGHTNESS)
      tftBL_Lvl = MAX_BRIGHTNESS;

    ledcWrite(TFT_BL, tftBL_Lvl);
    //    Serial.printf("+tft brightness now %i\r\n", tftBL_Lvl);
    BLChangeMillis = millis();
    BuildAndShow(NO_OUTLINE);
    delay(50);
  }
  while ((digitalRead(decrPin)) == 0 &&
         (tftBL_Lvl >= MIN_BRIGHTNESS))
  {
    delay(50);
    if (digitalRead(incrPin) == 0) {
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
    delay(50);
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
  if ((iDOW == 0) && (iHour == 4) && (iMinute == 2) && (iSecond == 10))
    ESP.restart();
}
/*******************************************************************************************/
void HourDance()
/*******************************************************************************************/
{
  //  Serial.printf("It is now %02i:00\r\n", iHour);

  // Do HourDance after updating the display to xx:00:00
  for (int i = 0; i < 2; i++) {
    tft.invertDisplay(false); delay(200);
    tft.invertDisplay(true); delay(200);
  }
}
/*******************************************************************************************/
void setHourBrightness()
/*******************************************************************************************/
{
  preferences.begin("Hourlys", RO_MODE);

  // If this hour has not been set, 1000 will be returned.  If it is
  //  and it is late, turn off the display.  It can be turned back on
  //  if anyone is awake and want to set it to be on for the hour.
  sprintf(chHour, "%d", iHour);
  tftBL_Lvl = preferences.getInt(chHour, 1000);  // Never been set?
  Serial.printf("%02i:%02i:%02i - Read brightness level for hour %i of %i\r\n",
                iHour, iMinute, iSecond, iHour, tftBL_Lvl);
  preferences.end();

  if (WakeupHour > SleepHour)
    WakeUp = (iHour >= WakeupHour || iHour <= SleepHour);
  else
    WakeUp = (iHour >= WakeupHour && iHour <= SleepHour);

  // Serial.printf("tftBL_Lvl now set to %i\r\n", tftBL_Lvl);

  if (!WakeUp) tftBL_Lvl = 0;
  if (tftBL_Lvl > 500) tftBL_Lvl = defaultBright;  // == 1000 is not working.  Why?

  ledcWrite(TFT_BL, tftBL_Lvl);  // Activate whatever was decided on.
  Serial.printf("%02i:%02i:%02i - Brightness level for hour %i set to %i\r\n",
                iHour, iMinute, iSecond, iHour, tftBL_Lvl);
}
/*******************************************************************************************/
void SaveOptions()
/*******************************************************************************************/
{
  // On the modulo 10 minute, see if saving the brightness value is needed.
  // Also on the second to last second of the hour.
  // Since this was an evolution rather than a design, it turns out that the
  //  brightness during dark time gets written to the Hourlys preferences values
  //  but the Hourlys during display on time do not get written to the Hourlys
  //  preferences entries.  It only happens the first time so not a big deal but if
  //  you type H into the Serial Monitor, you will see how it looks.  Odd, yes, but
  //  totally workable.
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
  sntp_set_sync_interval(21601358);  // Get updated time every 6 hours.
  //  sntp_set_sync_interval(86405432);  // 1 day in ms plus a little.
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
  Serial.println(localtime(&UTC), "Local time/date %A %m/%d/%Y %T %Z");
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
}
/*******************************************************************************************/
void printVers()
/*******************************************************************************************/
{
  int      lastDot, lastV;
  String   sTemp;

  //  Serial.println(__FILENAME__);  // Same as __FILE__
  sTemp = String(__FILE__);
  // Get rid of the trailing .ino tab name. In this case, "\Utilities.ino"
  sTemp = sTemp.substring(0, sTemp.lastIndexOf("\\"));
  Serial.print("Running from: "); Serial.println(sTemp);

  sTemp = String(__FILE__);  // Start again for the version number.
  lastDot = sTemp.lastIndexOf(".");
  if (lastDot > -1) {  // Found a dot.  Thank goodness!
    lastV = sTemp.lastIndexOf("v");  // Find start of version number
    if (lastV > -1) {  // Oh, good, found version number, too
      sVer = sTemp.substring(lastV + 1, lastDot); // Pick up version number
      lastV = sVer.lastIndexOf("\\");
      if (lastV > -1) sVer = sVer.substring(0, lastV);
    } else {
      sVer = "0.00";  // Unknown version.
    }
  } else {
    sVer = "n/a";  // Something badly wrong here!
  }
  Serial.print("Version " + sVer + ", ");
  Serial.printf("Compiled on %s at %s.\r\n", __DATE__, __TIME__);
}
/*******************************************************************************************/
void showInputOptions()
/*******************************************************************************************/
{
  Serial.println("Enter ? to see the full list of options.");
}
/*******************************************************************************************/
void showInputOptionsFull()
/*******************************************************************************************/
{
  Serial.println("\r\nEnter # to to start number entry to select a specific picture.");
  Serial.println("Enter 0-9 to finish number entry to select a specific picture.");
  Serial.println("Enter + (testing) to step to the next picture by number.");
  Serial.println("Enter - (testing) to step to the previous picture by number.");
  Serial.println("Enter B to toggle Battery usage state (full or partial).");
  Serial.println("Enter F to toggle showing time/date/battery Fields.");
  Serial.println("Enter H (testing) to see all Hourly brightness values on the Monitor.");
  Serial.println("Enter I (testing) to Invert all colors on the display.");
  Serial.println("Enter L to List all of the pictures and their number.");
  Serial.println("Enter P for the name of the current BG Picture.");
  Serial.println("Enter R (testing) to change to a new Random picture.");
  Serial.println("Enter V to toggle battery Voltage display on and off.");
  Serial.println("Enter ? for this list.  Upper or Lower case OK.");
  Serial.println("Enter CR or LF to finish picture number entry or execute your selection.");
  Serial.println("If you make an unknown entry, this list is printed on the monitor.\r\n");
}
/*******************************************************************************************/
void HandleSerialInput()
/*******************************************************************************************/
{
  char input = Serial.read();  // Read one character from the serial input
  int i, iHTemp;

  input = toupper(input); // Convert the character to uppercase
  if (input != '\r' && input != '\n')
    Serial.printf("User input %c\r\n", input);  // Show user input

  // In use:
  //     0-9 to finish number entry to select a specific picture.");
  //     + (testing) to step to the next picture by number.");
  //     - (testing) to step to the previous picture by number.");
  //     B to toggle Battery usage state (full or partial).");
  //     F to toggle showing time/date/battery Fields.");
  //     H (testing) to see all Hourly brightness values on the Monitor.");
  //     I (testing) to Invert all colors on the display.");
  //     L to List all of the pictures and their number.");
  //     P for the name of the current BG Picture.");
  //     R (testing) to change to a new Random picture.");
  //     V to toggle battery Voltage display on and off.");
  //     ? for this list.  Upper or Lower case OK.");
  //     CR or LF to finish picture number entry or execute your selection.");
  //     ? - Show list of commands on Serial Monitor
  //     CR/LF - End number entry, if any and show picture.
  //     default action - Show a message that the user is drunk!  ;-))
  //
  // Operational note:
  //
  //     iUserPic, if -1 is inactive.  # sign entry initializes it to 0, then
  //               number entries build it up until CR/LR terminates entry, sets
  //               BGPic and resets iUserPic to -1.
  //     veriPix - Set this to true to get numbers printed for the BG pictures
  //               during startup (in setup).

  switch (input) {

    case '#':  // Prepare for user picture selection number entry.
      iUserPic = 0;
      break;

    case '0' ... '9':
      //    case '0': case '1': case '2': case '3': case '4':
      //    case '5': case '6': case '7': case '8': case '9':
      if (iUserPic > -1)
        iUserPic = iUserPic * 10 + int(input - '0');
      else {
        Serial.println("Unexpected number input.");
        showInputOptions();
      }
      break;

    case '+':
      if (iUserPic > -1) Serial.println("Number entry aborted.");
      iUserPic = -1;
      BGPic++;
      if (BGPic == randSelections) {
        Serial.println("Picture selection number too high.  Resetting to 0.");
        BGPic = 0;
      }
      break;

    case '-':
      if (iUserPic > -1) Serial.println("Number entry aborted.");
      iUserPic = -1;
      BGPic--;
      if (BGPic < 0) {
        Serial.println("Picture selection number too low.  Resetting to 0.");
        BGPic = 0;
      }
      break;

    case 'B':  // Toggle battery usage state
      if (iUserPic > -1) Serial.println("Number entry aborted.");
      iUserPic = -1;
      dRead = digitalRead(15);
      if (dRead == 0) {
        digitalWrite(15, 1);
        Serial.println("\r\nBattery usage state set to full power. "
                       "There is no off state.");
      } else {
        digitalWrite(15, 0);
        Serial.println("\r\nBattery usage state set to partial power. "
                       "There is no off state.");
      }
      showInputOptions();
      break;

    case 'F':  // Toggle showing all fields
      if (iUserPic > -1) Serial.println("Number entry aborted.");
      iUserPic = -1;
      ShowFields = !ShowFields;
      Serial.printf("Fields will%s be shown.\r\n", ShowFields ? "" : " not");
      showInputOptions();
      break;

    case 'H':  // Show hourly brightness values
      if (iUserPic > -1) Serial.println("Number entry aborted.");
      iUserPic = -1;
      preferences.begin("Hourlys", RO_MODE);
      for (i = 0; i < 24; i++) {
        sprintf(chHour, "%d", i);
        iHTemp = preferences.getInt(chHour, 1000);  // Never been set?
        Serial.printf("Brightness level for hour %2i is %4i\r\n", i, iHTemp);
      }
      preferences.end();
      showInputOptions();
      break;

    case 'I':  // Invert screen
      if (iUserPic > -1) Serial.println("Number entry aborted.");
      iUserPic = -1;
      if (displayInverted) {
        tft.invertDisplay(false);
        displayInverted = false;
      } else {
        tft.invertDisplay(true);
        displayInverted = true;
      }
      showInputOptions();
      break;    // Optional here. Included for completeness.

    case 'L':
      printPixInfo();
      break;

    case 'P':  // Name current BG pic
      if (iUserPic > -1) Serial.println("Number entry aborted.");
      iUserPic = -1;
      Serial.printf("Picture showing is: #%i: ", BGPic);
      Serial.print(pInfo[BGPic].picName);
      Serial.printf(", with brightness of %i/255.\r\n", tftBL_Lvl);
      showInputOptions();
      break;

    case 'R':  // Change BG pic
      if (iUserPic > -1) Serial.println("Number entry aborted.");
      iUserPic = -1;
      Serial.println("User requested new random background picture.");
      BGPic = int(random(randSelections));  // Name will be shown by SetPic_Colors.
      showInputOptions();
      break;

    case 'V':  // Toggle showing battery voltage
      if (iUserPic > -1) Serial.println("Number entry aborted.");
      iUserPic = -1;
      showVolts = !showVolts;
      Serial.printf("\r\Battery voltage will%s be shown.\r\n", showVolts ? "" : " not");
      showInputOptions();
      break;

    case '?':
      if (iUserPic > -1) Serial.println("Number entry aborted.");
      iUserPic = -1;
      showInputOptionsFull();
      break;

    case '\r':
    case '\n':
      if (iUserPic >= randSelections) {
        Serial.println("Picture selection number too high.");
        iUserPic = -1;  // Invalidate and reset number entry mode.
      }
      if (iUserPic > -1) {
        Serial.printf("User requested loading of picture #%3i\r\n", iUserPic);
        BGPic = iUserPic;  // Already range checked.
      }
      iUserPic = -1;  // Reset number entry mode.
      break;

    default:
      if (iUserPic > -1) Serial.println("Number entry aborted.");
      iUserPic = -1;
      Serial.printf("*>> Unknown input \'%c\'!\r\n", input);  // Handle unknown input
      showInputOptions();
      break;
  }
}
