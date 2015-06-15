//I2C slave code
//Serial Data bus (SDA) = A4
//Serial Clock (SCL) = A5
#include<Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(5);
  //Wire.onReceive(react);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.onReceive(react);
}
  
void react(int n){
  while(Wire.available()){
    char c = Wire.read();
    if(c == 'H'){
      digitalWrite(13,HIGH);
    }else if(c == 'L'){
      digitalWrite(13,LOW);
    }
  }
}



