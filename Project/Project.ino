#include <DHT11.h>
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

#define MiddleSwitch 10
#define LeftSwitch 11
#define RightSwitch 9
#define DHTPin 12

DHT11 dht11(DHTPin);

LiquidCrystal_I2C lcd(0x27,16,2);

RTC_DS1307 RTC;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday"};

static int firstCount = 1;
static int InterfaceCount = 1;
static int functionCount = 1;

unsigned long past = 0;
int flag = 0;
unsigned long time = millis();

float temp, humi;
int err;

void InterfaceOn();

void LetStart();

void setup() {
   Serial.begin(9600);

  Wire.begin();

  RTC.adjust(DateTime(F(__DATE__),F(__TIME__))); 

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

void function_DHT11() {
  lcd.clear();
  if((err=dht11.read(humi, temp))==0) {
    lcd.print("temp: ");
    lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print("humi: ");
    lcd.print(humi);
  }
  else {
    lcd.print("Error No:");
  }
  delay(5000);
  function_DHT11();
}

void function() {
  past = 0;
  flag = 0;
  time = millis();
  if(time - past >= 1000) {
    past = time;
    flag = 1;
  }
  lcd.clear();
  if(digitalRead(LeftSwitch) == 0 || digitalRead(RightSwitch) == 0) {
    InterfaceOn();
  }
  if(digitalRead(MiddleSwitch)==0) {
    delay(300);
    function_DHT11();
  }
  if(flag == 1) {
  lcd.print("Function Mode");
  flag = 0;
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
    InterfaceOn();
  }
  if(time - past >= 1000) {
    past = time;
    flag = 1;
  }
  if(flag == 1){
  lcd.clear();
  lcd.print("automatic ON");
  flag = 0;
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
   Time();
  }
  else if(InterfaceCount==2){
   function();
  }
  else if(InterfaceCount==3){
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
  firstCount++;
  InterfaceOn();
}
void start() {
  if(firstCount == 0) {
    first();
  }
  else
 {
  lcd.print("Welcome back!");
  delay(2000);
  InterfaceOn();
 }
}

void LetStart() {
  start();
}

void loop() {
  
}
