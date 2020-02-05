//UNIVERSIDAD TÉCNICA DEL NORTE
//          FICA
//         CIERCOM
// SISTEMAS MICROPROCESADOS

// ISRAEL VINUEZA
//  04/02/2020

#include <LowPower.h>
#include <avr/wdt.h>
#include <EEPROM.h>
#include<avr/sleep.h>
#include <MsTimer2.h>
#include <TimerOne.h>
#include <avr/power.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int cont = 0;
int dato;
int lcdone = 7;
int num = EEPROM.read(0);

void setup() {
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  power_all_enable();
  lcd.begin(16, 2);
  num = 0;
}

void loop() {
  Serial.println(num);
  dormir();
  lcd.setCursor(6, 1);
  lcd.print("Tiempo:" + String(cont));
  dato = analogRead(0);
  lcd.setCursor(0, 1);
  lcd.print(dato);
}
void conteo() {
  cont++;
}

void dormir() {
  if (cont == 5) {
    num = num + 1;
    lcd.setCursor(0, 0);
    lcd.print("CAD DESACTIVADO");
    power_adc_disable();

  }
  if (cont == 8) {
    lcd.setCursor(0, 0);
    lcd.print("                     ");
    lcd.setCursor(0, 0);
    lcd.print("CX DESACTIVADO");
    power_spi_disable();
  }
  if (cont == 12) {
    lcd.setCursor(0, 0);
    lcd.print("                    ");
    lcd.setCursor(0, 0);
    lcd.print("DESACTIVADO");
    power_all_disable();
  }
  if (EEPROM.read(0) > 12) {
    num = 0;
    power_all_enable();
    EEPROM.write(0, num);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("REINICIO");
    lcd.setCursor(0, 1);
    lcd.print("DEL SISTEMA");
    digitalWrite(lcdone, HIGH);
    delay(10);
    wdt_enable(WDTO_1S);

  }
}
