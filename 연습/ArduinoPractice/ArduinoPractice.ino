void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    int a = Serial.parseInt();
    Serial.println(a);    
  }

}
