  //UNIVERSIDAD TÉCNICA DEL NORTE
              //FICA
           //CIERCOM
    //SISTEMAS MICROPROCESADOS
//Israel Vinueza
//10/12/2019


int modos = 0;
int seleccion = 0;
String dato;
String cant;
int var,var2;

void setup() {
  attachInterrupt(digitalPinToInterrupt(2), on, LOW);
  attachInterrupt(digitalPinToInterrupt(3), selec, LOW);
  Serial.begin(9600);
    Serial.println("BIENVENIDO");
    Serial.println("Presione el boton 1 para iniciar");
}
void loop() {
orden();
}
void on() {
  switch (modos) {
    case 0:
      Serial.println("Presione boton 2 para un nuevo ingreso:");
      modos++;
      break;
    case 1:
      Serial.println("Numero ordenado:");
      modos++;;
      break;
    case 2:
     Serial.println("Ordenamiento finalizado presione 1 para ingresar un nuevo numero.");
      modos = 0;
      seleccion = 0;
      break;
      default:
      break;
  }
}
void selec() {
  if (modos == 1) {
    Serial.println("Escribir numero");
    seleccion++;
  }else{
     Serial.println("Opcion no permitida");
  }
}
void orden(){
if (seleccion == 1 && modos == 1) {
    if (Serial.available() > 0) {
      dato = Serial.readString();
      Serial.println("Numero ingresado:");
      Serial.println(dato);
      Serial.println("Presione el boton 1 para ordenar el numero");
    }
  }
  else if (modos == 2 && dato != "") {      
    int num[dato.length()];                 
    for (int i = 0; i < dato.length(); i++) {   
      cant = dato.substring(i, (i + 1));    
      num[i] = cant.toInt();                
    }
    do {                                   
      var = 0;
      for (int i = 0; i < dato.length(); i++) { 
        if (num[i] > num[i + 1]) {          
          var = 1;
          var2 = num[i];
          num[i] = num[i + 1];
          num[i + 1] = var2;
        }
      }
    }
    while(var);
    for (int i = 0; i < dato.length(); i++) { 
      Serial.print(num[i]);
    }
    Serial.println(" ");
    dato = "";
  }
}
