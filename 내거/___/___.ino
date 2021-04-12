#define redLight 8
#define yellowLight 7
#define greenLight 6

void setup() {
  pinMode(redLight,OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
}

void loop() {
  digitalWrite(redLight,HIGH);
  delay(1500);
  digitalWrite(redLight, LOW);
  digitalWrite(greenLight,HIGH);
  delay(3000);
  digitalWrite(greenLight, LOW);
  digitalWrite(yellowLight,HIGH);
  delay(1000);
  digitalWrite(yellowLight, LOW);
  
}
