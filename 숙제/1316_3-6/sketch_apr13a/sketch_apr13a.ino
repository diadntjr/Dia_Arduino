byte Pin[] = {2,3,4,5,6,7,8,9};
byte Pin_num = sizeof(Pin) / sizeof(byte);
int i = 2;

void setup() {
  for(int j = 0; j<Pin_num; j++) {
    pinMode(Pin[j], OUTPUT); 
  }
}

void loop() {
  if(i==9) {
    while(1) {
      if(i==2) {
        break;
      }
      digitalWrite(Pin[i-2], HIGH);
      delay(500);
      digitalWrite(Pin[i-2], LOW);
      i--;
    }
  }
  if(i==2){
    while(1) {
      if(i==9) {
        break;
      }
      digitalWrite(Pin[i-2],HIGH);
      delay(500);
      digitalWrite(Pin[i-2], LOW);
      i++;
    }
  }
}
