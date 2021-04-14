byte Pin[] = {2,3,4,5,6,7,8,9};
byte Pin_num = sizeof(Pin) / sizeof(byte);

void setup() {
  for(int i = 0; i < Pin_num; i++) {
    pinMode(Pin[i], OUTPUT);  
  }
}

void loop() {
  static int loc = 0;
  for(int i = 0; i < Pin_num; i++) {
    digitalWrite(Pin[i], LOW);
    }
    digitalWrite(Pin[loc], HIGH);
    loc++;
    loc %= 8;
    delay(250);
 }
