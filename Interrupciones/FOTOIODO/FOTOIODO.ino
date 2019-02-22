const int analogInPin = A1; // Pin analogico 1 para la lectura del Fototransistor

int sensorValue = 0;   // Inicializamos el valor del sensor 
int cont=0;

void setup() {
  // Inicializamos la comunicacion serial a 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // leemos el pin y asignamos el valor a la variable.
  sensorValue = analogRead(analogInPin);            
  
//   Si el valor obtenido es mayor a 900 se activa el LED
  if(sensorValue > 40)
  {
    cont++;
  }
  

  // Imprimimos el valor en el monitor.
  Serial.print("contador = " );                           
  Serial.println(cont);    
  Serial.println(sensorValue);

  delay(250);                     
}
