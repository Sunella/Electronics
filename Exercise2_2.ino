int led[] = {5,6,7,8,9,10,11,12};
int button = 2;
long strt, stp;
int i;
int k =0;//iterator
int wait = 50;

int state = LOW;
int reading;
int previous = HIGH;

long time = 0;
long debounce = 200;

void setup() {
  Serial.begin(9600);
  {
  for(i=0; i<8; i++){
    pinMode(led[i],OUTPUT);
  }
  pinMode(button, INPUT);
}
}

void loop() {
  //strt = millis();
  reading = digitalRead(button);
  if(reading == HIGH && previous == LOW && (millis() - time) > debounce) {
    if(state == HIGH){
      state = LOW;
    }else{
      state = HIGH;
    }
    time = millis();
  }
  if(state == HIGH){
    showBinary(k);
    delay(100);
    k++;
  }
  previous = reading;
  if(k==256){
    stp = millis();
    Serial.print("Time it took to iterate: ");
    Serial.println(stp - strt);
    delay(5000);
    k = 0;
  }
}

void showBinary(int n){
  Serial.println(n);
 for(int j=0; j<8;j++){
   if (n%2){
     digitalWrite(led[j],HIGH);
   }else{
      digitalWrite(led[j],LOW);
   }
    n=n/2;
  }
}
