//I2C master code
//Serial Data bus (SDA) = A4
//Serial Clock (SCL) = A5
#include<Wire.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  while(true){
    Wire.beginTransmission(5);
    Wire.write('H');
    Wire.endTransmission();
    delay(500);
    Wire.beginTransmission(5);
    Wire.write('L');
    Wire.endTransmission();
    delay(100);
  }
}

