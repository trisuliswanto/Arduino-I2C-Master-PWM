

void setPWM(uint8_t address, uint8_t pin_number, uint8_t value){
  Wire.beginTransmission(address);  // transmit to device address
  Wire.write(pin_number);           // sends one byte
  Wire.write(value);                // sends one byte
  Wire.endTransmission();           // stop transmitting  
}
