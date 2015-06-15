//Sender

#include<SPI.h>
#include<Mirf.h>
#include<nRF24L01.h>
#include<MirfHardwareSpiDriver.h>

void transmit(const char *string){
  byte c;
  for(int i=0; string[i]!=0x00; i++){
    c = string[i];
    Mirf.send(&c);
    while(Mirf.isSending());
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"servl");
  Mirf.payload = 1;
  Mirf.config();
}

void loop() {
  // put your main code here, to run repeatedly:
  transmit("H");
  delay(500);
  transmit("L");
  delay(100);
}
