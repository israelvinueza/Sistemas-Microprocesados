int i;
int num=0; 
int var;  // se definen las variables
#define boton 8
int leds[6]={0,1,2,3,4,5};
void setup() {
 pinMode(boton, INPUT); // se toma boton como entrada
for(i=0;i<=6;i++){ 
pinMode(leds[i], OUTPUT); // salida de los leds
}
}
void loop() {
if (digitalRead(boton)==HIGH){ 
num++; // empieza el conteo de 1 en 1
if (num>63){ // si el numero es mayor a 63 
num=0; // vuelve a 0
}
while (digitalRead(boton)==HIGH){} //trabaja como un delay para evitar rebotes haciendo una pausa en los cambios.
}
var=num;
 
for(i=0; i<=6; i++){ 
digitalWrite(leds[i], var%2);// se muestran en los leds los residuos de la division por 2 para ver si led prendido o apagado.
var=var/2; //Se divide el cociente para 2 hasta que de 0 por cada ciclo del contador para obtener los valores binarios de los residuos.
}
}
