
int btn = 53;
int cont;
int st = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(btn, INPUT);
  cont =0;
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  st = digitalRead(btn);
  if(st == LOW){
    cont++;
  }

  Serial.println(cont);
}
