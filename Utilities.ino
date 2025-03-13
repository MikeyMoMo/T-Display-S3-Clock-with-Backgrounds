/****************************************************************************/
void SetPic_Colors(const char* myPicName, int timeColor, int dateColor,
                   int battColor, bool doTimeFill)
/****************************************************************************/
{
  if (prev_BGPic != BGPic) {
    prev_BGPic = BGPic;
    Serial.printf("%02i:%02i:%02i Loading picture %2i: ",
                  iHour, iMinute, iSecond, BGPic);
    Serial.println(myPicName);
  }

  // The callback knows where to put the picture.
  //  This just starts the process.
  TJpgDec.drawFsJpg(0, 0, myPicName);       // Load BG picture only.

  spriteTime.fillSprite(TFT_BLACK);
  if (doTimeFill) {
    for (int i = 20; i < SPRITE_TIME_HEIGHT; i = i + 2) {
      // Draw almost black lines across the time digits area.
      spriteTime.drawFastHLine(0, i, tft.width() - 45, RGB565(5, 5, 5));
    }
    for (int i = 0; i < tft.width(); i = i + 2) {
      // Cut holes in the almost black lines to make it semi-transparent.
      spriteTime.drawFastVLine(i, 18, SPRITE_TIME_HEIGHT - 19, TFT_BLACK);
    }
  }

  ofr.setFontColor(timeColor, TFT_BLACK);         // spriteTime colors
  spriteBatt.setTextColor(battColor, TFT_BLACK);  // spriteBatt colors
  spriteDate.setTextColor(dateColor, TFT_BLACK);  // spriteDate colors
}
/****************************************************************************/
void BuildAndShow()
/****************************************************************************/
{
  // Show a background picture. Draw the image, top left at 0,0
  // This works:
  //  SetPic_Colors("/MistyValley.jpg",
  //                TFT_GREEN, TFT_YELLOW, TFT_GREEN);
  // This also works
  //  SetPic_Colors(PicNames[0],
  //                TFT_GREEN, TFT_YELLOW,TFT_GREEN);
  //  void SetPic_Colors(const char* myPicName, int timeColor,
  //                     int dateColor, int battColor)
  // This also works
  //  void SetPic_Colors(char* myPicName, int timeColor, int dateColor,
  //                     int battColor)

  switch (BGPic) {
    case 0:  SetPic_Colors("/MistyValley.jpg", TFT_GREEN, TFT_YELLOW,
                             TFT_GREEN, false);
      break;
    case 1:  SetPic_Colors("/BubblyBackground.jpg",
                             TFT_CYAN, TFT_YELLOW, TFT_RED, true);
      break;
    case 2:  SetPic_Colors("/LeafRipples.jpg",
                             TFT_CYAN, TFT_YELLOW, TFT_CYAN, false);
      break;
    case 3:  SetPic_Colors("/MistySunset.jpg", TFT_GREENYELLOW,
                             TFT_YELLOW, TFT_GREENYELLOW, false);
      break;
    case 4:  SetPic_Colors("/BlueLagoon.jpg",
                             TFT_GREENYELLOW, TFT_YELLOW, TFT_RED, false);
      break;
    case 5:  SetPic_Colors("/BlueRiverGreenTrees.jpg",
                             TFT_WHITE, TFT_YELLOW, TFT_WHITE, false);
      break;
    case 6:  SetPic_Colors("/FantasyIsland.jpg",
                             TFT_WHITE, TFT_YELLOW, TFT_PURPLE, true);
      break;
    case 7:  SetPic_Colors("/GoldenSunset.jpg",
                             TFT_GREEN, TFT_YELLOW, TFT_GREEN, false);
      break;
    case 8:  SetPic_Colors("/GoldenTreeLine.jpg", TFT_GREENYELLOW,
                             TFT_YELLOW, TFT_GREEN, false);
      break;
    case 9:  SetPic_Colors("/GreenTreeRoad.jpg",
                             0xFC9F, TFT_PINK, TFT_WHITE, false);
      break;
    case 10: SetPic_Colors("/JapaneseMellow.jpg",
                             TFT_CYAN, TFT_CYAN, TFT_CYAN, false);
      break;
    case 11: SetPic_Colors("/BirdCreamSky.jpg",
                             TFT_CYAN, TFT_CYAN, TFT_CYAN, true);
      break;
    case 12: SetPic_Colors("/BlueBubbles.jpg",
                             RGB565(255, 80, 128) , TFT_WHITE ,
                             TFT_WHITE, true);
      break;
    case 13: SetPic_Colors("/BlueExplosion.jpg",
                             TFT_ORANGE, TFT_YELLOW, TFT_CYAN, true);
      break;
    case 14: SetPic_Colors("/BlueWhiteRipples.jpg",
                             TFT_ORANGE, TFT_WHITE,
                             TFT_RED, true);
      break;
    case 15: SetPic_Colors("/BlurryReflection.jpg",
                             TFT_YELLOW, TFT_GREENYELLOW, TFT_CYAN, false);
      break;
    case 16: SetPic_Colors("/BrownDesert.jpg",
                             TFT_CYAN, TFT_YELLOW, TFT_CYAN, false);
      break;
    case 17: SetPic_Colors("/FtBraggOcean.jpg",
                             TFT_YELLOW, TFT_YELLOW, TFT_MAGENTA, false);
      break;
    case 18: SetPic_Colors("/GoldenGateBridge.jpg",
                             TFT_WHITE, TFT_RED, TFT_CYAN, true);
      break;
    case 19: SetPic_Colors("/HotAirBalloons.jpg",
                             TFT_WHITE, TFT_YELLOW, TFT_CYAN, true);
      break;
    case 20: SetPic_Colors("/LittleBoatBlueOcean.jpg",
                             TFT_WHITE, TFT_YELLOW, TFT_CYAN, false);
      break;
    case 21: SetPic_Colors("/PinkBubbles.jpg",
                             TFT_CYAN, TFT_WHITE, TFT_WHITE, true);
      break;
    case 22: SetPic_Colors("/PurpleLightning.jpg",
                             TFT_GREENYELLOW, TFT_YELLOW, TFT_RED, false);
      break;
    case 23: SetPic_Colors("/Redwoods.jpg",
                             TFT_GREEN, TFT_YELLOW, TFT_CYAN, false);
      break;
    case 24: SetPic_Colors("/RockHoleOcean.jpg",
                             TFT_CYAN, TFT_YELLOW, TFT_CYAN, true);
      break;
    case 25: SetPic_Colors("/SkylineReflection.jpg",
                             TFT_CYAN, TFT_YELLOW, TFT_CYAN, false);
      break;
    case 26: SetPic_Colors("/SunsetSky.jpg",
                             TFT_CYAN, TFT_YELLOW, TFT_CYAN, false);
      break;
    case 27: SetPic_Colors("/Waterfall.jpg",
                             TFT_CYAN, TFT_YELLOW, TFT_CYAN, false);
      break;
    case 28: SetPic_Colors("/YellowOrangeSwirl.jpg",
                             TFT_CYAN, TFT_CYAN, TFT_CYAN, false);
      break;
    case 29: SetPic_Colors("/PinkClouds.jpg",
                             TFT_GREEN, TFT_GREEN, TFT_GREEN, false);
      break;
    case 30: SetPic_Colors("/StuffedAnimals.jpg",
                             TFT_WHITE, TFT_WHITE, TFT_WHITE, true);
      break;
    case 31: SetPic_Colors("/PurpleGossamer.jpg",
                             TFT_GREENYELLOW, TFT_YELLOW, TFT_YELLOW, true);
      break;
    case 32: SetPic_Colors("/CherryBlossoms.jpg",
                             TFT_CYAN, TFT_RED, TFT_CYAN, true);
      break;
    case 33: SetPic_Colors("/Marsmallows.jpg",
                             TFT_CYAN, TFT_CYAN, TFT_CYAN, true);
      break;
    case 34: SetPic_Colors("/PurpleLeaves.jpg",
                             TFT_RED, TFT_RED, TFT_CYAN, true);
      break;
    case 35: SetPic_Colors("/RedandYellow.jpg",
                             TFT_BLUE, TFT_CYAN, TFT_CYAN, true);
      break;
    case 36: SetPic_Colors("/YellowWash.jpg",
                             TFT_GREEN, TFT_GREEN, TFT_CYAN, true);
      break;
    case 37:
      if (prev_BGPic != BGPic) {
        prev_BGPic = BGPic;
        Serial.printf("%02i:%02i:%02i Loading graphic 1-Red) (%2i)\r\n",
                      iHour, iMinute, iSecond, BGPic);
      }
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
      ofr.setFontColor(TFT_GREENYELLOW, TFT_BLACK);
      break;
    case 38:
      if (prev_BGPic != BGPic) {
        prev_BGPic = BGPic;
        Serial.printf("%02i:%02i:%02i Loading graphic 2-Blue (%2i)\r\n",
                      iHour, iMinute, iSecond, BGPic);
      }
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
      ofr.setFontColor(TFT_GREENYELLOW, TFT_BLACK);
      break;
    default:
      Serial.printf("BGPic is out of range at %i\r\n", BGPic); break;
  }
  // Update the time sprite.  The optional screen is already in.
  sprintf(chBuffer, "%02i:%02i:%02i", iHour, iMinute, iSecond);
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

  ofr.setCursor(0, 5);
  ofr.printf(chBuffer);
  spriteTime.pushToSprite(&spriteBG, 20, 38, TFT_BLACK);

  // Create and draw the date sprite onto the background sprite.
  // Leading zero supression for the day of monthmonth.

  nTemp = atoi(chDayOfMonth);
  if (nTemp < 10) sprintf(chDayOfMonth, "%2d", nTemp);

  // Update the date sprite
  spriteDate.fillSprite(TFT_BLACK);
  sprintf(chBuffer, "%s  %s %s, %i",
          String(chDayofWeek), String(chMonth),
          String(chDayOfMonth), iYear);
  spriteDate.drawString(String(chBuffer),
                        (SPRITE_DATE_WIDTH / 2) -
                        (tft.textWidth(chBuffer, SPRITE_DATE_FONT_SIZE) / 2),
                        0, SPRITE_DATE_FONT_SIZE);
  spriteDate.pushToSprite(&spriteBG,
                          (tft.width() / 2) - (SPRITE_DATE_WIDTH / 2),
                          138, TFT_BLACK);
  // Read the battery voltage.
  uVolt = (analogRead(4) * 2 * 3.3 * 1000) / 4096;
  spriteBatt.fillSprite(TFT_BLACK);
  if (millis() > BLChangeMillis + BRIGHTNESS_SHOW_MILLIS) {
    // This sprite was just set to black (the invisible color).
    //  So, having nothing happen here means that it will be blank.
    //  There will not even be a background or outline.  Just nothing!
    // Upeate the battery sprite.
    //    spriteBatt.drawString(String(uVolt / 1000) + "." +
    //                          String(uVolt % 1000)
    //                          + " vDC", 0, 0, SPRITE_BATTERY_FONT_SIZE);
  } else {
    spriteBatt.drawString("Brightness: " + String(tftBL_Lvl), 0, 0,
                          SPRITE_BATTERY_FONT_SIZE);
  }
  spriteBatt.pushToSprite(&spriteBG, 4, 2, TFT_BLACK);
  spriteBG.pushSprite(0, 0); spriteBG.fillSprite(TFT_BLACK);
  delay(1);
}
/****************************************************************************/
void CheckButtons()
/****************************************************************************/
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

    ledcWrite(38, tftBL_Lvl);
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

    ledcWrite(38, tftBL_Lvl);
    //    Serial.printf("-tft brightness now %i\r\n", tftBL_Lvl);
    BLChangeMillis = millis();
    BuildAndShow();
    delay(150);
  }
}
/****************************************************************************/
void GetCurrentTime()
/****************************************************************************/
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
/****************************************************************************/
void HourDance()
/****************************************************************************/
{
  Serial.printf("It is now %02i:00\r\n", iHour);

  // Do HourDance after updating the display to xx:00:00
  for (int i = 0; i < 4; i++) {
    tft.invertDisplay(false); delay(200);
    tft.invertDisplay(true); delay(200);
  }
  pickHourBrightness();
  Serial.printf("Hourdance derived brightness level for hour %i of %i\r\n",
                iHour, tftBL_Lvl);
}
/****************************************************************************/
void pickHourBrightness()
/****************************************************************************/
{
  // For normal operation, use this one.
  preferences.begin("Hourlys", RO_MODE);
  // To clear out all of the hourly readings, use the following two instead.
  //  preferences.begin("Hourlys", RW_MODE);
  //  preferences.clear();

  // If this hour has not been set, 1000 will be returned.  If it is
  //  and it is late, turn off the display.  It can be turned back on
  //  if anyone is awake and want to set it to be on for the hour.
  sprintf(chHour, "%d", iHour);
  tftBL_Lvl = preferences.getInt(chHour, 1000);  // Never been set?
  Serial.printf("Read brightness level for %i of %i\r\n",
                iHour, tftBL_Lvl);
  preferences.end();
  if ((iHour == 23 || iHour < 10) && tftBL_Lvl == 1000)
    tftBL_Lvl = 0;
  if (tftBL_Lvl == 1000) tftBL_Lvl = defaultBright;
  ledcWrite(38, tftBL_Lvl);  // Activate whatever was decided on.
}
/****************************************************************************/
void SaveBrightness()
/****************************************************************************/
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
/****************************************************************************/
void initTime()
/****************************************************************************/
{
  sntp_set_sync_interval(86405432);  // 1 day in ms plus a little.
  sntp_set_time_sync_notification_cb(timeSyncCallback);
  sntp_set_sync_mode(SNTP_SYNC_MODE_SMOOTH);
  configTzTime("PHT-8", "time.nist.gov");
  Serial.print("Waiting for correct time...");

  strftime(chBuffer, sizeof(chBuffer), "%Y", localtime(&workTime));
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
/****************************************************************************/
void timeSyncCallback(struct timeval * tv)
/****************************************************************************/
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
