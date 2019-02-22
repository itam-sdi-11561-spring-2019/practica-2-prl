int ledpin = 52;
int set_pin = 1;

void setup() {
  // put your setup code here, to run once:

  DDRB = DDRB | B00000001;

  Serial.begin(9600);
  asm volatile(
     "ldi r16, 0 \n\t"
     "ldi r18 , 0 \n\t"    
    );

    pinMode(ledpin, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  asm volatile( 
    "inc r16 \n\t"
    "brvc switch \n\t"
    "ldi r16, 0 \n\t"
    "clv \n\t"
    "sbis %0, %1 \n\t"
    "jmp high \n\t"
    "cbi %0, %1 \n\t"
    "jmp switch \n\t"
    "high: sbi %0, %1 \n\t"
    "switch: nop \n\t"
    : : "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB1) :
    );

     Serial.print(PORTB1);




}
