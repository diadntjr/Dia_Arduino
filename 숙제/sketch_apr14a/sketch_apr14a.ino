#include <stdio.h>
byte Pin[] = {2,3,4,5};
byte Pin_num = sizeof(Pin) / sizeof(byte);
byte sendNumber = 0;
byte count = 0;
byte Pin_ON[] = {0,0,0,0};

void setup() {
  for(int j = 0; j<Pin_num; j++) {
    pinMode(Pin[j], OUTPUT); 
  }
}

int function(int receiveNumber) {
  for (int i = 3; i >= 0; i--) { //8자리 숫자까지 나타냄
        Pin_ON[i] = receiveNumber >> i;
    }
  return 0;
}

void loop() {
  function(sendNumber);
  if(sendNumber == 16) {
    sendNumber = 0;
  }
  for(int i = 0; i<=4; i++) {
    if(Pin_ON[i] == 1) {
      digitalWrite(i+2, HIGH);
      delay(500);
      Pin_ON[i] = 0;
    }
    else {
      digitalWrite(i+2, LOW);
      delay(500);
    }
  }
  sendNumber++;
}
