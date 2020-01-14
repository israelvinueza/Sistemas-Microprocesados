#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8); 
String dato;
String texto;
int i=0;
void setup() {
  lcd.begin(16,2);
  lcd.blink();
  Serial.begin(9600);
}
void loop() {
    lcd.setCursor(0,0);
  lcd.print("INGRESE TEXTO");
  dato = "";
  texto = "";
  lcd.print("                ");
  lcd.setCursor(0,0);
  if (Serial.available() > 0) {
    dato = Serial.readString();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    for (i = 0; i < dato.length()-1;i++)
    {
      texto = texto + dato.substring(i,i+1);
    }
    lcd.print(texto);
    delay(1000);
    for (i = 0; i < 16+texto.length(); i++) {
     lcd.scrollDisplayRight();
      delay(600);
    }
 }
}
