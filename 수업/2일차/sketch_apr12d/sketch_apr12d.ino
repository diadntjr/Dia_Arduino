#define LED 2
#define SW 3

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT);
}

void loop() {
  int sw_IN;
  sw_IN = digitalRead(SW);
  if(sw_IN == HIGH) {
    digitalWrite(LED, HIGH);
    delay(1000);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
