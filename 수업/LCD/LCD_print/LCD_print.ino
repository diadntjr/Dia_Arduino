#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x7f,16,2);

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.print("Hello World");

}

void loop() {
  // put your main code here, to run repeatedly:

}
