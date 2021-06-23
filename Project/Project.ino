extern volatile unsigned long timer0_millis;

#include <DHT11.h>
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

#define MiddleSwitch 10
#define LeftSwitch 11
#define RightSwitch 9
#define DHTPin A1
#define speedPin 2
#define LEDR 13
#define LEDG 12
#define BUTTON 3

DHT11 dht11(DHTPin);

LiquidCrystal_I2C lcd(0x27,16,2);

RTC_DS1307 RTC;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday"};

static int InterfaceCount = 1;
static int automaticCount = 0;

unsigned long past = 0;
int flag = 0;
unsigned long time = millis();

float temp, humi;
int err;

int measurePin = A0;
int ledPower = 6;

int Raindrops_pin = A2;

int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;

float voMeasured = 0.0;
float calcVoltage = 0.0;
float dustDensity = 0.0;

void InterfaceOn();

void LetStart();

void setup() {
   Serial.begin(9600);

  Wire.begin();

  //RTC.adjust(DateTime(F(__DATE__),F(__TIME__))); 

  RTC.begin();
  if(! RTC.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if(! RTC.isrunning()) {
    Serial.println("RTC is NOT running");
  }

  lcd.begin();
  lcd.backlight();
  pinMode(LeftSwitch,INPUT_PULLUP);
  pinMode(MiddleSwitch,INPUT_PULLUP);
  pinMode(RightSwitch,INPUT_PULLUP);
  pinMode(ledPower,OUTPUT);
  pinMode(Raindrops_pin, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG,OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  LetStart();
}

void Time() {
  DateTime now = RTC.now();
  int Day = now.day();
  time = millis();
  if(time - past >= 1000) {
    past = time;
    flag = 1;
  }
  if(digitalRead(LeftSwitch) == 0 || digitalRead(RightSwitch) == 0) {
    InterfaceOn();
  }
  if(digitalRead(MiddleSwitch) == 0) {
    lcd.clear();
  lcd.print(now.year(), DEC);
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(Day);
  lcd.setCursor(0,1);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  delay(3000);
  }
  if(flag == 1) {
  lcd.clear();
  lcd.print("Now time is:");
  lcd.setCursor(0,1);
  lcd.print(now.hour(),DEC);
  lcd.print(":");
  lcd.print(now.minute(),DEC);
  lcd.print(":");
  lcd.print(now.second(),DEC);
  flag = 0;
  Time();
  }
  else {
    Time();
  }
}

void function();

void function_RaindropsModule() {
  flag = 0;
  time = millis();
  if(time - past >= 2000) {
    past = time;
    flag = 1;
  }
  if(digitalRead(MiddleSwitch)==0) {
    delay(300);
    past = 0;
    timer0_millis = 1000;
    function();
  }
  if(flag==1) {
    lcd.clear();
    if(analogRead(A2)<500 && analogRead(A2)>400) {
      lcd.print("Very small rain");
    }
    else if(analogRead(A2)<401 && analogRead(A2)>350) {
      lcd.print("small Rain");
    }
    else if(analogRead(A2)<351 && analogRead(A2)>300) {
      lcd.print("middle Rain");
    }
    else if(analogRead(A2)<301 && analogRead(A2)>250) {
      lcd.print("much rain");
    }
    else if(analogRead(A2) <250) {
      lcd.print("Rainning");
      lcd.setCursor(0,1);
      lcd.print("Cats and dogs");
    }
    else {
      lcd.print("It's sunny! :)");
    }
    flag = 0;
    function_RaindropsModule();
  }
  else {
    function_RaindropsModule();
  }
}

void function_PMSensor() {
  flag = 0;
  time = millis();
  if(time - past >= 2000) {
    past = time;
    flag = 1;
  }
  if(digitalRead(MiddleSwitch)==0) {
    delay(300);
    past = 0;
    timer0_millis = 2000;
    function_RaindropsModule();
  }
  if(flag == 1) {
  digitalWrite(ledPower,LOW);
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin);
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH);
  delayMicroseconds(sleepTime);

  calcVoltage = voMeasured * (5.0/1024.0);

  dustDensity = 0.17 * calcVoltage - 0.1;

  lcd.clear();
  lcd.print("DustDensity: ");
  lcd.setCursor(0,1);
  lcd.print(dustDensity);
  lcd.print("(mg/m^3)");
  flag = 0;
  function_PMSensor();
  }
  else {
    function_PMSensor();
  }
}

