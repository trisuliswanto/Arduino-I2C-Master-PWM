#include <Wire.h>

#define JUMLAH_SLAVE_DEVICE 6
#define JUMLAH_PIN_SETIAP_SLAVE 9
#define TOTAL_JUMLAH_PIN  (JUMLAH_SLAVE_DEVICE * JUMLAH_PIN_SETIAP_SLAVE)
#define JUMLAH_MAX_RGB  (TOTAL_JUMLAH_PIN/3)
#define JUMLAH_MAX_RGBW  (TOTAL_JUMLAH_PIN/4)

#define SLAVE_START_ADDRESS 1   // alamat Slave pertama

void setup() {
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {

  //untuk kontrol per pin menggunakan fungsi setPWM
//nganan
  for(int i=1; i<=TOTAL_JUMLAH_PIN; i++){
    if(i-1 > 0) setPWM(i-1, 0);
    setPWM(i, 250);
    delay(50);
  }
  delay(500);
//ngiri
  for(int i=TOTAL_JUMLAH_PIN; i>=1; i--){
    setPWM(i, 250);
    if(i+1 <= TOTAL_JUMLAH_PIN) setPWM(i+1, 0);
    delay(50);
  }
  delay(500);

//Untuk animasi menggunakan fungsi setRGB
//nganan
  for(int i=1; i<=JUMLAH_MAX_RGB; i++){
    if(i-1 > 0) setRGB(i-1, 0,0,0);
    setRGB(i, 250, 250, 250);
    delay(50);
  }
  delay(500);
//ngiri
  for(int i=JUMLAH_MAX_RGB; i>=1; i--){
    setRGB(i, 250, 250, 250);
    if(i+1 <= JUMLAH_MAX_RGB) setRGB(i+1, 0,0,0);
    delay(50);
  }
  delay(500);

  //Untuk animasi menggunakan fungsi setRGBW
//nganan
  for(int i=1; i<=JUMLAH_MAX_RGBW; i++){
    if(i-1 > 0) setRGBW(i-1, 0,0,0,0);
    setRGBW(i, 250, 250, 250, 250);
    delay(50);
  }
  delay(500);
//ngiri
  for(int i=JUMLAH_MAX_RGBW; i>=1; i--){
    setRGBW(i, 250, 250, 250, 250);
    if(i+1 <= JUMLAH_MAX_RGBW) setRGBW(i+1, 0,0,0,0);
    delay(50);
  }
  delay(500);

  //nganan
  for(int i=1; i<=JUMLAH_MAX_RGBW; i++){
    setRGBW(i, 250, 250, 250, 250);
    delay(50);
  }
  delay(500);
//ngiri
  for(int i=JUMLAH_MAX_RGBW; i>=1; i--){
    setRGBW(i, 250, 250, 250, 250);
    if(i+1 <= JUMLAH_MAX_RGBW) setRGBW(i+1, 0,0,0,0);
    delay(50);
  }
  delay(500);


// animasi untuk satu block kelompok led
  uint8_t jumlah_per_block = 10;
//nganan
  for(int i=1; i<=TOTAL_JUMLAH_PIN; i+=jumlah_per_block){
    setBLOCK(i, jumlah_per_block, 250);
    if(i-jumlah_per_block >= 0) setBLOCK(i-jumlah_per_block, jumlah_per_block, 0);
    delay(50);
  }
  delay(100);
//ngiri
  for(int i=TOTAL_JUMLAH_PIN; i>=1; i-=jumlah_per_block){
    setBLOCK(i, jumlah_per_block, 250);
    if(i+jumlah_per_block <= TOTAL_JUMLAH_PIN) setBLOCK(i+jumlah_per_block, jumlah_per_block, 0);
    delay(50);
  }
  delay(100);  
}


