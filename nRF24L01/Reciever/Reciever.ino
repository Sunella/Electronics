//Recieve

#include<SPI.h>
#include<Mirf.h>
#include<nRF24L01.h>
#include<MirfHardwareSpiDriver.h>

String message;

int led = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"servl");
  Mirf.payload = 1;
  Mirf.config();
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte c;
  if(!Mirf.isSending() && Mirf.dataReady()){
    Mirf.getData(&c);
    char letter = char(c);
    if(letter == 'H'){
      digitalWrite(led,HIGH);
    }else if(letter == 'L'){
      digitalWrite(led,LOW);
    }
  }
}
