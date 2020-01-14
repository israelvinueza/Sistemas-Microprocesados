#include <Keypad.h>    
#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11,10, 9, 8);
const byte fila = 4;     
const byte colum = 4;    
char keys[fila][colum] = {    
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinFila[fila] = {A0, A1, A3,A4}; 
byte pinColum[colum] = {7, 6, 5, 4}; 
Keypad teclado = Keypad(makeKeymap(keys), pinFila, pinColum, fila,colum); 
char boton;
String dato ;
int val = 0;
int i = 0;
void setup() {
  MsTimer2::set(2000, lectura);
  MsTimer2::start();
  lcd.begin(16,2);
  lcd.print("INGRESE VALOR:");
  lcd.setCursor(0, 1);
}

void loop() {
  boton = teclado.getKey();
  if (boton) {
    if (boton == 'A' || boton == 'B' || boton == 'C' || boton == '#' || boton == '*') {
      i = 1 - i;
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(9, 1);
      lcd.print("       ");
      lcd.setCursor(0, 0);
      lcd.print("INICIO CONTEO");
    }
    else if (boton== 'D') {
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("RESETEO");
      delay(2000);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("INGRESE VALOR:");
      lcd.setCursor(0, 1);
      boton = ' ';
      dato=" ";
      i = 0;
      val = 0;
    }
    else {
      lcd.print(boton);
      dato = dato + boton;
    }
    val = dato.toInt();
  }
}
void lectura() {
  if (i == 1 ) {
    if (val > 0) {
      lcd.setCursor(9, 1);
      lcd.print("      ");
      lcd.setCursor(9, 1);
      lcd.print(val);
      val--;
    }
    else if (val == 0) {
      lcd.setCursor(9, 1);
      lcd.print("    ");
      lcd.setCursor(9, 1);
      lcd.print(val);
      lcd.setCursor(0, 0);
      lcd.print("                ");
    }
  }
}
