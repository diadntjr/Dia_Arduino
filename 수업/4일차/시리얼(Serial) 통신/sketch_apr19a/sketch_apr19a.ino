void setup() {
  Serial.begin(9600);

  Serial.println("start : ");
  Serial.println("Write data : ");

  Serial.write('A');
  Serial.write('\n');
  Serial.write(65);
  Serial.write('\n');
  Serial.write("Hello");
  Serial.write('\n');

  char str[] = {'W','o','r','l','d','\0'};
  Serial.write(str);
  Serial.write('\n');
  Serial.write(str,3); // Serial.write

  Serial.println(78);
  Serial.println(1.2346);
  Serial.println('N');
  Serial.println("Hello World!");

  Serial.println(78, BIN);
  Serial.println(78, OCT);
  Serial.println(78, DEC);
  Serial.println(78, HEX);

  Serial.println(1.12346, 0);
  Serial.println(1.12346, 2);
  Serial.println(1.12346, 4); // Serial.print
  
}

void loop() {
 

}
