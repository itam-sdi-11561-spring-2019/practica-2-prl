void setup() {
 Serial.begin(9600);
  
}

void loop() {
  unsigned int var_out = 0;
  asm volatile (
            "ldi r24, 0 \n\t"
            "adiw r24,10 \n\t"
            "adiw r24,9 \n\t"
            "adiw r24,8  \n\t"
            "adiw r24,7 \n\t"
            "adiw r24,6 \n\t"
            "adiw r24,5 \n\t"
            "adiw r24,4  \n\t"
            "adiw r24,3 \n\t"
            "ldi r18, 0 \n\t"
            "ldi r22, 8 \n\t"
            "while: sub r24, r22 \n\t"
            "cpi r24, 0 \n\t"
            "brlt end \n\t"
            "inc r18  \n\t"
            "jmp while \n\t" 
            "end:mov %0, r18 \n\t" 
            
            : "=r" (var_out)
            );

            
      if(var_out == 6){
        Serial.print(var_out);
      }
       Serial.end() ;    

//  double prom = 0.0;
//  for(int i=10; i>2; i--){
//    prom+=i;
//  }
//  prom/=8;
//
//  Serial.print(prom);
//  Serial.end();
//  
  
}
