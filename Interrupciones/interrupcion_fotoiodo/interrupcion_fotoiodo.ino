int x=0;

void setup()
{
  //. Deshabilitar globalmente las interrupciones
  cli();
  //Establecer como entrada el puerto correspondiente
  DDRD &= ~(1 << DDD1);
  //Activar el bit de la interrupci´on en el puerto correspondiente
  PORTD |= (1 << PORTD1);
  //Establecer el tipo de interrupci´on 
  EICRA |= (1 << ISC10);
  //Habilitar la interrupci´on deseada en el registro de m´ascaras de interrupciones externas
  EIMSK |= (1 << INT1);
  //Habilitar globalmente las interrupciones
  sei();
  Serial.begin(9600);
}

void loop(){
  
}

//Declarar la funci´on ISR con el par´ametro correspondiente a la interrupci´on

ISR(INT1_vect)
{
  x++;
  Serial.println(x);\
}
