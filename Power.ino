

//UNIVERSIDAD TÉCNICA DEL NORTE
//          FICA
//         CIERCOM
// SISTEMAS MICROPROCESADOS

// ISRAEL VINUEZA
//  04/02/2020

# include  < LowPower.h >
# include  < avr / wdt.h >
# include  < EEPROM.h >
# include < avr / sleep.h >
# include  < MsTimer2.h >
# include  < TimerOne.h >
# include  < avr / power.h >
# include  < LiquidCrystal.h >

LiquidCrystal lcd ( 13 , 12 , 11 , 10 , 9 , 8 );
int cont = 0 ;
int dato;
int lcdone = 8 ;
int num = EEPROM.read ( 0 );

 configuración nula () {
  Temporizador 1. inicializar ( 1000000 );
  Temporizador 1. attachInterrupt (conteo);
  power_all_enable ();
  lcd comenzar ( 16 , 2 );
  num = 0 ;
}

 bucle vacío () {
  De serie. println (num);
  dormir ();
  lcd setCursor ( 6 , 1 );
  lcd print ( " Tiempo: " + String (cont));
  dato = analogRead ( 0 );
  lcd setCursor ( 0 , 1 );
  lcd imprimir (dato);
}
vacío  conteo () {
  cont ++;
}

vacío  dormir () {
  if (cont == 5 ) {
    num = num + 1 ;
    lcd setCursor ( 0 , 0 );
    lcd imprimir ( " CAD INACTIVO " );
    power_adc_disable ();

  }
  if (cont == 8 ) {
    lcd setCursor ( 0 , 0 );
    lcd imprimir ( "                      " );
    lcd setCursor ( 0 , 0 );
    lcd imprimir ( " CX DESACTIVADO " );
    power_spi_disable ();
  }
  if (cont == 12 ) {
    lcd setCursor ( 0 , 0 );
    lcd imprimir ( "                     " );
    lcd setCursor ( 0 , 0 );
    lcd imprimir ( " INACTIVO " );
    power_all_disable ();
  }
  if (EEPROM. read ( 0 )> 12 ) {
    num = 0 ;
    power_all_enable ();
    EEPROM. escribir ( 0 , num);
    lcd claro ();
    lcd setCursor ( 0 , 0 );
    lcd imprimir ( " REINICIO " );
    lcd setCursor ( 0 , 1 );
    lcd imprimir ( " DEL SISTEMA " );
    digitalWrite (lcdone, HIGH);
    retraso ( 10 );
    wdt_enable (WDTO_1S);

  }
}
