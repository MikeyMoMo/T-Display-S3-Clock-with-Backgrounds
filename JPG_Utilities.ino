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
bool jpg_output_Sprite(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
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
bool jpg_output_tft(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
/*******************************************************************************************/
{
  // Stop further decoding as image is running off bottom of sprite
  if ( y >= tft.height() ) return 0;

  // This function will clip the image block rendering automatically at the sprite boundaries
  tft.pushImage(x, y, w, h, bitmap);

  // Return 1 to decode next block
  return 1;
}
/*******************************************************************************************/
void FillPixArray(bool showEm)
/*******************************************************************************************/
{
  /* Note:
      I started to change this to a struct build and load in the global area so the compiler
       could take care of this task but it meant that I would then have to write a routine to
       check that all of the pictures were there and that is already here controlled by the
       variable showEm.  So I will let this take a second and a half or 2 seconds each boot
       up.  Verifying all of the pix would probably take that long and is what probably makes
       this routine take that long because the little moves of values that are done here are
       really quick.  If I time test it some day, I will update this.  But I just decided to
       not take a lot of busywork time to change the format of this to allocate and load the
       struct and then have to check the files separately.  OK?  Thank you!

       P.S., The other reason is that I started it this way instead of loading the struct ovewr
             at the definition point and it is just too much eyestrain and brainstrain to
             change this over to the other way.  OK?  I'm done this time!
  */
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
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(5, 5, 5);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  // Blue Digital Graphic
  strcpy(pInfo[BGPic].picName, "Blue Digital Graphic");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(5, 5, 5);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  // Green Digital Graphic
  strcpy(pInfo[BGPic].picName, "Green Digital Graphic");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(5, 5, 5);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/AFriend.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/AFriend2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/AICalm.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE;
  pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/AliceWonder.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/AngrySun.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/AniForest.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Aquarium.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Arches.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/AutumnBlur.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Balloons.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BigBlueFlower.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BigRack.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BigSurf.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BirdFeather.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Birds.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlackHole.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlowIt.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueBlack.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Bluebonnets.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueBubbles.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueCity.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueEgg.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueExplosion.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueEyesCat.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueFlower.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueGold.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueGray.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueIceHouse.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueLagoon.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueMirror.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueMoon.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BluePurpleBlooms.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueRiverGreenTrees.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueShell.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueSkyTrees.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueSun.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueSwirl.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueSwirls.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueTesla.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueTree.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueTriangles.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueVanes.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueWaterfall.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueWhiteFlames.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlueWhiteRipples.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BlurryReflection.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BoatWharf.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Bower.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BrightForest.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Broadway.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BrooklynBridge.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BrownDesert.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BrownFence.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
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
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/BubblyBackground.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = RGB565(255, 50, 25);
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Butterflies.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Butterfly1.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ButterflyDaisy.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Cabanas.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Camelia.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CandyStretch.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CapitalBurning.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Carnations.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CherryBlossom2.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CherryBlossoms.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CherryTree.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ClearWater.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CloudTops.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CNTMoon.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Cockatoo.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColaBubbles.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColaBubbles2.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorBars.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorBoards.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorBubbles.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorClouds.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorCoins.jpg");
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorCubes.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorPetals.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorRays.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorStars.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorStars2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorStars3.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorStripes.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ColorSwirls.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Copper.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CopperOrbs.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CosmosBubbles.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Crescent.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Crimson.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CryptoMoon.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CrystalFlower.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/CyanGrassDew.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Daisys.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DarkFlower.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DarkLighthouse.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DarkLondon.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DarkTrees.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DataFlow.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DeepBlue.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DeepSea.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DeepSky.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DewBud.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DiagonalRainbow.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DigBlue.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DontKnow.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DontKnow1.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DotVortex.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Dover.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Driftwood.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/DryGround.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Earth.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Ejection.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Eyes.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(255, 50, 25);
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FairyFlys.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FallSunset.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FantasyIsland.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Feathers.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FerrisWheel.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Fiberglass.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FieldOfColor.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FireRainbow1.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = TFT_BLUE;
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch
  
  strcpy(pInfo[BGPic].picName, "/FireTown.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FireWing.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREEN;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREEN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FivePoints.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FizzCity.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FlameTree.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FletNix.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FloatingDirt.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FlowerWheel.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Frame.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FrostyTrees.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FtBraggOcean.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FutureCity.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FuzzyLights.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/FutureCity2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Galaxy.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GardenStair.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GayMist.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(50, 255, 80);
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Geometric1.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GoldenGateBridge.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GoldenTreeLine.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GoldLeaf.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GoldVein.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GossamerButterfly.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GossamerMoons.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Grass.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenBench.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenFlow.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenHorse.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenMarble.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenMarquee.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenMist.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(255, 50, 25);
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenRocks.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenSeeds.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenTrail.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenTreeRoad.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/GreenWaterfall.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Halloween.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Hearth.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Heather.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(200, 0, 200);
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/HighlightCity.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/HotAirBalloons.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/HotPink.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(200, 0, 200);
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Howling.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/HummingBird.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/IntenseBlue.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/IntenseRed.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/JapaneseMellow.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/JapanGateway.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/JapanStreetLight.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/JapanStreetLight1.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/JapanStreetLight2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/JustFish.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Justice.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/KidRainbow.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LeafDrops.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LeafRipples.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LEDMatrix.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Leopard.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Library.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LightStreak.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Lilypads.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LitMushrooms.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LonelyRed.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(0, 50, 255);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LongSpiral.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(0, 50, 255);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/LotsaRoof.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MardiGras.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Marshmallows.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MastHead.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Mayan.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Mayan1.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Meadow.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_RED; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = TFT_WHITE;
  pInfo[BGPic].dColor = TFT_RED; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Meadow2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MellowGold.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Menton.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE ;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Meteors.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MeteorShower.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Mickey.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MilkyWay.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREEN; pInfo[BGPic++].dHatch = false; // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MilkyWay2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MistHouse.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MistyFullMoon.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MistySunset.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREEN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MistyValley.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREEN;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MMs.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Monarch.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Moon1.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MoonCastle.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MoonTree.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MorePink.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MultiBright.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = true;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MushroomOwl.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = true;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = true;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MusicNotes.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/MustardField.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/NahNah.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/NeonSwirls.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Nips.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/NobodyHome.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/NorthernLights1.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/NorthernLights2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OddClouds.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OI04.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OI06.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OI07.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_PINK;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OI09.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OI11.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OI13.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OI14.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OI18.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OI19.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OI20.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OI21.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OilSlick.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OneSplash.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Oragami.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeBlast.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeBlur.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = TFT_BLUE ;
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeBubbles.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = TFT_BLUE ;
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeBubbles2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = TFT_BLUE ;
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeCircles.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeGeo.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeLeavesMoon.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeMoon.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeMoon2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeSun.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeSunset.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeTown.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OrangeVortex.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Osaka.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/OtherWorld.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Outhouse.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Owl.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Pagoda.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Pagoda2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PaintedSky.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PaintSplats.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Pansys.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PartEclipse.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PastelRipples.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PastelWaves.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PenguinMarch.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PhantomFlower.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkBalls.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = 0;
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkBubbles.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkClouds.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkFlower2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkFlowers.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_RED;  // RGB565(255, 50, 25);
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkGateway.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;  // RGB565(255, 50, 25);
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkGreen.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;  // RGB565(255, 50, 25);
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

   strcpy(pInfo[BGPic].picName, "/PinkHearts.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

 strcpy(pInfo[BGPic].picName, "/PinkLeaves.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;  // RGB565(255, 50, 25);
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkPurple.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkRoses.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkTesla.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PinkThings.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Plasma.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Players.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Prism.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PrismRabbit.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychBubbles.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychBubbles2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychButterfly.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychButterfly2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychCamera.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychClouds.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychDots.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychExplosion.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychFeathers.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychHills.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychLillypad.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychLiquid.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychMagma.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychMeteors.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychMountains.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychNotes.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychPaisley.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychPeacock.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychRecord.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychRichter.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychShip.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychSky.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychSmoke.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychSpiral.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychSplash.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychSwirls.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychVortex.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychWave.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsychYarn.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PsycodelicNotes.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleBramble.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleButterfly.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleFlowers.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleGossamer.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREEN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleGossamer2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleHeather.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(50, 255, 80);
  pInfo[BGPic].tColor = RGB565(50, 255, 80); pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = RGB565(50, 255, 80); pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleLeaves.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleLightning.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleLiquid.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleMorning.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleMountains.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleOrbs.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurplePlanet.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleRings.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleSpires.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleSunset.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PurpleSwirl.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/PyramidBalls.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Radiance.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;  // TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Radiance2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Radiance3.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RainyStreet.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RandomTiled.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RBExplosion.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedandYellow.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedBlack.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedBlueRocks.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedBoats.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedCabbage.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedChurch.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedConcave.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedFlower.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedGoldPath.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedLeaves.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedPalms.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedPath.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedPeaks.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedSpiral.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedSunset.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedTracks.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREEN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedTree.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedUmbrellas.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedWhite.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedWhiteStalks.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RedWhiteTiled.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Redwoods.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_GREEN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RightChevron.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Rings.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RockHoleOcean.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RockStream.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/RoseThorns.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Sailboat.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SaturnEclipse.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Seagull.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Sepia.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SepiaOutline.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ShyFlowers.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SimpGraf1.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SimpGraf2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SnowFlake.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false; // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SnowTree.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Soaring.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SomeLeaves.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Somewhere.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SpaceFlame.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SpaceStation.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SpaceTiger.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Spectral.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW;  pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SpectrumRibbon.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE;  pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Spikes.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Spiral.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SpiralBall.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Spirals.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Spirals2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SS1.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/StackedHouses.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/StarBurst.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/StarGate.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/StreamPath.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/StripedOrbs.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/StuffedAnimals.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Sunflowers.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SunsetSky.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SuperNova.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/SydneyOpera.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/TallFalls.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/TanFlowers.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/TeddyBear.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Tendrils.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ThreadFalls.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Tiger.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/TiledRoof.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Traces.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Trapezoids.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Tulips.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/TwoBirdsPink.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/TwoTrees.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/TypewriterKeys.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/UpAndAway.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/VanishingLibrary.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {  
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/VanishingPt.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/VeryRedLeaves.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/VeryRedRoses.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/ViewRoom.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Violets.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WarpSpeed.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WaterBower.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Waterfall.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_GREENYELLOW;
  pInfo[BGPic].tColor = TFT_GREENYELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_GREENYELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WaterfallLeaf.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WaterLeaves.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WaterLeaves2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WaterPots.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WaterPots2.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WaterSkyShack.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WaveRocks.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WeirdClouds.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WetDaisy.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WetWalk.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Wheels.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Wild1.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WildArt.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WildPurple.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WispyMoon.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WispySky.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WitchyTree.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WolfMoon.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/WorldRings.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/Worlds.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/XmasVillage.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = RGB565(255, 50, 25);
  pInfo[BGPic].tColor = TFT_YELLOW; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_YELLOW; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/YellowBlue.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/YellowButterfly.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/YellowGreen.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_WHITE;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/YellowLeaves.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_CYAN;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/YellowOrangeSwirl.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/YellowPainting.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/YellowWash.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_RED;
  pInfo[BGPic].tColor = TFT_WHITE; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_CYAN; pInfo[BGPic++].dHatch = false;  // Date Hatch

  strcpy(pInfo[BGPic].picName, "/YodaMaybe.jpg");
  if (showEm) Serial.printf("#%3i, Pic: %s\r\n", BGPic, pInfo[BGPic].picName);
  if (!LittleFS.exists(pInfo[BGPic].picName)) {
    Serial.print(pInfo[BGPic].picName); Serial.println(" does not exist.");
  }
  pInfo[BGPic].bColor = TFT_YELLOW;
  pInfo[BGPic].tColor = TFT_CYAN; pInfo[BGPic].tHatch = false;  // Time Hatch
  pInfo[BGPic].oColor = RGB565(255, 50, 25);
  pInfo[BGPic].dColor = TFT_WHITE; pInfo[BGPic++].dHatch = false;  // Date Hatch
}
