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
    for (int i = 3; i >= 0; i--) { 
        Pin_ON[i] = receiveNumber >> i & 1;
    }
    return 0;
}

int function2() {
   for(int i = 0; i < 4; i++) {
    if(Pin_ON[i] >= 1) {
      digitalWrite(i+2, HIGH);
      Pin_ON[i] = 0;
    }
    else {
      digitalWrite(i+2, LOW);
    }
  }
   delay(1000);
  return 0;
}

void loop() {
  function(sendNumber);
  if(sendNumber == 16) {
    sendNumber = 0;
  }
  function2();
  sendNumber++;
}
