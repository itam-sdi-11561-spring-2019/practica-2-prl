int led= 52;
int band = 0;

void setup() {
  pinMode(led, OUTPUT);
  cli();
  TCCR1B = 0; TCCR1A = 0;
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  TCNT1 = 57724;
  TIMSK1 |= (1 << TOIE1);
  sei();

}
ISR(TIMER1_OVF_vect)
{
  if(band == 0){
    digitalWrite(led, HIGH);
    band =1;
  }else{
    digitalWrite(led, LOW);
    band = 0;
  }
  TCNT1 = 57724;
  
}

void loop() { 
 
}
