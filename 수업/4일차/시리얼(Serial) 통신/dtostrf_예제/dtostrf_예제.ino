void setup() {
  Serial.begin(9600);
  char temp[20];
  char buffer[20];
  int i = 133;
  float f = 32.4;
  char c = 'A';
  char str[] = "Hello";

  dtostrf(f,4,1,temp);
  sprintf(buffer, "%d, %s, %c, %s", i, temp, c, str);

  Serial.print(buffer);

}

void loop() {
  // put your main code here, to run repeatedly:

}
