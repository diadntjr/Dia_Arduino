byte Pin[] = {2,3,4,5,6,7,8,9};
byte Pin_num = sizeof(Pin) / sizeof(byte);
int i =2;

void setup() {
  for(int i = 0; i<Pin_num; i++) {
    pinMode(Pin[i], OUTPUT); 
  }
}

void loop() {
  static int loc;
  if(i==8) {
    while(i==2) {
      loc = Pin[i];
      digitalWrite(loc, HIGH);
      delay(100);
      digitalWrite(loc, LOW);
      i--
    }
  }
  if(i==2){
    while(i==8) {
      loc = Pin[i];
      digitalWrite(loc, HIGH);
      delay(100);
      digitalWrite(loc, LOW);
      i++
    }
  }
}
