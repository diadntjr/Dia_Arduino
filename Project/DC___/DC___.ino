#define in3 10
#define in4 11
#define speedPin 10

void setup() {
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(speedPin,OUTPUT);
}

void loop() {
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(speedPin,150);
  delay(1000);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(1000);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(speedPin,150);
  delay(1000);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(1000);

}
