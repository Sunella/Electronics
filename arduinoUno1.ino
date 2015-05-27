int latency=200;
int led[]={5,6,7,8,9,10,11,12};
unsigned int tStart, tStop;
int x;
void setup() {
  Serial.begin(9600);
  for (int i=0; i<8;i++){
    pinMode(led[i],OUTPUT);
  }}

void loop() {
  tStart=millis();
  for (int i=0;i<=x;i++){
      showBinary(i);
      delay(latency);
  }
  tStop=millis();
  Serial.println(tStop-tStart);
  delay(5000);
}
  
void showBinary(int n){
  Serial.println(n);
 for(int j=0; j<8;j++){
   if (n%2)
     digitalWrite(led[j],HIGH);
    else
      digitalWrite(led[j],LOW);
    n=n/2;
 }}
