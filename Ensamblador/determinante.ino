void setup() {
 Serial.begin(9600);
  unsigned int var_out = 0;
  asm volatile (
            "ldi r16, 10 ;a \n\t"
            "ldi r17, 20 ;b \n\t"
            "ldi r18, 30 ;c \n\t"
            "mul r17, r17 ;b^2 \n\t"
            "movw r26, r0  \n\t"
            "mul r18, r16 ; ac \n\t"
            "lsl r0 ;2ac \n\t"
            "rol r1  \n\t"
            "lsl r0 ;4ac \n\t"
            "rol r1 \n\t"
            "sub r26, r0 ;b^2 - 4ac \n\t"
            "sbc r27,r1 \n\t"
            "movw %0, r26 \n\t"
            : "=r" (var_out)
            );
  if(var_out == -800){

    Serial.print("si");
  }else{
    Serial.print("no");
  }
  
  
}

void loop() {
//  int a=10;
//  int b=20;
//  int c=30;
//  Serial.print(b*b-4*a*c);
//  
  

}
