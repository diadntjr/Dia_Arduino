byte Pin[] = {2,3,4,5,6,7,8,9};
byte Pin_num = sizeof(Pin) / sizeof(byte);

void setup() {
  for(int i = 0; i < Pin_num; i++) {
    pinMode(Pin[i], OUTPUT);  
  }
}

void loop() {
  for(int i = 0; i < Pin_num; i++) {
    for(int j = 0; j<Pin_num; j++) {
      if(i==j) {
        digitalWrite(Pin[j], HIGH);
      }
      else {
        digitalWrite(Pin[j], LOW);
      }
    }
    delay(50);
  }
}
