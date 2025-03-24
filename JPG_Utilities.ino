/*******************************************************************************************/
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
/*******************************************************************************************/
{
  // Stop further decoding as image is running off bottom of screen
  if ( y >= tft.height() ) return 0;

  // This function will clip the image block rendering automatically at the TFT boundaries
  tft.pushImage(x, y, w, h, bitmap);

  // Return 1 to decode next block
  return 1;
}

// This next function will be called during decoding of the jpeg file to
// render each block to the sprite spriteBG.
/*******************************************************************************************/
bool spr_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
/*******************************************************************************************/
{
  // Stop further decoding as image is running off bottom of sprite
  if ( y >= spriteBG.height() ) return 0;

  // This function will clip the image block rendering automatically at the sprite boundaries
  spriteBG.pushImage(x, y, w, h, bitmap);

  // Return 1 to decode next block
  return 1;
}
/*******************************************************************************************/
void FillPixArray()
/*******************************************************************************************/
{
  //struct picDef
  //{
  //  char picName[20];
  //  unsigned int tColor;  // Text Color for Time
  //  unsigned int dColor;  // Text Color for Date
  //  unsigned int bColor;  // Text Color for Brightness
  //  bool tHatch;          // True or False, do hatching for Time string
  //  bool dHatch;          // True or False, do hatching for Date string
  //};
  //struct picDef PixInfo[200];

  BGPic = 0;

  // Red Digital Graphic
  strcpy(PixInfo[BGPic].picName, "Red Digital Graphic");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREENYELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "Blue Digital Graphic");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREENYELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  // Green Digital Graphic
  strcpy(PixInfo[BGPic].picName, "Green Digital Graphic");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_RED;
  PixInfo[BGPic].tColor = TFT_RED; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_RED; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/AniForest.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Arches.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/AutumnBlur.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Balloons.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BigRack.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BigSurf.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Birds.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlowIt.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueBlack.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Bluebonnets.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueBubbles.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueExplosion.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueFlower.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueGold.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueGray.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueLagoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_RED;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueMirror.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueMoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueRiverGreenTrees.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREEN;
  PixInfo[BGPic].tColor = TFT_GREEN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueSkyTrees.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREEN;
  PixInfo[BGPic].tColor = TFT_MAGENTA; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueSwirl.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREENYELLOW;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueTesla.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueTree.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueTriangles.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueWaterfall.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlueWhiteRipples.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BlurryReflection.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BoatWharf.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BrownDesert.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BrownFence.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BrownTrees.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/BubblyBackground.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Butterflies.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_PINK; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_RED; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Butterfly1.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Cabanas.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Camelia.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/CapitalBurning.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Carnations.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/CherryBlossoms.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_RED;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/CloudTops.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/ColorBoards.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/ColorCubes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/ColorPetals.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/ColorStars.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_RED;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/ColorStars2.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/ColorStripes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/ColorSwirls.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/CopperOrbs.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Crimson.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/CryptoMoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Daisys.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/DeepBlue.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/DiagonalRainbow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_RED;
  PixInfo[BGPic].tColor = TFT_RED; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_RED; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/DontKnow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/DotVortex.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Ejection.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Eyes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/FallSunset.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/FantasyIsland.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_PURPLE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/FireWing.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREEN;
  PixInfo[BGPic].tColor = TFT_GREEN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREEN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/FlowerWheel.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Frame.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/FrostyTrees.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/FtBraggOcean.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_MAGENTA;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GardenStair.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Geometric1.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GoldenGateBridge.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GoldenTreeLine.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREEN;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GoldVein.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GossamerButterfly.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GreenHorse.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_PINK; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GreenMarquee.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GreenMist.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GreenRocks.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GreenTrail.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GreenTreeRoad.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/GreenWaterfall.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Halloween.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREENYELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Hearth.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREENYELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Heather.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true; // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/HotAirBalloons.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true; // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/HotPink.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_BLUE;
  PixInfo[BGPic].tColor = TFT_BLUE; PixInfo[BGPic].tHatch = true; // Time Hatch
  PixInfo[BGPic].dColor = TFT_BLUE; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/IntenseBlue.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true; // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/IntenseRed.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/JapaneseMellow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/JustFish.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Justice.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/KidRainbow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true; // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/LeafDrops.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/LeafRipples.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Library.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/LightStreak.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Lilypads.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/LitMushrooms.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Marshmallows.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_GREEN; PixInfo[BGPic].tHatch = true; // Time Hatch
  PixInfo[BGPic].dColor = TFT_BLUE; PixInfo[BGPic++].dHatch = true; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Meadow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_RED;
  PixInfo[BGPic].tColor = TFT_PINK; PixInfo[BGPic].tHatch = true; // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Meadow2.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true; // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/MellowGold.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false; // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/MeteorShower.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = true; // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/MilkyWay.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_GREEN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_BLUE; PixInfo[BGPic++].dHatch = true; // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/MilkyWay2.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/MistyFullMoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/MistySunset.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_GREEN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREEN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/MistyValley.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREEN;
  PixInfo[BGPic].tColor = TFT_GREEN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Moon1.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/MoonCastle.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_GREEN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/MusicNotes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/OilSlick.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/OrangeBlur.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/OrangeCircles.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/OrangeGeo.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/OrangeMoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/OrangeSun.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/OrangeTown.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/OtherWorld.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Outhouse.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PaintedSky.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PaintSplats.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_GREEN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREEN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PhantomFlower.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PinkBalls.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_BLUE;
  PixInfo[BGPic].tColor = TFT_BLUE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_BLUE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PinkBubbles.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PinkClouds.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PinkFlowers.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREENYELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PinkPurple.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PinkRoses.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_BLUE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Plasma.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PsychButterfly.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PsychCamera.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PsychMeteors.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PsychMountains.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PsychNotes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PsychPaisley.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PsychRecord.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PsychSky.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PsychVortex.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PsycodelicNotes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PurpleBramble.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PurpleButterfly.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PurpleFlowers.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PurpleGossamer.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PurpleHeather.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PurpleLeaves.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = RGB565(255, 0, 80); PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_RED; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PurpleLightning.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_RED;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PurpleOrbs.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/PurpleSunset.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Radiance.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREENYELLOW;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Radiance2.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Radiance3.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/RainyStreet.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/RBExplosion.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/RedandYellow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = RGB565(80, 80, 255); PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/RedChurch.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/RedConcave.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/RedGoldPath.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_BLUE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/RedLeaves.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREENYELLOW;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/RedTracks.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREEN;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Redwoods.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_GREEN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/RightChevron.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/RockStream.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Sailboat.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_GREENYELLOW;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Seagull.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Sepia.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_GREENYELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREENYELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/ShyFlowers.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_PINK; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/SnowTree.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_RED; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_RED; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/SomeLeaves.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/SpaceStation.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/SpaceTiger.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Spectral.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_GREEN;  PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Spikes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Spiral.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Spirals.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Spirals2.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/SS1.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/StarBurst.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/StuffedAnimals.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/SunsetSky.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/SydneyOpera.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/TanFlowers.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/TeddyBear.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Tiger.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Traces.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Tulips.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/TwoTrees.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Violets.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/WarpSpeed.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/Waterfall.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_RED;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/WaterLeaves.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_WHITE;
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/WetWalk.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/WetDaisy.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/WildArt.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/WolfMoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/XmasVillage.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_YELLOW;
  PixInfo[BGPic].tColor = TFT_YELLOW; PixInfo[BGPic].tHatch = false;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_YELLOW; PixInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/YellowOrangeSwirl.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = RGB565(20, 120, 255);
  PixInfo[BGPic].tColor = TFT_WHITE; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_WHITE; PixInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(PixInfo[BGPic].picName, "/YellowWash.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, PixInfo[BGPic].picName);
  PixInfo[BGPic].bColor = TFT_CYAN;
  PixInfo[BGPic].tColor = TFT_CYAN; PixInfo[BGPic].tHatch = true;  // Time Hatch
  PixInfo[BGPic].dColor = TFT_CYAN; PixInfo[BGPic++].dHatch = true;  // Date Hatch
}
