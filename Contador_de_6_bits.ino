#define btn
int leds[6]={8,9,10,11,12,13};
int i=0;
int var;
void setup() {
//pinMode(btn, INPUT);
for(;i<6;i++){
  
pinMode (leds[i], OUTPUT);
}
}
void loop() {

if (digitalRead(btn)==HIGH){ 
i++; 
if (i>127){ 
i=0; 
}
while(digitalRead(btn)==HIGH) {
  
  }
}
var=i; 
for(int i=2; i<=7; i++){ 
digitalWrite(leds[i], var%2);
var=var/2; 
}
}
