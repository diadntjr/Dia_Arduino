#include <stdio.h>
byte Pin[] = {4,5,6,7,8,9,10,11};
byte Pin_num = sizeof(Pin) / sizeof(byte);
byte sendNumber = 0;
byte count = 0;
byte Pin_ON[] = {0,0,0,0,0,0,0,0};

void setup() {
  for(int j = 0; j<Pin_num; j++) {
    pinMode(Pin[j], OUTPUT); 
  }
}

int function(int receiveNumber) {
    for (int i = 7; i >= 0; i--) { 
        Pin_ON[i] = receiveNumber >> i & 1;
    }
    return 0;
}

int function2() {
   for(int i = 0; i < 8; i++) {
    if(Pin_ON[i] >= 1) {
      digitalWrite(i+4, HIGH);
      Pin_ON[i] = 0;
    }
    else {
      digitalWrite(i+4, LOW);
    }
  }
   delay(200);
  return 0;
}

void loop() {
  function(sendNumber);
  if(sendNumber == 255) {
    sendNumber = 0;
  }
  function2();
  sendNumber++;
}
