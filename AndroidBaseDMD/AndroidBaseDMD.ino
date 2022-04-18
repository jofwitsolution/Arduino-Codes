#include <SoftwareSerial.h>
#include <EEPROM.h>
#include "RTClib.h" 
#include "SPI.h"
#include "DMD.h"
#include "TimerOne.h"
#include "System6x7.h"
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#include "SystemFont3x5.h"
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1

SoftwareSerial BlueTooth(0, 1); // (TXD, RXD) of HC-05
RTC_DS1307 rtc; 
DMD dmd( DISPLAYS_ACROSS , DISPLAYS_DOWN );

char daysOfTheWeek [7] [4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
char monthsOfTheYear [12] [4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

// EEPROM addressing
const byte EEPROM_ID = 0x99;  // initializing EEPROM ID
int addr_0 = 0;               // ID address

String BT_input;
String textToScroll="Computer";
String hodName = "DR. OKE";
String meridiem, Hour, Mins;
String mode;
int hr, mins;
unsigned long currentTime = 0;

String dateTime;



void setup() {
  
  Serial.begin(9600);
  BlueTooth.begin(9600);
  Timer1.initialize( 5000 );
  Timer1.attachInterrupt( ScanDMD );
  dmd.clearScreen( true );

  //check if the RTC module is connected
  if (! rtc.begin())
  {
    Serial.println("couldnt find RTC");
    delay(300);
    //while (1);
  }
  if (! rtc.isrunning())
  {
    Serial.println("RTC is NOT running");
    
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //auto update from computer time
  //rtc.adjust(DateTime(2018, 11, 29, 18, 15, 10)); // to set the time manually
}

void loop() {

  EEPROM_read_write(); // read/write operation is performed
  Serial.println(textToScroll);
  Serial.println(textToScroll.c_str());
//  DateTime now = rtc.now(); //this time stores real time in DateTime now
//Serial.println(now.hour(), DEC);
//  hr = now.hour();  
//  if (hr >= 12)  {// convert to 12 hour format
//    hr = hr - 12;
//    if (hr == 0) hr = 12;
//    meridiem = "PM";
//  }
//  else {
//    meridiem = "AM";
//  }
//  
//  Hour = getTime(hr);
//  Mins = getTime(now.minute());
//  String Time = Hour + ":" + Mins + meridiem;
//  String Day = String(daysOfTheWeek[now.dayOfTheWeek()]) + ", " + String(now.day());
//  String monthYear = String(monthsOfTheYear[now.month() - 1]) + " " + String(now.year());  
//  
//  if (BlueTooth.available()) {
//      mode = BlueTooth.readString();
//      //Serial.println(mode);
//   }
//
//   while (mode == "sc") {  
//    // Wait for the new textToScroll
//     if (BlueTooth.available()) {
//      BT_input=BlueTooth.readString();
//      if (BT_input == "0") {
//        mode = "0";
//      }
//      else {
//        //Serial.println(BT_input);
//        textToScroll = BT_input;
//        Serial.println("Update Successfull");
//        int textLen = writeStringToEEPROM(100, textToScroll);
//        mode = "0";
//      }
//    }
//  }
//
//  while (mode == "hod") {  
//    // Wait for the new textToScroll
//     if (BlueTooth.available()) {
//      BT_input=BlueTooth.readString();
//      if (BT_input == "0") {
//        mode = "0";
//      }
//      else {
//        //Serial.println(BT_input);
//        if (BT_input.length() <= 8) { // write the new hodName
//            hodName = BT_input;
//            Serial.println("Update Successfull");
//            int textLen = writeStringToEEPROM(1, hodName);
//            mode = "0";
//        } else { mode = "0"; }  // exit the loop and live the existing hodName
//      }
//    }
//  }
//
//   while (mode == "dt") {
//     // Wait for the new date and time string
//     if (BlueTooth.available()) {
//        BT_input=BlueTooth.readString();
//        if (BT_input == "0") {
//        mode = "0";
//      }
//      else {
//        dateTime = BT_input;
//        setDateTime();
//        Serial.println("Update Successfull");
//        mode = "0";
//      }
//     } 
//   }
//
////   if (Serial.available()) {
////      BT_input=Serial.readString();
////      //Serial.println(BT_input);
////      textToScroll = BT_input;
////      int textLen = writeStringToEEPROM(100, textToScroll);
////      mode = '0';
////    }
//   
//
////   Serial.println(Time.c_str());
////   Serial.println(Day.c_str());
////   Serial.println(monthYear.c_str());
// 
  drawText(textToScroll);
//  dmd.selectFont( SystemFont3x5 );
//  dmd.drawString( 2,0, hodName.c_str(), 7, GRAPHICS_NORMAL);
//  dmd.drawString( 10,9, "HOD", 3, GRAPHICS_NORMAL);
//  delay(2000);
//  dmd.clearScreen ( true );
//  dmd.selectFont( SystemFont3x5 );
//  dmd.drawString( 3,0, "FIRST", 5, GRAPHICS_NORMAL);
//  dmd.drawString( 0,9, "SEMESTER", 8, GRAPHICS_NORMAL);
//  delay(2000);
//  dmd.clearScreen ( true );
//
//  currentTime = millis();
//  while (currentTime + 10000 >= millis()) {
//    DateTime now = rtc.now(); //this time stores real time in DateTime now
//    dmd.selectFont ( System6x7 );
//    dmd.drawString( 1,3, Hour.c_str(), 2, GRAPHICS_NORMAL);
//    if (now.second()% 2 != 0) {
//      dmd.drawBox(15, 5, 16, 6, GRAPHICS_NORMAL ); // dmd.drawBox(x1, y1, x2, y2, GRAPHICS_NORMAL );
//      dmd.drawBox(15, 8, 16, 9, GRAPHICS_NORMAL ); // dmd.drawBox(x1, y1, x2, y2, GRAPHICS_NORMAL );
//    }
//    else {
//      dmd.drawBox(15, 5, 16, 6, GRAPHICS_NOR ); // dmd.drawBox(x1, y1, x2, y2, GRAPHICS_NORMAL );
//      dmd.drawBox(15, 8, 16, 9, GRAPHICS_NOR );
//    }
//    dmd.drawString( 18,3, Mins.c_str(), 2, GRAPHICS_NORMAL);
//  }
//  dmd.clearScreen ( true );
//  
//  dmd.selectFont( SystemFont3x5 );
//  dmd.drawString( 1,0, Time.c_str(), 7, GRAPHICS_NORMAL);
//  dmd.drawString( 0,9, "GOOD DAY", 8, GRAPHICS_NORMAL);
//  delay(3000);
//  dmd.clearScreen ( true );
//  dmd.selectFont( SystemFont3x5 );
//  dmd.drawString( 0,0, Day.c_str(), 7, GRAPHICS_NORMAL);
//  dmd.drawString( 0,9, monthYear.c_str(), 8, GRAPHICS_NORMAL);
//  delay(3000);
//  dmd.clearScreen ( true );

} // end of void loop()

void ScanDMD() {
  dmd.scanDisplayBySPI();
}


void drawText( String dispString ) {
  dmd.clearScreen( true );
  dmd.selectFont( Arial_Black_16 );
  char newString[256];
  int sLength = dispString.length();
  dispString.toCharArray( newString, sLength+1 );
  dmd.drawMarquee( newString , sLength , ( 32*DISPLAYS_ACROSS )-1 ,0);
  long start=millis();
  long timer=start;
  long timer2=start;
  boolean ret=false;
  while( !ret ){
    if ( ( timer+60 ) < millis() ) {
      ret=dmd.stepMarquee( -1 , 0 );
      timer=millis();
    }
  }
} // end of drawText


// this function prefix time with "0" if time is less than 10
String getTime(int Time) {
  String prefix = "0";
  if (Time < 10) {
    String result = prefix + String(Time);
    //Time = result.toInt();
    return result;
  }

  return String(Time);
} // end of getTime()


// This function split string. It takes two arg the String to split and the char to be used to split.
String * split(String dateTime, String Char) {
  
  int i = 0;
  int charPosition = 0; 
  static String result[3];  // static pointer string array
 
  do  {
    charPosition = dateTime.indexOf(Char);
    if(charPosition != -1) {
      //Serial.println( dateTime.substring(0, charPosition));
      result[i] = dateTime.substring(0, charPosition);  //return text starting from index 0 and less than charPosition(index)
      dateTime = dateTime.substring(charPosition+1, dateTime.length()); // overwrite dateTime with text after charPosition 
      i++;  // increment the array
    }
    else  { // here after the last char is found
      if(dateTime.length() > 0) {
      // if there is text after the last char, store it
      result[i] = dateTime;
        }
      }
    }
  while(charPosition >=0);

  return result;
} // end of split()


// this function update the date and time 
void setDateTime() {

  String *dateAndTime;
  String *splittedDate;
  String *splittedTime;
  
  int BT_year, BT_month, BT_day, BT_hour, BT_min, BT_second = 0;

  dateTime.trim();
  dateAndTime = split(dateTime, "/");

  String date = *(dateAndTime + 0);
  String Time = *(dateAndTime + 1);

  splittedDate = split(date, "-");
  BT_year = String(*(splittedDate + 0)).toInt();
  BT_month = String(*(splittedDate + 1)).toInt();
  BT_day = String(*(splittedDate + 2)).toInt();

  splittedTime = split(Time, "-");
  BT_hour = String(*(splittedTime + 0)).toInt();
  BT_min = String(*(splittedTime + 1)).toInt();
  BT_second = String(*(splittedTime + 2)).toInt();
  
  rtc.adjust(DateTime(BT_year, BT_month, BT_day, BT_hour, BT_min, BT_second));
  
  } // end of setDateTime()


int writeStringToEEPROM(int addrOffset, const String &strToWrite) { 
  int count = 1;
  int len = strToWrite.length(); 
  if (len > 800) return len;  // return if the remaining character length is too much for the EEPROM
  //Serial.println(len);
  if (len > 254) {  // if string length is greater than a byte(255)
    EEPROM.write(addrOffset, 254);  // write 254 to EEPROM
    int remainder = len - 254;      //  get the remainder
    while (remainder > 254) {       // while the remainder is still greater than 254
       EEPROM.write(addrOffset + count, 254); // write 254 to the next address
       remainder = remainder - 254;
       count++;   //  increment address
       if (count == 3) break; // break bcus we dont want length of charact to exceed EEPROM limit
    }
    
    byte remByte = remainder;
    //Serial.println(remByte);
    EEPROM.write(addrOffset + count, remByte);  // store the remaining length in EEPROM
    count++;  // move to the next address
  }
  else { // otherwise
    EEPROM.write(addrOffset, len);  
  }
   
  for (int i = 0; i < len; i++) { 
    EEPROM.write(addrOffset + count + i, strToWrite[i]);  // write characters to EEPROM
    } 
    
    return len; // return length of characters
 } // end of writeStringToEEPROM()

String readStringFromEEPROM(int addrOffset) { 
    int count = 1;
    int totalLen = 0;
    int newStrLen = EEPROM.read(addrOffset);
    totalLen = newStrLen;
    
    while (newStrLen == 254) {
      newStrLen = EEPROM.read(addrOffset + count);
      totalLen += newStrLen;
      //Serial.println(totalLen);
      count++;
    }
    
    //Serial.println(count);
    char data[totalLen + 1]; 
    for (int i = 0; i < totalLen; i++) { 
      data[i] = EEPROM.read(addrOffset + count + i); 
     } 

     data[totalLen] = '\0';  
     
     return String(data);
} 

void EEPROM_read_write() {
  byte id = EEPROM.read(addr_0); // read the first byte from the EEPROM
  if( id == EEPROM_ID) {
     textToScroll = readStringFromEEPROM(100);
     hodName = readStringFromEEPROM(1);  
  }
  else {// this code is executed once after the program is uploaded on the controller
    EEPROM.write(addr_0, EEPROM_ID);
    int textLen = writeStringToEEPROM(100, textToScroll);
    int hodNameLen = writeStringToEEPROM(1, hodName);
  }
}

