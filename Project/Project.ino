#define MiddleSwitch 10
#define LeftSwitch 11
#define RightSwitch 9

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#include <Wire.h>

#include "RTClib.h"

RTC_DS1307 RTC;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday"};

static int firstCount = 1;
static int count = 1;

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
  pinMode(LeftSwitch,INPUT);
  pinMode(MiddleSwitch,INPUT);
  pinMode(RightSwitch,INPUT);
  LetStart();
}

void Time() {
  lcd.clear();
  DateTime now = RTC.now();
  int Day = now.day();
  if(digitalRead(MiddleSwitch) == 1) {
    lcd.clear();
  lcd.print(now.year(), DEC);
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(Day);
  lcd.setCursor(0,1);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  delay(2000);
  if(now.day()!=Day) {
    Time();
  }
  if(digitalRead(MiddleSwitch) == 1) Time();
  }
  lcd.print("Now time is:");
  lcd.setCursor(0,1);
  lcd.print(now.hour(),DEC);
  lcd.print(":");
  lcd.print(now.minute(),DEC);
  lcd.print(":");
  lcd.print(now.second(),DEC);
  delay(100);
  Time();
}

void InterfaceOn() {
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
  functure();
  }
  else {
    automatic();
  }
  
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
