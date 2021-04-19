#define LED 3
#define Input 2

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(Input, INPUT);

}

void loop() {
  int sw_in;
  sw_in = digitalRead(Input);
  if(sw_in == LOW) {    // 기본적인 5V 전력이 스위치가 작동하지 않아도 이미 디지털 회로에 흘러 들어가고 있는데, 스위치 작동시 전력이 그라운드로 빠져 디지털 회로에는 전력이 안들어오기 때문
    digitalWrite(LED, HIGH);
    delay(1000);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
