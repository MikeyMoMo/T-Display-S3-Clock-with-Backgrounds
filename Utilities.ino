/*******************************************************************************************/
void SetPic_Colors(const char* myPicName, int timeColor, int dateColor,
                   int battColor, bool doTimeFill, bool doDateFill)
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

  if (prev_BGPic != BGPic) {
    prev_BGPic = BGPic;
    Serial.printf("%02i:%02i:%02i Loading picture %3i: ",
                  iHour, iMinute, iSecond, BGPic);
    Serial.println(myPicName);
  }

  // The callback knows where to put the picture.
  //  This just starts the process.
  TJpgDec.drawFsJpg(0, 0, myPicName, LittleFS);  // Load BG picture only.

  spriteTime.fillSprite(TFT_BLACK);
  if (doTimeFill) {
    for (int i = 20; i < SPR_TIME_HEIGHT; i = i + 2) {
      // Draw almost black lines across the time digits area.
      // I tried (1, 1, 1) but it seems to have considered it still to
      //  be hidden and drew nothing.
      spriteTime.drawFastHLine(0, i, SPR_TIME_WIDTH - 25, RGB565(5, 5, 5));
    }
    for (int i = 0; i < tft.width(); i = i + 2) {
      // Cut holes in the almost black lines to make it semi-transparent.
      spriteTime.drawFastVLine(i, 18, SPR_TIME_HEIGHT - 19, TFT_BLACK);
    }
  }

  spriteDate.fillSprite(TFT_BLACK);
  spriteDateWork.fillSprite(TFT_BLACK);
  if (doDateFill) {
    for (int i = 0; i < SPR_DATE_HEIGHT - 8; i = i + 2) {
      // Draw almost black lines across the time digits area.
      // I tried (1, 1, 1) but it seems to have considered it still to
      //  be hidden and drew nothing.
      spriteDate.drawFastHLine(0, i, SPR_DATE_WIDTH, RGB565(5, 5, 5));
    }
    for (int i = 0; i < SPR_DATE_WIDTH; i = i + 2) {
      // Cut holes in the almost black lines to make it semi-transparent.
      spriteDate.drawFastVLine(i, 0, SPR_DATE_HEIGHT - 8, TFT_BLACK);
    }
  }

  ofr.setFontColor(timeColor, TFT_BLACK);         // spriteTime colors
  spriteBatt.setTextColor(battColor, TFT_BLACK);  // spriteBatt colors
  spriteDate.setTextColor(dateColor, TFT_BLACK);  // spriteDate colors
  spriteDateWork.setTextColor(dateColor, TFT_BLACK);  // Work area colors
}
/************** *****************************************************************************/
void BuildAndShow()
/*******************************************************************************************/
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
  //  BGPic = 12;  // Testing
  switch (BGPic) {
    case   3:  SetPic_Colors("/Arches.jpg",
                               TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_WHITE, false, false);
      break;
    case 105: SetPic_Colors("/BigRack.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, true, true);
      break;
    case 106: SetPic_Colors("/Birds.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_CYAN, true, true);
      break;
    case   4: SetPic_Colors("/BlueBlack.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_CYAN, false, false);
      break;
    case   5: SetPic_Colors("/Bluebonnets.jpg",
                              TFT_WHITE, TFT_YELLOW, TFT_WHITE, false, false);
      break;
    case   6: SetPic_Colors("/BlueBubbles.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case   7: SetPic_Colors("/BlueExplosion.jpg",
                              TFT_WHITE, TFT_YELLOW, TFT_CYAN, true, true);
      break;
    case   8: SetPic_Colors("/BlueFlower.jpg",
                              TFT_MAGENTA, TFT_YELLOW, TFT_WHITE, true, true);
      break;
    case   9: SetPic_Colors("/BlueGold.jpg",
                              TFT_GREENYELLOW, TFT_YELLOW, TFT_WHITE, false, false);
      break;
    case  10: SetPic_Colors("/BlueLagoon.jpg",
                              TFT_GREENYELLOW, TFT_YELLOW, TFT_RED, false, false);
      break;
    case  11: SetPic_Colors("/BlueMirror.jpg",
                              TFT_GREENYELLOW, TFT_YELLOW, TFT_YELLOW, false, false);
      break;
    case  12: SetPic_Colors("/BlueMoon.jpg",
                              TFT_GREENYELLOW, TFT_YELLOW, TFT_YELLOW, false, false);
      break;
    case  13: SetPic_Colors("/BlueRiverGreenTrees.jpg",
                              TFT_GREEN, TFT_YELLOW, TFT_GREEN, false, false);
      break;
    case  14: SetPic_Colors("/BlueSkyTrees.jpg",
                              TFT_MAGENTA, TFT_MAGENTA, TFT_GREEN, false, false);
      break;
    case  15: SetPic_Colors("/BlueSwirl.jpg",
                              TFT_WHITE, TFT_YELLOW, TFT_GREENYELLOW, false, false);
      break;
    case  16: SetPic_Colors("/BlueTriangles.jpg",
                              TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_YELLOW, false, false);
      break;
    case  17: SetPic_Colors("/BlueWaterfall.jpg",
                              TFT_GREENYELLOW, TFT_WHITE, TFT_WHITE, true, true);
      break;
    case  18: SetPic_Colors("/BlueWhiteRipples.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_RED, true, true);
      break;
    case  19: SetPic_Colors("/BlurryReflection.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_CYAN,
                              false, false);
      break;
    case 107: SetPic_Colors("/BoatWharf.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, false, false);
      break;
    case  21: SetPic_Colors("/BrownFence.jpg",  // 0xFC9F = light purple
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, true, false);
      break;
    case 108: SetPic_Colors("/Butterflies.jpg",  // 0xFC9F = light purple
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case  22: SetPic_Colors("/BubblyBackground.jpg",
                              TFT_CYAN, TFT_YELLOW, TFT_RED, true, false);
      break;
    case 109: SetPic_Colors("/BubblyBackground.jpg",
                              TFT_CYAN, TFT_YELLOW, TFT_RED, true, false);
      break;
    case  23: SetPic_Colors("/Butterfly1.jpg",
                              TFT_GREENYELLOW, TFT_YELLOW, TFT_WHITE, true, false);
      break;
    case  24: SetPic_Colors("/Camelia.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, true, true);  // white next
      break;
    case  25: SetPic_Colors("/CapitalBurning.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, true, true);
      break;
    case  26: SetPic_Colors("/Carnations.jpg",
                              TFT_BLUE, TFT_BLUE, TFT_BLUE, true, true);
      break;
    case  27: SetPic_Colors("/CherryBlossoms.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_RED, true, true);
      break;
    case  28: SetPic_Colors("/ColorCubes.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, true, true);
      break;
    case  29: SetPic_Colors("/ColorPetals.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, true, true);
      break;
    case  30: SetPic_Colors("/ColorStars.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_RED, true, true);
      break;
    case  31: SetPic_Colors("/ColorStars2.jpg",
                              TFT_WHITE, TFT_YELLOW, TFT_WHITE, true, false);
      break;
    case  32: SetPic_Colors("/ColorStripes.jpg",
                              TFT_WHITE, TFT_YELLOW, TFT_WHITE, false, true);
      break;
    case  33: SetPic_Colors("/ColorSwirls.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, true, false);
      break;
    case  34: SetPic_Colors("/Crimson.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_YELLOW, true, false);
      break;
    case  35: SetPic_Colors("/DeepBlue.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_YELLOW, false, false);
      break;
    case  36: SetPic_Colors("/DiagonalRainbow.jpg",
                              TFT_RED, TFT_RED, TFT_RED, false, false);
      break;
    case  37: SetPic_Colors("/DotVortex.jpg",
                              TFT_CYAN, TFT_WHITE, TFT_WHITE, true, false);
      break;
    case  38: SetPic_Colors("/Eyes.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_YELLOW, true, false);
      break;
    case  39: SetPic_Colors("/FallSunset.jpg",
                              TFT_CYAN, TFT_WHITE, TFT_CYAN, true, true);
      break;
    case  40: SetPic_Colors("/FantasyIsland.jpg",
                              TFT_WHITE, TFT_YELLOW, TFT_PURPLE, true, true);
      break;
    case 110: SetPic_Colors("/FrostyTrees.jpg",
                              TFT_WHITE, TFT_YELLOW, TFT_WHITE, true, true);
      break;
    case  41: SetPic_Colors("/FtBraggOcean.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_MAGENTA, false, true);
      break;
    case 111: SetPic_Colors("/FtBraggOcean.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_MAGENTA, false, true);
      break;
    case  42: SetPic_Colors("/Geometric1.jpg",
                              TFT_CYAN, TFT_YELLOW, TFT_CYAN, false, false);
      break;
    case  43: SetPic_Colors("/GoldenGateBridge.jpg",
                              TFT_WHITE, TFT_GREENYELLOW, TFT_WHITE, true, true);
      break;
    case  44: SetPic_Colors("/GoldenTreeLine.jpg",
                              TFT_GREENYELLOW, TFT_YELLOW, TFT_GREEN, false, false);
      break;
    case  45: SetPic_Colors("/GossamerButterfly.jpg",
                              TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_WHITE, true, true);
      break;
    case  46: SetPic_Colors("/GreenMarquee.jpg",
                              TFT_YELLOW, TFT_WHITE, TFT_WHITE, true, true);
      break;
    case  47: SetPic_Colors("/GreenRocks.jpg",
                              TFT_MAGENTA, TFT_MAGENTA, TFT_YELLOW, false, false);
      break;
    case  48: SetPic_Colors("/GreenTreeRoad.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case  49: SetPic_Colors("/Heather.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, false, false);
      break;
    case  50: SetPic_Colors("/HotAirBalloons.jpg",
                              TFT_WHITE, TFT_YELLOW, TFT_CYAN, true, false);
      break;
    case  51: SetPic_Colors("/HotPink.jpg",
                              TFT_BLUE, TFT_BLUE, TFT_BLUE, true, false);
      break;
    case  52: SetPic_Colors("/IntenseBlue.jpg",
                              TFT_WHITE, TFT_YELLOW, TFT_WHITE, true, false);
      break;
    case  53: SetPic_Colors("/JapaneseMellow.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_YELLOW, false, false);
      break;
    case  54: SetPic_Colors("/JustFish.jpg",
                              TFT_CYAN, TFT_YELLOW, TFT_CYAN, false, false);
      break;
    case  55: SetPic_Colors("/KidRainbow.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, true, true);
      break;
    case  56: SetPic_Colors("/LeafRipples.jpg",
                              TFT_CYAN, TFT_YELLOW, TFT_CYAN, false, false);
      break;
    case  57: SetPic_Colors("/Lilypads.jpg",
                              TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_WHITE, true, false);
      break;
    case  58: SetPic_Colors("/LitMushrooms.jpg",
                              TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_WHITE, false, false);
      break;
    case  59: SetPic_Colors("/Marshmallows.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, true, true);
      break;
    case  60: SetPic_Colors("/Meadow.jpg",
                              TFT_RED, TFT_RED, TFT_RED, true, true);
      break;
    case  61: SetPic_Colors("/MellowGold.jpg",
                              TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_YELLOW, false, false);
      break;
    case 112: SetPic_Colors("/MeteorShower.jpg",
                              TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_YELLOW, true, false);
      break;
    case  62: SetPic_Colors("/MilkyWay.jpg",
                              TFT_GREEN, TFT_BLUE, TFT_CYAN, true, true);
      break;
    case 113: SetPic_Colors("/MilkyWay2.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, false, true);
      break;
    case 114: SetPic_Colors("/MistyFullMoon.jpg",
                              TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_YELLOW, false, true);
      break;
    case  63: SetPic_Colors("/MistySunset.jpg",
                              TFT_GREEN, TFT_GREEN, TFT_CYAN, true, true);
      break;
    case  64: SetPic_Colors("/MistyValley.jpg",
                              TFT_GREEN, TFT_YELLOW, TFT_GREEN, false, true);
      break;
    case  65: SetPic_Colors("/Moon1.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_WHITE, false, false);
      break;
    case  66: SetPic_Colors("/MoonCastle.jpg",
                              TFT_GREEN, TFT_YELLOW, TFT_GREEN, false, true);
      break;
    case  67: SetPic_Colors("/OrangeBlur.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_YELLOW, true, true);
      break;
    case  68: SetPic_Colors("/OrangeCircles.jpg",
                              TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_YELLOW, true, true);
      break;
    case 115: SetPic_Colors("/OrangeMoon.jpg",
                              TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_WHITE, false, false);
      break;
    case  69: SetPic_Colors("/PhantomFlower.jpg",
                              TFT_BLUE, TFT_BLUE, TFT_BLUE, true, true);
      break;
    case  70: SetPic_Colors("/PinkBalls.jpg",
                              TFT_BLUE, TFT_BLUE, TFT_BLUE, true, true);
      break;
    case  71: SetPic_Colors("/PinkBubbles.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case  72: SetPic_Colors("/PinkClouds.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case  73: SetPic_Colors("/PinkFlowers.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case  74: SetPic_Colors("/PinkPurple.jpg",
                              TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_YELLOW, true, true);
      break;
    case  75: SetPic_Colors("/PinkRoses.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_BLUE, true, true);
      break;
    case  76: SetPic_Colors("/PsycodelicNotes.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, true, false);
      break;
    case  77: SetPic_Colors("/PurpleBramble.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, false, false);
      break;
    case  78: SetPic_Colors("/PurpleButterfly.jpg",
                              TFT_WHITE, TFT_CYAN, TFT_CYAN, true, false);
      break;
    case  79: SetPic_Colors("/PurpleFlowers.jpg",
                              TFT_GREENYELLOW, TFT_GREENYELLOW, TFT_YELLOW, true, true);
      break;
    case  80: SetPic_Colors("/PurpleGossamer.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_YELLOW, true, true);
      break;
    case  81: SetPic_Colors("/PurpleLeaves.jpg",
                              RGB565(255, 0, 80), TFT_RED, TFT_CYAN, true, false);
      break;
    case  82: SetPic_Colors("/PurpleLightning.jpg",
                              TFT_GREENYELLOW, TFT_YELLOW, TFT_RED, false, false);
      break;
    case  83: SetPic_Colors("/PurpleSunset.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, true, true);
      break;
    case  84: SetPic_Colors("/Radiance.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_GREENYELLOW, false, false);
      break;
    case 116: SetPic_Colors("/Radiance2.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_CYAN, false, false);
      break;
    case  85: SetPic_Colors("/RedandYellow.jpg",
                              RGB565(80, 80, 255), TFT_CYAN, TFT_CYAN, true, true);
      break;
    case  86: SetPic_Colors("/RedGoldPath.jpg",
                              TFT_CYAN, TFT_BLUE, TFT_CYAN, true, true);
      break;
    case  87: SetPic_Colors("/RedLeaves.jpg",
                              TFT_GREENYELLOW, TFT_WHITE, TFT_GREENYELLOW, false, false);
      break;
    case  88: SetPic_Colors("/RedTracks.jpg",
                              TFT_YELLOW, TFT_CYAN, TFT_GREEN, true, true);
      break;
    case  89: SetPic_Colors("/Redwoods.jpg",
                              TFT_GREEN, TFT_YELLOW, TFT_CYAN, false, false);
      break;
    case 117: SetPic_Colors("/RightChevron.jpg",
                              TFT_GREEN, TFT_YELLOW, TFT_CYAN, false, false);
      break;
    case 118: SetPic_Colors("/Sailboat.jpg",
                              TFT_CYAN, TFT_GREENYELLOW, TFT_WHITE, false, false);
      break;
    case  90: SetPic_Colors("/Sepia.jpg",
                              TFT_GREENYELLOW, TFT_YELLOW, TFT_GREENYELLOW, false, false);
      break;
    case  91: SetPic_Colors("/ShyFlowers.jpg",
                              TFT_CYAN, TFT_BLUE, TFT_WHITE, false, false);
      break;
    case  92: SetPic_Colors("/SnowTree.jpg",
                              TFT_RED, TFT_RED, TFT_YELLOW, true, true);
      break;
    case  93: SetPic_Colors("/SS1.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_YELLOW, false, false);
      break;
    case  94: SetPic_Colors("/StarBurst.jpg",
                              TFT_WHITE, TFT_CYAN, TFT_WHITE, true, false);
      break;
    case  95: SetPic_Colors("/StuffedAnimals.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case  96: SetPic_Colors("/SunsetSky.jpg",
                              TFT_CYAN, TFT_WHITE, TFT_CYAN, true, true);
      break;
    case 119: SetPic_Colors("/SydneyOpera.jpg",
                              TFT_CYAN, TFT_WHITE, TFT_CYAN, true, true);
      break;
    case  97: SetPic_Colors("/TanFlowers.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case  98: SetPic_Colors("/Tiger.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case  99: SetPic_Colors("/Tulips.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_YELLOW, true, true);
      break;
    case 100: SetPic_Colors("/Waterfall.jpg",
                              TFT_CYAN, TFT_WHITE, TFT_RED, false, false);
      break;
    case 120: SetPic_Colors("/Waterfall.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case 101: SetPic_Colors("/WetDaisy.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case 102: SetPic_Colors("/WolfMoon.jpg",
                              TFT_YELLOW, TFT_YELLOW, TFT_YELLOW, false, false);
      break;
    case 121: SetPic_Colors("/XmasVillage.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, false, false);
      break;
    case 103: SetPic_Colors("/YellowOrangeSwirl.jpg",
                              TFT_WHITE, TFT_WHITE, TFT_WHITE, true, true);
      break;
    case 104: SetPic_Colors("/YellowWash.jpg",
                              TFT_CYAN, TFT_CYAN, TFT_CYAN, true, true);
      break;

    // And, now, the three digital graphics backgrounds.
    case 0:
      if (prev_BGPic != BGPic) {
        prev_BGPic = BGPic;
        Serial.printf("%02i:%02i:%02i Loading graphic 1-Red) (%i)\r\n",
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
    case 1:
      if (prev_BGPic != BGPic) {
        prev_BGPic = BGPic;
        Serial.printf("%02i:%02i:%02i Loading graphic 2-Blue (%i)\r\n",
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
    case 2:
      if (prev_BGPic != BGPic) {
        prev_BGPic = BGPic;
        Serial.printf("%02i:%02i:%02i Loading graphic 3-Green (%i)\r\n",
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
      ofr.setFontColor(TFT_RED, TFT_BLACK);
      break;
    default:
      Serial.printf("No match for BGPic graphic selector %i\r\n", BGPic); break;
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
  //  spriteDate.fillSprite(TFT_BLACK);
  sprintf(chBuffer, "%s  %s %s, %i",
          String(chDayofWeek), String(chMonth),
          String(chDayOfMonth), iYear);
  // I am doing a little magic here to end up with a #2 (built-in) font in a sprite.
  //  First, I will drawString the text onto spriteDateWork with the font background
  //  color being black.  At this point, it would be visible if shown.
  //  But, then I will push that onto spriteDate with black invisible then push that
  //  onto spriteBG for the final presentation.  It is double work but I end up with
  //  characters that let the background picture or graphic show through them.
  spriteDateWork.drawString(String(chBuffer),
                            (SPR_DATE_WIDTH / 2) -
                            (tft.textWidth(chBuffer, SPR_DATE_FONT_SIZE) / 2),
                            0, SPR_DATE_FONT_SIZE);
  spriteDateWork.pushToSprite(&spriteDate, 0, 0, TFT_BLACK);
  spriteDate.pushToSprite(&spriteBG,
                          (tft.width() / 2) - (SPR_DATE_WIDTH / 2),
                          138, TFT_BLACK);
  // Read the battery voltage.
  uVolt = (analogRead(4) * 2 * 3.3 * 1000) / 4096;
  spriteBatt.fillSprite(TFT_BLACK);
  if (millis() > BLChangeMillis + BRIGHTNESS_SHOW_MILLIS) {
    // This sprite was just set to black (the invisible color).
    //  So, having nothing happen here means that it will be blank.
    //  There will not even be a background or outline.  Just nothing!
    // Upeate the battery sprite.0
    //    spriteBatt.drawString(String(uVolt / 1000) + "." +
    //                          String(uVolt % 1000)
    //                          + " vDC", 0, 0, SPR_BATTERY_FONT_SIZE);
  } else {
    spriteBatt.drawString("Brightness: " + String(tftBL_Lvl), 0, 0,
                          SPR_BATTERY_FONT_SIZE);
  }
  spriteBatt.pushToSprite(&spriteBG, 4, 2, TFT_BLACK);
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
  pickHourBrightness();
  Serial.printf("Hourdance derived brightness level for hour %i of %i\r\n",
                iHour, tftBL_Lvl);
}
/*******************************************************************************************/
void pickHourBrightness()
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
  if ((iHour == 23 || iHour < 10) && tftBL_Lvl == 1000)
    tftBL_Lvl = 0;
  if (tftBL_Lvl == 1000) tftBL_Lvl = defaultBright;
  ledcWrite(TFT_BL, tftBL_Lvl);  // Activate whatever was decided on.
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
