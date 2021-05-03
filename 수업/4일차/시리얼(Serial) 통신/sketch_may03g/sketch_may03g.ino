

void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
}

void loop() {
  if(Serial.available()) {
    long num = Serial.parseInt();
    Serial.write(num);

    if( num == '1') {
      digitalWrite(10, HIGH);
    }
    
    if( num == '0') {
      digitalWrite(10, LOW);
    }
  }

}
