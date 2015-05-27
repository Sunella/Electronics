int latency=200;
int led[]={5,6,7,8,9,10,11,12};
int tstart = 0;
int tstop = 0;
int inpt=2;
int x;
void setup() {
  Serial.begin(9600);
  for(int i=0;i<8;i++){
    pinMode(led[i],OUTPUT);
  }
  pinMode(inpt, INPUT);
}

void loop() {
  //boolean select=false;
  tstop = Serial.read();
  //if(){}
  //tStart=millis();
  for(int i=tstart; i<tstop; i++){
    if(tstop>255){
      i = 0;
      tstop = tstop - 255;
    }
    showBinary(i);
    delay(latency);
  }
  tstart = tstop;
  //tStop=millis();
  //Serial.println(tStop-tStart);
  //delay(5000);
}


void showBinary(int n){
  //tfSerial.println(n);
  for(int j=0;j<8;j++){
    if (n%2)
      digitalWrite(led[j],HIGH);
    else
      digitalWrite(led[j],LOW);
      n=n/2;
  }
}
