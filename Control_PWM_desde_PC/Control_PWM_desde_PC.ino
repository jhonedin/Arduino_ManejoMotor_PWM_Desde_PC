/*
 * Autor: Jhon Edinson Blandon
 * Anio: 2021
 * Descripcion: Control de un motor DC simple por PWM desde un PC en 5 velocidades distintas.
 */
//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int motor=13;     //Declara Pin del motor
 
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
  Serial.begin(9600); //Inicia la comunicacion serial Arduino-PC
}
 
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{           //  cuando este energizado el Arduino
 
  // Si hay algun valor en la Consola Serial
  if (Serial.available()){
 
      //Variable donde se guarda el caracter enviado desde teclado
      char a = Serial.read();
 
      // Si el caracter ingresado esta entre 0 y 5
      if (a>='0' && a<='5'){ 
 
        //Variable para escalar el valor ingresado a rango de PWM
        int velocidad = map(a,'0','5',0,255);
        //Escritura de PWM al motor
        analogWrite(motor,velocidad);
        //Mensaje para el usuario
        Serial.print("El motor esta girando a la velocidad ");
        Serial.println(a);
 
      }else{ // Si el caracter ingresado NO esta entre 0 y 5
 
        //Mensaje para el usuario
        Serial.print("Velocidad invalida");
        Serial.println(a);
 
      }
 
  }
 
}
 
//Fin programa
