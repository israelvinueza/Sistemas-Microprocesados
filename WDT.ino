//UNIVERSIDAD TÉCNICA DEL NORTE
//          FICA
//         CIERCOM
// SISTEMAS MICROPROCESADOS

// ISRAEL VINUEZA
//  04/02/2020

#include <avr/wdt.h>
#include <EEPROM.h>
#include <TimerOne.h>
String tiempo;
int cont = 0;
int on = 0;
int in = 0;
void setup() {
  Serial.begin(9600);
  attachInterrupt(0, select, LOW);
  attachInterrupt(1, inicio, LOW);
  Serial.println("Watch Dog");
  Serial.println("Presione el segudo boton para activar");
  Timer1.stop();
  cont = 0;
  in=0;
  tiempo=" ";
}
void loop() {
  if (on == 1) {
    if (Serial.available() > 0 ) {
      tiempo = Serial.readString();
      Timer1.initialize(1000000);
      Timer1.attachInterrupt(conteo);
    }
  }
}
void select() {
  switch (on) {
    case 0:
      Serial.println("Ingrese el tiempo");
      on++;
      break;
    case 1:
      Serial.println(" ");
      on = 0;
      break;

  }
}
void conteo() {
  cont++;
 if(in==1){
 if(tiempo=="A"){
     Serial.println(String(2-cont));
    }
    if(tiempo=="B"){
     Serial.println(String(3-cont));
    }
    if(tiempo=="C"){
     Serial.println(String(5-cont));
    }
    if(tiempo=="D"){
     Serial.println(String(9-cont));
    }
 }
}
void inicio() {
  in++;
  if (tiempo == "A" && in == 1) {
    Serial.println("Reinicio 1Seg");
    wdt_enable(WDTO_1S);
  }
  if (tiempo == "B" && in == 1) {
    Serial.println("Reinicio 2Seg");
    wdt_enable(WDTO_2S);
  }
  if (tiempo == "C" && in == 1) {
    Serial.println("Reinicio 4Seg");
    wdt_enable(WDTO_4S);
  }
  if (tiempo == "D" && in == 1) {
    Serial.println("Reinicio 8Seg");
    wdt_enable(WDTO_8S);
  }
}
