void setup() {
  Serial.begin(9600);
}

void loop() {
  static int i = 0;
  char str[20];
  sprintf(str, "%d-th value",i++);
  Serial.println(str);
  delay(500);
}