void function_DHT11() {
  flag = 0;
  time = millis();
  if(time - past >= 3000) {
    past = time;
    flag = 1;
  }
  if(digitalRead(MiddleSwitch)==0) {
    delay(300);
    past = 0;
    timer0_millis = 2000;
    function_PMSensor();
  }
  if(flag == 1) {
  lcd.clear();
  if((err=dht11.read(humi, temp))==0) {
    lcd.print("temp: ");
    lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print("humi: ");
    lcd.print(humi);
    flag = 0;
  }
  else {
    lcd.print("Error No:");
  }
  function_DHT11();
  }
  else {
  function_DHT11();
  }
}

void function() {
  flag = 0;
  time = millis();
  if(time - past >= 1000) {
    past = time;
    flag = 1;
  }
  if(digitalRead(LeftSwitch) == 0 || digitalRead(RightSwitch) == 0) {
    InterfaceOn();
  }
  if(digitalRead(MiddleSwitch)==0) {
    past = 0;
    timer0_millis = 3000;
    delay(300);
    function_DHT11();
  }
  if(flag == 1) {
  lcd.clear();
  lcd.print("Function Mode");
  flag = 0;
  function();
  }
  else {
    function();
  }
}

void automatic() {
  past = 0;
  flag = 0;
  time = millis();
  if(digitalRead(LeftSwitch) == 0 || digitalRead(RightSwitch) == 0) {
    delay(300);
    InterfaceOn();
  }
  if(digitalRead(MiddleSwitch)==0) {
    delay(300);
    if(automaticCount == 0) {
      automaticCount++;
    }
    else if(automaticCount == 1) {
      automaticCount--;
    }
  }
  if(time - past >= 1000) {
    past = time;
    flag = 1;
  }
  if(flag == 1){
    if(automaticCount == 1) {
      lcd.clear();
      lcd.print("automatic ON"); 
    }
    else if(automaticCount == 0) {
      lcd.clear();
      lcd.print("automatic OFF");
    }
    flag = 0;
  }
  if(automaticCount == 1) {
      digitalWrite(ledPower,LOW);
      delayMicroseconds(samplingTime);

      voMeasured = analogRead(measurePin);
      delayMicroseconds(deltaTime);
      digitalWrite(ledPower,HIGH);
      delayMicroseconds(sleepTime);

      calcVoltage = voMeasured * (5.0/1024.0);

      dustDensity = 0.17 * calcVoltage - 0.1;
      if(dustDensity > 0.10 || analogRead(A2) < 500) {
        digitalWrite(LEDG, LOW);
        digitalWrite(LEDR, HIGH);
      }
    else if(digitalRead(LEDR) == 1 && analogRead(A2) >500 && dustDensity < 0.10 ) {
      digitalWrite(LEDG, HIGH);
      digitalWrite(LEDR, LOW);
      
      }
    else {
      digitalWrite(LEDG, HIGH);
    }
  }
  else if(automaticCount == 0) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, LOW);
  }
    
  else {
    automatic();
  }
}

void InterfaceOn() {
  if(digitalRead(LeftSwitch) == 0) {
    delay(300);
    InterfaceCount++;
  }
  else if (digitalRead(RightSwitch) == 0){
    delay(300);
    InterfaceCount--;
  }
  if(InterfaceCount>3) {
    InterfaceCount = 1;
  }
  else if(InterfaceCount < 1) {
    InterfaceCount = 3;
  }
   /*if(flag == 1) { //테스트 용 LCD 출력
  lcd.clear();
  lcd.print("Loading...");
  lcd.setCursor(0,1);
  lcd.print(count);
  }*/
  if(InterfaceCount == 1) {
   past = 0;
   timer0_millis = 1000;
   Time();
  }
  else if(InterfaceCount==2){
   past = 0;
   timer0_millis = 1000;
   function();
  }
  else if(InterfaceCount==3){
   past = 0;
   timer0_millis = 1000;
   automatic();
  } 
  InterfaceOn();
} 

void first() {
  lcd.print("Hello! Welcome!");
  delay(1000);
  lcd.clear();
  lcd.print("The right button");
  lcd.setCursor(0,1);
  lcd.print("Change the mode");
  delay(2000);
  lcd.clear();
  lcd.print("The left button");
  lcd.setCursor(0,1);
  lcd.print("change previous");
  delay(2000);
  lcd.clear();
  lcd.print("Middle button");
  lcd.setCursor(0,1);
  lcd.print("See all function");
  delay(2000);
  lcd.clear();
  lcd.print("Ok, so let's go!");
  delay(1000);
  InterfaceOn();
}
void start() {
  if(digitalRead(BUTTON)==1) {
    first();
  }
  else
 {
  lcd.print("Welcome back! :)");
  delay(2000);
  InterfaceOn();
 }
}

void LetStart() {
  start();
}

void loop() {
  
}
