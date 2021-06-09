#define MiddleSwitch 10
#define LeftSwitch 11
#define RightSwitch 9

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#include <Wire.h>

#include <RTClib.h>

RTC_DS1307 RTC;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday"};

static int firstCount = 1;
static int count = 1;

unsigned long past = 0;
int flag = 0;
unsigned long time = millis();

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

void function() {
  flag = 0;
  time = millis();
  if(digitalRead(LeftSwitch) == 0 || digitalRead(RightSwitch) == 0) {
    InterfaceOn();
  }
  /*if(time - past >= 1000) {
    past = time;
    flag = 1;
  }
  if(flag == 1) {*/
  delay(1000);
  lcd.clear();
  lcd.print("Function ON");
  function();
//}
}

void automatic() {
  flag = 0;
  time = millis();
  if(digitalRead(LeftSwitch) == 0 || digitalRead(RightSwitch) == 0) {
    InterfaceOn();
  }
  /*if(time - past >= 1000) {
    past = time;
    flag = 1;
  }
  if(flag == 1){*/
  delay(1000);
  lcd.clear();
  lcd.print("automatic ON");
  automatic();
//}
}

void InterfaceOn() {
  lcd.clear();
  lcd.print("Loading...");
  lcd.setCursor(0,1);
  lcd.print(count);
  delay(1000);
  if(digitalRead(LeftSwitch) == 0) {
    count++;
  }
  else if (digitalRead(RightSwitch) == 0){
    count--;
  }
  if(count>3) {
    count = 1;
  }
  else if(count < 1) {
    count = 3;
  }
  if(count == 1) {
  Time();
  }
  else if(count==2){
   function();
  }
  else if(count==3){
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
