#define LED 3
#define Input 2

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(Input, INPUT);

}

void loop() {
  int sw_in;
  sw_in = digitalRead(Input);
  if(sw_in == HIGH) {    // 그라운드랑 디지털 회로랑 연결이 되어있는데, 스위치 작동시 5V전력이 풀다운 저항으로 인해 그라운드와 디지털 회로 동시에 전력이 들어가 HIGH로 입력받음
    digitalWrite(LED, HIGH);
    delay(1000);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
