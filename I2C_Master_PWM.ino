#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {

  setPWM(1, 9, 50);  
  setPWM(1, 10, 100);  
  setPWM(1, 11, 200); 
  setPWM(2, 13, 50); 
  Serial.println("oke");
  delay(1000);
  setPWM(1, 9, 0);  
  setPWM(1, 10, 0);  
  setPWM(1, 11, 0);
  setPWM(2, 13, 0);
  Serial.println("oke juga");
  delay(1000);
  setPWM(1, 9, 255);  
  setPWM(1, 10, 255);  
  setPWM(1, 11, 255);
  setPWM(2, 13, 255);
  Serial.println("oke juga banget");
  delay(1000);
}


