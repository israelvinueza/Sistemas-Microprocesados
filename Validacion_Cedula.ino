/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 *          FICA
 *         CIERCOM
 *   SISTEMAS MICROPROCESADOS
 *   
 *NOMBRE: ISRAEL VINUEZA

*/
int num1,num2,num3,num4,num5,num6,num7,num8,num9,num10;
String ced;
int tam;
int num_impar;
int num_par;
int total;
void setup() {
    Serial.begin(9600);
    Serial.println("Ingrese un numero de cedula valido:");
    Serial.println("Formato valido XXXXXXXXX-X ");
      Serial.println("");
}

void loop() {
  if(Serial.available()>0){
  ced=Serial.readString();
  Serial.println(ced);
  delay(200);
  tam=ced.length();
   if(tam ==11 && ced.charAt(9)== '-' ){
         Serial.println("");
    Serial.println("Usted ingreso:"+ced);
      Serial.println("");
  //Se extrae los numeros impares se multiplica x 2 si el numero resultante es mayor a 9 se le resta 9 al resultante
          num1=num1*2;
      if(num1>9){
        num1=num1-9;
        }
      num3=num3*2;
      if(num3>9){
        num3=num3-9;
        }  
      num5=num5*2;
      if(num5>9){
        num5=num5-9;
        }
      num7=num7*2;
      if(num7>9){
        num7=num7-9;
        }
     num9=num9*2;
      if(num9>9){
        num9=num9-9;
        }
  num_impar=num1+num3+num5+num7+num9;
  num_par=num2+num4+num6+num8;
  total=num_impar+num_par;
      
      if(num10==(total%10)|| num10==(10-total%10)){
        String digito_region = ced.substring(0,2);
        int region=digito_region.toInt();
        if( region >= 1 && region <=24 ){
          Serial.println("");
        Serial.println("La cedula: "+ced+ " es correcta");
         Serial.println (" Ingrese un nuevo numero de cedula para validar ");
           Serial.println("");
        }
        else{
            Serial.println("");
           Serial.println("La cedula ingresada es incorrecta");
          Serial.println (" La cedula no pertenece a ninguna Region del Ecuador ");
            Serial.println("");
        }
        }
        else{
            Serial.println("");
          Serial.println("La cedula ingresada no es valida");
               Serial.println("");
          }
  } 
     else{
        Serial.println("");
      Serial.println("La cedula ingresada no es valida");   
           Serial.println("");
         }  
             if (ced.length() < 10) {
    Serial.println("");
    Serial.println("La cedula ingresada tiene menos de 10 digitos");
    Serial.println("Ingrese nuevamente el numero de cedula");
         Serial.println("");
    delay(300);
}
    if (ced.length() > 11) {
    Serial.println("");
    Serial.println("La cedula ingresada tiene mas de 10 digitos");
    Serial.println("Ingrese nuevamente el numero de cedula");
         Serial.println("");
    delay(300);
   }    
    }
 
  } 
