//Date and time function using a DS1307 RTC connected via I2C and wire lib
#include <Wire.h>
#include "RTClib.h" 

RTC_DS1307 rtc;

 char daysOfTheWeek [7] [4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
 int hr, mins;
 String prefix = "0";

void setup() {
  Serial.begin(9600);
   Serial.println("RTC");
  //check if the RTC module is connected
  if (! rtc.begin())
  {
    Serial.println("couldnt find RTC");
    delay(300);
    while (1);
  }
  if (! rtc.isrunning())
  {
    Serial.println("RTC is NOT running");
    
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //auto update from computer time
  // rtc.adjust(DateTime(2018, 11, 29, 18, 15, 10)); // to set the time manually
}

void loop() {
   Serial.println("RTC");
  DateTime now = rtc.now(); //this time stores real time in DateTime now

  hr = now.hour();
  if (hr > 12)  hr = hr - 12;
  hr = getTime(hr);
  mins = getTime(now.minute());
  
  Serial.println(hr);
  Serial.println(mins);
  Serial.println(daysOfTheWeek[now.dayOfTheWeek()]);
  delay(400);

}

int getTime(int Time) {
 
  if (Time < 10) {
    String result = prefix + String(Time);
    Time = result.toInt();
    return Time;
  }

  return Time;
}

