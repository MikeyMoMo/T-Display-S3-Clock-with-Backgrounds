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
  //  char picName[30];
  //  unsigned int tColor;  // Text Color for Time
  //  unsigned int dColor;  // Text Color for Date
  //  unsigned int bColor;  // Text Color for Brightness
  //  unsigned int oColor;  // Outline Color
  //  bool tHatch;          // True or False, do hatching for Time string
  //  bool dHatch;          // True or False, do hatching for Date string
  //};
  //struct picDef pInfo[200];

  BGPic = 0;

  // Red Digital Graphic
  strcpy(pInfo[BGPic].picName, "Red Digital Graphic");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = TFT_WHITE;
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "Blue Digital Graphic");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = TFT_WHITE;
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  // Green Digital Graphic
  strcpy(pInfo[BGPic].picName, "Green Digital Graphic");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_RED; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = TFT_WHITE;
  pInfo[BGPic].dColor = TFT_RED; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/AICalm.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/AniForest.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Arches.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/AutumnBlur.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Balloons.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BigRack.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BigSurf.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(50, 255, 80);
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Birds.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlowIt.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueBlack.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Bluebonnets.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueBubbles.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueExplosion.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueFlower.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueGold.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueGray.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueLagoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueMirror.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueMoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = RGB565(255, 50, 25); pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueRiverGreenTrees.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueSkyTrees.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueSwirl.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueTesla.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueTree.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueTriangles.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueWaterfall.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueWhiteRipples.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(5, 5, 5);
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlurryReflection.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BoatWharf.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BrownDesert.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BrownFence.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BrownTrees.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BubblyBackground.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Butterflies.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Butterfly1.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Cabanas.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Camelia.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CapitalBurning.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Carnations.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CherryBlossoms.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CloudTops.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorBoards.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorCubes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorPetals.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorStars.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorStars2.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorStripes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorSwirls.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CopperOrbs.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Crimson.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CryptoMoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Daisys.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DeepBlue.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DiagonalRainbow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DontKnow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DotVortex.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Ejection.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Eyes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(255, 50, 25);
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FallSunset.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FantasyIsland.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FireWing.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREEN;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREEN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FlowerWheel.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Frame.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FrostyTrees.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FtBraggOcean.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(50, 255, 80);
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GardenStair.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Geometric1.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GoldenGateBridge.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GoldenTreeLine.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GoldVein.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GossamerButterfly.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = RGB565(255, 50, 25); pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenHorse.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenMarquee.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenMist.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenRocks.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenTrail.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenTreeRoad.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenWaterfall.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Halloween.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Hearth.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Heather.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(200, 0, 200);
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/HotAirBalloons.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/HotPink.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_BLUE;
  pInfo[BGPic].tColor = TFT_BLUE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_BLUE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/IntenseBlue.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/IntenseRed.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/JapaneseMellow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/JustFish.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Justice.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/KidRainbow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LeafDrops.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LeafRipples.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Library.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LightStreak.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Lilypads.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LitMushrooms.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Marshmallows.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(255, 50, 25);
  pInfo[BGPic].tColor = TFT_BLUE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREEN; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Meadow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_PINK;
  pInfo[BGPic].tColor = TFT_PINK; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Meadow2.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MellowGold.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MeteorShower.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MilkyWay.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_BLUE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MilkyWay2.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MistyFullMoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MistySunset.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREEN;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREEN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MistyValley.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREEN;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Moon1.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MoonCastle.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MusicNotes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = RGB565(255, 50, 25); pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OilSlick.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeBlur.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = TFT_BLUE ;
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeCircles.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeGeo.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeMoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeSun.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeTown.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OtherWorld.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Outhouse.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PaintedSky.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PaintSplats.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREEN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PartEclipse.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PhantomFlower.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkBalls.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkBubbles.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkClouds.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkFlowers.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkPurple.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkRoses.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Plasma.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychButterfly.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychCamera.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychMeteors.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychMountains.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychNotes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychPaisley.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychRecord.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychSky.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = TFT_GREEN;
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychVortex.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsycodelicNotes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleBramble.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleButterfly.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleFlowers.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleGossamer.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleHeather.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(50, 255, 80);
  pInfo[BGPic].tColor = RGB565(50, 255, 80); pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = RGB565(50, 255, 80); pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleLeaves.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = RGB565(255, 0, 80); pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = RGB565(255, 0, 80); pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleLightning.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleOrbs.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleSunset.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Radiance.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Radiance2.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Radiance3.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RainyStreet.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RBExplosion.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedandYellow.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = RGB565(80, 80, 255); pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedChurch.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedConcave.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedGoldPath.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedLeaves.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedTracks.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREEN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Redwoods.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RightChevron.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RockStream.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Sailboat.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Seagull.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Sepia.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ShyFlowers.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SnowTree.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SomeLeaves.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SpaceStation.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SpaceTiger.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Spectral.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = RGB565(255, 50, 25);  pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Spikes.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Spiral.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Spirals.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Spirals2.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SS1.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/StarBurst.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/StuffedAnimals.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SunsetSky.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SydneyOpera.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/TanFlowers.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/TeddyBear.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Tiger.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Traces.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Tulips.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/TwoTrees.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Violets.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(172, 255, 0); // Bright yellowish green
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WarpSpeed.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Waterfall.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WaterLeaves.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WetWalk.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WetDaisy.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WildArt.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WolfMoon.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/XmasVillage.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/YellowOrangeSwirl.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(80, 180, 255);
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/YellowWash.jpg");
  if (veriPix) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREEN;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_BLUE; pInfo[BGPic++].dHatch = false;  // Date Hatch
}
