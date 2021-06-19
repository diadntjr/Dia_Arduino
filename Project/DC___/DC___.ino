#define in3 4
#define in4 3
#define speedPin 2

void setup() {
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(speedPin,OUTPUT);
}

void loop() {
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(speedPin,50);
  delay(1000);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(1000);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(speedPin,50);
  delay(1000);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(1000);

}
