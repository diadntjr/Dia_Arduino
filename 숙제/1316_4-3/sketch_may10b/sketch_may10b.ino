void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  
  
}

void loop()
{
  if(Serial.available() ) {
 int value1 = Serial.parseInt();
  if(digitalRead(value1+9) ^ 1) {
    digitalWrite(value1+9,HIGH);
  }
  else {
    digitalWrite(value1+9,LOW);
  }
  }
}
