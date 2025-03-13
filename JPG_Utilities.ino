bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
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
bool spr_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
{
   // Stop further decoding as image is running off bottom of sprite
  if ( y >= spriteBG.height() ) return 0;

  // This function will clip the image block rendering automatically at the sprite boundaries
  spriteBG.pushImage(x, y, w, h, bitmap);

  // Return 1 to decode next block
  return 1;
}
