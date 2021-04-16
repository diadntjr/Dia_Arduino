#define RED 10
#define YELLOW 11
#define GREEN 12

byte Pin[] = {RED,YELLOW,GREEN};
byte Pin_num = sizeof(Pin) / sizeof(byte);

void setup() {
  for(int j = 0; j<Pin_num; j++) {
    pinMode(Pin[j], OUTPUT); 
  }
}

void loop() {
  analogWrite(RED,200);
  delay(1000);
  

}
