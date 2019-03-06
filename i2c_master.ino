void setPWM(uint8_t pin_number, uint8_t value){
  uint8_t address = ceil((float)((float)pin_number/(float)TOTAL_JUMLAH_PIN)*(float)JUMLAH_SLAVE_DEVICE);
  uint8_t actual_pin_number =  (JUMLAH_PIN_SETIAP_SLAVE - ((address * JUMLAH_PIN_SETIAP_SLAVE)-pin_number))+1;
  
  Wire.beginTransmission(address);  // transmit to device address
  Wire.write(actual_pin_number);           // sends one byte
  Wire.write(value);                // sends one byte
  Wire.endTransmission();           // stop transmitting  
}

//dikelompokkan 1 lampu 3 warna
void setRGB(uint8_t rgb_number, uint8_t r, uint8_t g, uint8_t b){
  setPWM((rgb_number*3)-2, r);  // RED
  setPWM((rgb_number*3)-1, g);  // GREEN
  setPWM(rgb_number*3, b);     // BLUE
}

//dikelompokkan 1 lampu 4 warna ==> RGBW
void setRGBW(uint8_t rgbw_number, uint8_t r, uint8_t g, uint8_t b, uint8_t w){
  setPWM((rgbw_number*4)-3, r);  // RED
  setPWM((rgbw_number*4)-2, g);  // GREEN
  setPWM((rgbw_number*4)-1, b);  // BLUE
  setPWM(rgbw_number*4, w);     // WHITE / pompa
}

//dikelompokkan 1 block
void setBLOCK(uint8_t start_pin_number, uint8_t jml_per_block, uint8_t val){
  for(int i=0; i<jml_per_block; i++){
    setPWM(i+start_pin_number, val);  // loop sampai jumlah per block
  }
}
