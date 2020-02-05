

//UNIVERSIDAD TÉCNICA DEL NORTE
//          FICA
//         CIERCOM
// SISTEMAS MICROPROCESADOS

// ISRAEL VINUEZA
//  04/02/2020

#include<TimerOne.h>
#include<avr/sleep.h>
#include<avr/power.h>
#include <avr/wdt.h>
#include<EEPROM.h>
int conteo = 0;
int estado;

void setup() {
  Serial.begin(9600);
  estado = EEPROM.read(0);
  EEPROM.write(0, 1);
  attachInterrupt(0, wakeup, LOW);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(cont);
  set_sleep_mode(SLEEP_MODE_IDLE); 
  Serial.begin(9600);
  Serial.println(estado);
}
void loop() {
  activar();
  dormir();
}
void cont() {
  conteo++;
}
void wakeup() {
  sleep_disable();
  Serial.println("DESPIERTO");
  conteo = 0;
}
void activar() {
  if (cont == 2 ) {
    Serial.println("ACTIVO");
    Serial.println(conteo);
  }
}
void dormir() {
  if (cont == 4) {
    Serial.println("DORMIDO");
    EEPROM.update(0, 0);
    sleep_mode();
    sleep_enable();
  } if (conteo == 10) {
    sleep_disable();
    conteo = 0;
  }
}
