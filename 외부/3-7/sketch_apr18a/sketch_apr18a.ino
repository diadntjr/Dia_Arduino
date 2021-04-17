void setup(){

  pinMode(13, OUTPUT);

  pinMode(12, OUTPUT);

  pinMode(11, OUTPUT);

  pinMode(10, OUTPUT);

}

void loop(){
  byte num;
  for(num = 1; num <= 15; num++){
    if(num & 1) digitalWrite(10,HIGH);
    else        digitalWrite(10,LOW);
      
    if(num & 2) digitalWrite(11,HIGH);
    else        digitalWrite(11,LOW);
      
    if(num & 4) digitalWrite(12,HIGH);
    else        digitalWrite(12,LOW);
      
    if(num & 8) digitalWrite(13,HIGH);
    else        digitalWrite(13,LOW);
    
    delay(1000);      
  }
}
