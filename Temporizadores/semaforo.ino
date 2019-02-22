int ledV = 52;
int ledA = 46;
int ledR = 48;
int cont = 0;

void setup() {
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledR, OUTPUT);
  
  cli();
  TCCR1B = 0; TCCR1A = 0;
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  TCNT1 = 49911;
  TIMSK1 |= (1 << TOIE1);
  sei();

  digitalWrite(ledR, HIGH);
}

ISR(TIMER1_OVF_vect)
{
  if(cont == 10){
    digitalWrite(ledR, LOW);
    digitalWrite(ledV, HIGH);
  }
  if(cont == 22){
    digitalWrite(ledA, HIGH);
  }
  if(cont == 25){
    digitalWrite(ledA, LOW);
    digitalWrite(ledV, LOW);
    digitalWrite(ledR, HIGH);
    cont=0;
  }
  TCNT1 = 49911;
  cont++;
}

void loop(){



























































































































































































































































  
}
