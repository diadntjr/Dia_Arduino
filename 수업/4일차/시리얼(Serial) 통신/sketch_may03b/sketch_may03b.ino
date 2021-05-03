void setup() {
  Serial.begin(9600);
  
  char c_data = 65;
  int i_data;

  i_data = c_data;

  Serial.println(c_data);
  Serial.println(i_data);

  Serial.println(int(c_data));
  Serial.println(char(i_data));
}

void loop() {
  // put your main code here, to run repeatedly:

}
