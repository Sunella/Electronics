int led[] = {5,6,7,8,9,10,11,12};
int strt = 0;
int stp = 0;
int i;
int wait = 50;

void setup() {
  Serial.begin(9600);
  for(i=0; i<8; i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  /*
  for(int i=strt;i<=stp;i++){
      showBinary(i);
      delay(wait);
  }
  */
  while(Serial.available()){
    stp = Serial.parseInt();
  }
  if(stp>255){
    stp = stp%255;
  }
  if(stp>strt){
    for(i=strt;i<=stp;i++){
      showBinary(i);
      delay(wait);
    }
    strt = stp;
  }else if(stp<strt){
    for(i=strt;i<=255;i++){
      showBinary(i);
      delay(wait);
    }
    strt = 0;
    for(int i=strt;i<=stp;i++){
      showBinary(i);
      delay(wait);
    }
    strt = stp;;
  }
}

void showBinary(int n){
 for(int j=0; j<8;j++){
   if (n%2){
     digitalWrite(led[j],HIGH);
   }else{
      digitalWrite(led[j],LOW);
   }
    n=n/2;
  }
}
