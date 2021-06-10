int Raindrops_pin = A2;  // 빗방울센서 핀을 A0으로 설정

 
void setup(){
  Serial.begin(9600);   // Serial monitor 전원 인가
  pinMode(A2 , INPUT);   // 빗방울 감지핀을 아날로그 입력으로 설정
}
 
void loop(){
 
  Serial.println(analogRead(A0));  // 센서값을 시리얼모니터로 전송
  delay(100);                       // 센서값 간격 0.1초로 설정
}
