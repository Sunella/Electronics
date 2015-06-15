int led[] = {5,6,7,8,9,10,11,12};
long strt, stp;
int i;
int wait = 50;

void setup() {
  Serial.begin(9600);
  for(i=0; i<8; i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  strt = millis();
  for(i=0; i<255; i++){
    showBinary(i);
    Serial.println(i);
    delay(wait);
  }
  stp = millis();
  Serial.print("Time it took to iterate: ");
  Serial.println(stp - strt);
  delay(5000);
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
