byte LED[] = {4,5,6,7,8,9,10,11};
byte Cur_LED = 0x00;

void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(LED[i],OUTPUT);
  }
  Serial.begin(9600);
  show_LED();
}

void loop(){
  if(Serial.available()) {
    Cur_LED = Serial.parseInt();
    Serial.println(Cur_LED);
    show_LED();
  }
}

void show_LED(void) {
  for(int i = 0; i<8; i++) {
    digitalWrite(LED[i], Cur_LED & (0x01 << i));
  }
 }
