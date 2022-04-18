#include "RTClib.h"

RTC_DS1307 rtc;

int lightPin = 6;
int OnTimeHr = 0;
int OnTimeMin = 0;
int OffTimeHr = 0;
int OffTimeMin = 0;

char daysOfTheWeek [7] [4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void setup() {
  Serial.begin(9600);
  
  pinMode(lightPin, OUTPUT);

  if (! rtc.begin()) {
    Serial.print("couldnt find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.print("RTC is NOT running");
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

