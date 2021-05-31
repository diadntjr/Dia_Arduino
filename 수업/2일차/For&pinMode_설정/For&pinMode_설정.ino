#define MaxLine 9

void setup() {
  for(int i = 2; i<=MaxLine; i++) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  for(int i = 9; i>=2; i--) {
    for(int j = 9; j>=2; j--) {
      if(i==j) {
        digitalWrite(j, HIGH);
      }
      else {
        digitalWrite(j, LOW);
      }
    }
    delay(50);
 }

}
