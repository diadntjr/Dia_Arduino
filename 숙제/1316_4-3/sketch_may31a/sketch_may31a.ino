int pin[] = {2,3,4,5,6,7,8,9};

void setup()
{
  Serial.begin(9600);
  for(int i = 0; i!=8; i++)  {
   pinMode(pin[i],OUTPUT);
  }
}

void loop()
{
  if(Serial.available()){
   int value1 = Serial.parseInt();
   int value2;
    value2 = ~value1;
   if(digitalRead(pin[value1]-1)==HIGH) {
      digitalWrite(pin[value1]-1,~(value1^value2));
    }
    else {
      digitalWrite(pin[value1]-1,value1);
    }
    
  }
}
