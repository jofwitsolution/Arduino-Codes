//#include <Wire.h>
#include <LiquidCrystal.h>
#include "RTClib.h"

RTC_DS1307 rtc;
LiquidCrystal lcd(12, 11, 10, 9, 8, 7); // (rs, en, d4, d5, d6, d7)
int lightPin = 6;
int OnTimeHr = 0;
int OnTimeMin = 0;
int OffTimeHr = 0;
int OffTimeMin = 0;

char daysOfTheWeek [7] [4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(lightPin, OUTPUT);

  if (! rtc.begin()) {
    lcd.print("couldnt find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    lcd.print("RTC is NOT running");
  }

  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //auto update from computer time
  //rtc.adjust(DateTime(2020, 11, 29, 9, 0, 10)); // to set the time manually
}

void loop() {
  DateTime now = rtc.now();
  Serial.println(now.hour());
  Serial.println(now.minute());
  Serial.println("wawu");
  delay(500);

  Serial.println(now.year());
  Serial.println(now.day());
}

