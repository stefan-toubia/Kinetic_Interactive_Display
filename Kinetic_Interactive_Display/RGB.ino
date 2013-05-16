uint32_t makeColor(int pos){
  uint8_t r, g, b;
  //r = (255/125)*pos;
  b=255;
  r = 255+(-255/MAX_STEPS)*pos;
  g = 0;
  
  
  return combineColor(r, g, b);
  
}

uint32_t combineColor(byte r, byte g, byte b){
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

void Color(){
  int i = 0;
  for (int y = 0; y < 3; y++){
    for (int x = 0; x < 3; x++){
      rgb.setPixelColor(i, 0, makeColor(pos[x][y]));
      rgb.setPixelColor(i, 1, makeColor(pos[x][y]));
      //rgb.setPixelColor(i, 0, 0xFF00FF);
      i++;
    }
  }
}
