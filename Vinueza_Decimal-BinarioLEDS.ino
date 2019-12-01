  //UNIVERSIDAD TÉCNICA DEL NORTE
              //FICA
           //CIERCOM
    //SISTEMAS MICROPROCESADOS
//Israel Vinueza
//30/11/2019
float num;
int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
int num2;
void setup() {

  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
    
  }
  Serial.begin(9600);
    Serial.println("Ingrese un numero entre 0 y 255:");
}
void loop() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(leds[i], LOW);
  }
    delay(400);
  num = Serial.parseFloat();

  if (int(num) == num) {
    if (num >= 0 && num <= 255) {
      num2 = int(num);
      for (int i = 0; i < 8; i++) {
        if (num2 % 2 == 1) {
          digitalWrite(leds[i], HIGH);
        Serial.println(num);
        }
        else {
          digitalWrite(leds[i], LOW);

        }
        num2 = num2 / 2;
      }

    }

    else {
       Serial.println(num);
      Serial.println("El numero ingresado no es valido");
    }
  }
  else {
     Serial.println(num);
    Serial.println("Solo se permiten números enteros");
  }
  delay(4000);
}
