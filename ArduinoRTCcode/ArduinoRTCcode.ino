//Date and time function using a DS1307 RTC connected via I2C and wire lib
#include <Wire.h>
#include <LiquidCrystal.h>
#include "RTClib.h" 

RTC_DS1307 rtc;
LiquidCrystal lcd(9, 8, 7, 6, 5, 4); // (rs, en, d4, d5, d6, d7)

 char daysOfTheWeek [7] [4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
int state = 0;
void setup() {
  Serial.begin(57600);
  lcd.begin(16,2);
  //check if the RTC module is connected
  if (! rtc.begin())
  {
    Serial.println("couldnt find RTC");
    delay(300);
    lcd.print("couldnt find RTC");
    while (1);
  }
  if (! rtc.isrunning())
  {
    Serial.println("RTC is NOT running");
    lcd.print("RTC is NOT running");
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //auto update from computer time
  }

  
  //rtc.adjust(DateTime(2018, 11, 29, 18, 15, 10)); // to set the time manually
lcd.clear();
}

void loop() {
  DateTime now = rtc.now(); //this time stores real time in DateTime now
  int getHour = now.hour();
  if (getHour >= 12) {
    getHour = getHour - 12;
    if (getHour == 0)   getHour = 12; 
    state = 1;
  }
  Serial.println("Time");
  Serial.println(now.hour(), DEC);
  Serial.println(now.minute(), DEC);
  Serial.println(now.second(), DEC);
  daysOfTheWeek[now.dayOfTheWeek()];
  delay(400);

  lcd.setCursor(0, 1);
  lcd.print(getHour);
  lcd.print(':');
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.second());
  lcd.print("   ");
  if (state == 0) {
     lcd.setCursor(7, 1);
    lcd.print("am");
  }
  else {
     lcd.setCursor(7, 1);
    lcd.print("pm");
  }
  lcd.setCursor(0, 0);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  lcd.print(" ,");
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());
}
