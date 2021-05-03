

void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
}

void loop() {
  if(Serial.available()) {
    long value1 = Serial.parseInt();

    if( value1 == 1) {
      digitalWrite(10, HIGH);
    }
    
    if( value1 == 0) {
      digitalWrite(10, LOW);
    }
  }

}
