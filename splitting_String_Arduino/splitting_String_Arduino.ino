/*
* SplitSplit sketch
* split a comma-separated string
*/
//Date and time function using a DS1307 RTC connected via I2C and wire lib
#include <Wire.h>
#include "RTClib.h" 

RTC_DS1307 rtc;

 char daysOfTheWeek [7] [4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

// The substring() takes two arguement, the start index and end index.
// It returns string on the start index to the end index

String message= "Peter,Paul,Mary"; // an example string
String dateTime = "2018-11-29/18-15-10";
//String dateTime = "3/5";
String *dateAndTime;
String *splittedDate;
String *splittedTime;

int BT_year, BT_month, BT_day, BT_hour, BT_min, BT_second = 0;

//int i = 0;
 
int slashPosition; // the position of the next slash in the string

void setup() {
  Serial.begin(9600);
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
}

void loop() {
  DateTime now = rtc.now();
  //Serial.println(dateTime); // show the source string

  if (Serial.available()) {
    dateTime = Serial.readString();

  dateAndTime = split(dateTime, "/");

  String date = *(dateAndTime + 0);
  String Time = *(dateAndTime + 1);

  Serial.println(date);
  Serial.println(Time);

  splittedDate = split(date, "-");
  BT_year = String(*(splittedDate + 0)).toInt();
  BT_month = String(*(splittedDate + 1)).toInt();
  BT_day = String(*(splittedDate + 2)).toInt();
  
    for (int x = 0; x < 3; x++) {
  Serial.println(*(splittedDate + x));
  }

  splittedTime = split(Time, "-");
  BT_hour = String(*(splittedTime + 0)).toInt();
  BT_min = String(*(splittedTime + 1)).toInt();
  BT_second = String(*(splittedTime + 2)).toInt();

    for (int x = 0; x < 3; x++) {
  Serial.println(*(splittedTime + x));
  }
  
  rtc.adjust(DateTime(BT_year, BT_month, BT_day, BT_hour, BT_min, BT_second));
  delay(1000);
  }

  Serial.println(now.hour());
  Serial.println(now.minute());
  Serial.println(now.second());
  delay(2000);
}


//do  {
//  commaPosition = message.indexOf(',');
//  if(commaPosition != -1) {
//    Serial.println( message.substring(0,commaPosition));
//    message = message.substring(commaPosition+1, message.length());
//  }
//  else  { // here after the last comma is found
//    if(message.length() > 0)
//    Serial.println(message); // if there is text after the last comma, print it
//  }
//  }
//  while(commaPosition >=0);
//  delay(3000);


String * split(String dateTime, String Char) {
  int i = 0;
  static String result[3];
 
do  {
  slashPosition = dateTime.indexOf(Char);
  if(slashPosition != -1) {
    //Serial.println( dateTime.substring(0, slashPosition));
    result[i] = dateTime.substring(0, slashPosition);
    dateTime = dateTime.substring(slashPosition+1, dateTime.length());
    i++;
  }
  else  { // here after the last slash is found
    if(dateTime.length() > 0) {
    //Serial.println(dateTime); // if there is text after the last slash, print it
    result[i] = dateTime;
      }
    }
  }
  while(slashPosition >=0);

  return result;
}
