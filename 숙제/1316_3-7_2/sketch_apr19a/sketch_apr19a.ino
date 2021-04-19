void setup() {
  for(int i =2; i<=3; i++) {
  pinMode(i, INPUT_PULLUP);
  }
  for(int i =4; i<=5; i++) {
  pinMode(i, OUTPUT);
  }
}

void loop() {
  int a,b;
  a = digitalRead(2);
  b = digitalRead(3);
  if(a == LOW) {
    digitalWrite(4, HIGH);
    delay(2000);
    digitalWrite(4, LOW);
  }
  if(b == LOW) {
    digitalWrite(5, HIGH);
    delay(2000);
    digitalWrite(5, LOW);
  }

}
