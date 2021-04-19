#define LED 3
#define Input 2

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(Input, INPUT_PULLUP); //아두이노 내부에서 풀업저항 기능 제공

}

void loop() {
  int sw_in;
  sw_in = digitalRead(Input);
  if(sw_in == LOW) {    
    digitalWrite(LED, HIGH);
    delay(1000);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
