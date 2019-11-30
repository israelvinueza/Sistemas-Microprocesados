    //UNIVERSIDAD TÉCNICA DEL NORTE
              //FICA
           //CIERCOM
    //SISTEMAS MICROPROCESADOS
//Israel Vinueza
int dato;
int lectura;
#define led A3
int ult;
void setup() {
Serial.begin(9600);
pinMode(led,OUTPUT);
}
void loop() {
 if( Serial.available()>0)
  {
    lectura=Serial.readString().toInt();
    Serial.println(lectura);
  }
 dato=(analogRead(A0)*5.0)/(1023.0);
 dato = analogRead(0);
 Serial.println(String(analogRead(0)));
 delay(200);
 
if(ult>dato){
  digitalWrite(led, HIGH);
   Serial.println("Mayor valor del pin Análogo Digital");
   delay(100);
}else{
  digitalWrite(led, HIGH);  
}
}
