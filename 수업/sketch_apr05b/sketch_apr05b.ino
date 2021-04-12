#define PIN_A 12
#define PIN_B 11
#define PIN_C 10

void setup() {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);

}

void loop() {
  digitalWrite(PIN_A, HIGH);
  delay(20);
  digitalWrite(PIN_A, LOW);
  digitalWrite(PIN_B, HIGH);
  delay(20);
  digitalWrite(PIN_B, LOW);
  digitalWrite(PIN_C, HIGH);
  delay(20);
  digitalWrite(PIN_C, LOW);

}
