/*******************************************************************************************/
bool jpg_output_Sprite(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
/*******************************************************************************************/
{

  // This function is be called during decoding of the jpeg file to
  // render each block to the sprite spriteBG.  It us used to load all of the BG pictures.

  // Stop further decoding as image is running off bottom of sprite
  if ( y >= spriteBG.height() ) return 0;

  // This function will clip the image block rendering
  //  automatically at the sprite boundaries
  spriteBG.pushImage(x, y, w, h, bitmap);

  // Return 1 to decode next block
  return 1;
}
/*******************************************************************************************/
bool jpg_output_tft(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
/*******************************************************************************************/
{

  // This function is be called during decoding of the jpeg file to
  // render each block to the tft base display.  It is only used once, during setup().

  // Stop further decoding as image is running off bottom of sprite
  if ( y >= tft.height() ) return 0;

  // This function will clip the image block rendering automatically at the sprite boundaries
  tft.pushImage(x, y, w, h, bitmap);

  // Return 1 to decode next block
  return 1;
}
/*******************************************************************************************/
void printPixInfo()
/*******************************************************************************************/
{
  for (int i = 0; i < randSelections; i++) {
    Serial.print("Picture "); 
    printPicName(i, pInfo[i].picName);
  }
}
/*******************************************************************************************/
void printPicName(int picNo, const char *picName)
/*******************************************************************************************/
{
  // Check if the first character is '/'
  if (picName[0] == '/') picName++; // Move pointer forward to skip the '/'
  printf("#%3i: %s\n", picNo, picName);
}
