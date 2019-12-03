  //UNIVERSIDAD TÉCNICA DEL NORTE
              //FICA
           //CIERCOM
    //SISTEMAS MICROPROCESADOS
//Israel Vinueza
//02/12/2019

String dato;
int contador=7;
int i=0;
int j=0;
int z=0;
int y=0;
int leds []={2,3,4,5,6,7};
void setup() {
 for (; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
    
  }
  Serial.begin(9600);
    Serial.println("Ingrese un comando de luces:");
     Serial.println("1. ACBF : Se enciende luces de manera ascendete");
      Serial.println("2. ACGF : Se eciende las luces en pocisiones impares");
       Serial.println("3. ADBF : Se eciende ls luces de forma ascendente y descendente");
        Serial.println("4. ADBH : Se enciende las luces de manera ascendende de 3 en 3");
        delay(200);
}

void loop() {
  if(Serial.available()>0){
    dato=Serial.readString();
    Serial.println(dato);
    delay(400);
    
if(dato=="ACBF"){
     for(i=j;i<contador;i++){
     digitalWrite(leds[i],HIGH);
      delay(100);
      digitalWrite(leds[i],LOW);  
       delay(100);
  
}
}
if(dato=="ACGF"){
          for(i=7;i>=0;i=i-2){
         digitalWrite(leds[i],HIGH);
           delay(200);
          digitalWrite(leds[i],LOW);  
          delay(200);
}  
}

if(dato=="ADBF"){
          for(int w=0;w<contador;w++){
           digitalWrite(leds[w],HIGH);
           delay(50);
           digitalWrite(leds[w],LOW);   
}
        for(int w=contador-1;w>=0;w--){
         digitalWrite(leds[w],HIGH);
         delay(50);
         digitalWrite(leds[w],LOW);   
}
        for(int w=0;w<contador;w++){
       digitalWrite(leds[w],HIGH);
       delay(50);
       digitalWrite(leds[w],LOW);   
}
      for(int w=contador-1;w>=0;w--){
      digitalWrite(leds[w],HIGH);
       delay(50);
       digitalWrite(leds[w],LOW);   
}
}

if(dato=="ADBH"){
        for(z=0;z<contador;z++){
        y=z-2;
       digitalWrite(leds[z],HIGH);
       delay(50);
        digitalWrite(leds[y],LOW); 
}
        for(z=contador-1;z>=0;z--){
        y=z;
        digitalWrite(leds[z],HIGH);
        delay(50);
        digitalWrite(leds[y],LOW); 
}
      for(i=0;i<8;i++){
       digitalWrite(leds[i],HIGH);
       digitalWrite(leds[7-i],HIGH);
       delay(500);
       digitalWrite(leds[i],LOW);  
       digitalWrite(leds[7-i],LOW); 
        delay(500);
}
}

}
}
