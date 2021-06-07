#include <Wire.h>

#include "RTClib.h"

RTC_DS1307 RTC;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday"};

// 요일이 틀리면 순서를 바꿔줍니다. 



void setup () {

  Serial.begin(9600);

  Wire.begin();

  RTC.begin();
  if(! RTC.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if(! RTC.isrunning()) {
    Serial.println("RTC is NOT running");
  }
 // RTC.adjust(DateTime(F(__DATE__),F(__TIME__)));    

  /*현재시간을 설정할 수 있습니다. 시간 설정시 앞의 //를 지운 후 업로드한 후 다시 //를 넣고 업로드해주세요.

   월에 대한 설정입니다.

    1월: Jan

    2월: Feb

    3월: Mar

    4월: Apr

    5월: May

    6월: Jun

    7월: Jul

    8월: Aug

    9월: Sep

    10월: Qct

    11월: Nov

    12월: Dec

  */

}



void loop () {

  DateTime now = RTC.now();

  Serial.print(now.year(), DEC);  // 년

  Serial.print('/');

  Serial.print(now.month(), DEC);  // 월

  Serial.print('/');

  Serial.print(now.day(), DEC);   // 일

  Serial.print(' ');

  Serial.print(now.hour(), DEC);    // 시간

  Serial.print(':');

  Serial.print(now.minute(), DEC);   // 분

  Serial.print(':');

  Serial.print(now.second(), DEC);   // 초

  Serial.print(' ');

  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);   // 요일

  Serial.println();

  delay(1000);

}
