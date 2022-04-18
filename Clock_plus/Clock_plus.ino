/* 
 This is a arduino program using the  DMD as an output for display. 
 It contains an alarm function. The day, date and time is printed on the DMD. 
 The alarm function button is on pins 2 for alarm set, 3 for snooze and 4 for the output alarm.
 The alarm time and days of week can be set. 
 */
byte dayOfWeek=4;
byte dayOfMonth=1;

#include <SPI.h>        //SPI.h must be included as DMD is written by SPI (the IDE complains otherwise)
#include <DMD.h>        //
#include <TimerOne.h>   //
#include "SystemFont5x7.h"
#include "Wire.h"
#include <Wire.h>
#include "RTClib.h"
#define DS1307_I2C_ADDRESS 0x68

int AlarmSetPin = 2;
int SnoozePin = 3;
int Alarm = 4;
int AlarmSet = 0;
int Snooze = 0;

// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return ( (val/10*16) + (val%10) );
}

// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return ( (val/16*10) + (val%16) );
}

// 1) Sets the date and time on the ds1307
// 2) Starts the clock
// 3) Sets hour mode to 24 hour clock

// Assumes you're passing in valid numbers

void setDateDs1307(byte second,        // 0-59
byte minute,        // 0-59
byte hour,          // 1-23
byte dayOfWeek,     // 1-7
byte dayOfMonth,    // 1-28/29/30/31
byte month,         // 1-12
byte year)          // 0-99
{
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(0); //it tells the DS that data is coming in
  Wire.write(decToBcd(second));    // 0 to bit 7 starts the clock
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));     
  Wire.write(decToBcd(dayOfWeek));
  Wire.write(decToBcd(dayOfMonth));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(00010000); // sends 0x10 (hex) 00010000 (binary) to control register - turns on square wave
  Wire.endTransmission();
}

// Gets the date and time from the ds1307
void getDateDs1307(byte *second,
byte *minute,
byte *hour,
byte *dayOfWeek,
byte *dayOfMonth,
byte *month,
byte *year)
{
  // Reset the register pointer
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_I2C_ADDRESS, 7);
  // A few of these need masks because certain bits are control bits
  *second     = bcdToDec(Wire.read() & 0x7f);
  *minute     = bcdToDec(Wire.read());
  *hour       = bcdToDec(Wire.read() & 0x3f);  // Need to change this if 12 hour am/pm
  *dayOfWeek  = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month      = bcdToDec(Wire.read());
  *year       = bcdToDec(Wire.read());
}

//Fire up the DMD library as dmd
DMD dmd(1,1);

void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}

void setup()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

  //initialize TimerOne's interrupt/CPU usage used to scan and refresh the display
  Timer1.initialize( 5000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
  Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()

  //clear/init the DMD pixels held in RAM
  dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
  dmd.selectFont(System5x7);

  Wire.begin();

  // Change these values to what you want to set your clock to.
  // You probably only want to set your clock once and then remove
  // the setDateDs1307 call.

  second = 0;
  minute = 10;
  hour = 21; // use 24-hour time otherwise day/date calculations will be off
  dayOfWeek = 1;
  dayOfMonth = 02;
  month = 9;
  year = 18;
  //uncomment the setDateDs1307 call below to set time to intervals above.  Remember if you set the time 
  //you need to uncomment the line below again otherwise the sketch will only stay at the time set.
  setDateDs1307(second, minute, hour, dayOfWeek, dayOfMonth, month, year);

  pinMode(AlarmSetPin, INPUT_PULLUP);
  pinMode(SnoozePin, INPUT_PULLUP);
  pinMode(Alarm, OUTPUT);
  digitalWrite(Alarm, LOW);
}

void drawDay()
// shows day of week
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  getDateDs1307(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  switch(dayOfWeek)
  {
  case 1:
    dmd.drawString( 1,0, "Sun,", 3, GRAPHICS_NORMAL );    
    break;

  case 2:
    dmd.drawString( 1,0, "Mon,", 3, GRAPHICS_NORMAL );        
    break;

  case 3:
    dmd.drawString( 1,0, "Tue,", 3, GRAPHICS_NORMAL );        
    break;

  case 4:
    dmd.drawString( 1,0, "Wed,", 3, GRAPHICS_NORMAL );        
    break;

  case 5:
    dmd.drawString( 1,0, "Thu,", 3, GRAPHICS_NORMAL );        
    break;

  case 6:
    dmd.drawString( 1,0, "Fri,", 3, GRAPHICS_NORMAL );        
    break;

  case 7:
    dmd.drawString( 1,0, "Sat,", 3, GRAPHICS_NORMAL );        
    break;
  }
}

void drawDate()
// shows numerical date
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  getDateDs1307(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  switch(dayOfMonth)
  {
  case 1:
    dmd.drawString( 20,0, "01", 2, GRAPHICS_NORMAL );
    break;
  case 2:
    dmd.drawString( 20,0, "02", 2, GRAPHICS_NORMAL );
    break;
  case 3:
    dmd.drawString( 20,0, "03", 2, GRAPHICS_NORMAL );
    break;
  case 4:
    dmd.drawString( 20,0, "04", 2, GRAPHICS_NORMAL );
    break;
  case 5:
    dmd.drawString( 20,0, "05", 2, GRAPHICS_NORMAL );
    break;
  case 6:
    dmd.drawString( 20,0, "06", 2, GRAPHICS_NORMAL );
    break;
  case 7:
    dmd.drawString( 20,0, "07", 2, GRAPHICS_NORMAL );
    break;
  case 8:
    dmd.drawString( 20,0, "08", 2, GRAPHICS_NORMAL );
    break;
  case 9:
    dmd.drawString( 20,0, "09", 2, GRAPHICS_NORMAL );
    break;
  case 10:
    dmd.drawString( 20,0, "10", 2, GRAPHICS_NORMAL );
    break;
  case 11:
    dmd.drawString( 20,0, "11", 2, GRAPHICS_NORMAL );
    break;
  case 12:
    dmd.drawString( 20,0, "12", 2, GRAPHICS_NORMAL );
    break;
  case 13:
    dmd.drawString( 20,0, "13", 2, GRAPHICS_NORMAL );
    break;
  case 14:
    dmd.drawString( 20,0, "14", 2, GRAPHICS_NORMAL );
    break;
  case 15:
    dmd.drawString( 20,0, "15", 2, GRAPHICS_NORMAL );
    break;
  case 16:
    dmd.drawString( 20,0, "16", 2, GRAPHICS_NORMAL );
    break;
  case 17:
    dmd.drawString( 20,0, "17", 2, GRAPHICS_NORMAL );
    break;
  case 18:
    dmd.drawString( 20,0, "18", 2, GRAPHICS_NORMAL );
    break;
  case 19:
    dmd.drawString( 20,0, "19", 2, GRAPHICS_NORMAL );
    break;
  case 20:
    dmd.drawString( 20,0, "20", 2, GRAPHICS_NORMAL );
    break;
  case 21:
    dmd.drawString( 20,0, "21", 2, GRAPHICS_NORMAL );
    break;
  case 22:
    dmd.drawString( 20,0, "22", 2, GRAPHICS_NORMAL );
    break;
  case 23:
    dmd.drawString( 20,0, "23", 2, GRAPHICS_NORMAL );
    break;
  case 24:
    dmd.drawString( 20,0, "24", 2, GRAPHICS_NORMAL );
    break;
  case 25:
    dmd.drawString( 20,0, "25", 2, GRAPHICS_NORMAL );
    break;
  case 26:
    dmd.drawString( 20,0, "26", 2, GRAPHICS_NORMAL );
    break;
  case 27:
    dmd.drawString( 20,0, "27", 2, GRAPHICS_NORMAL );
    break;
  case 28:
    dmd.drawString( 20,0, "28", 2, GRAPHICS_NORMAL );
    break;
  case 29:
    dmd.drawString( 20,0, "29", 2, GRAPHICS_NORMAL );
    break;
  case 30:
    dmd.drawString( 20,0, "30", 2, GRAPHICS_NORMAL );
    break;
  case 31:
    dmd.drawString( 20,0, "31", 2, GRAPHICS_NORMAL );
    break;
  }
}

void drawHour()
// draws the hour hand
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  getDateDs1307(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  if (hour>12) //Remove this if command for 24 hour time
  {
    hour=hour-12; // This is a 12 hour Clock 
  }
  switch(hour)
  {
  case 1:
    dmd.drawString( 1,8, "01", 2, GRAPHICS_NORMAL );
    break;
  case 2:
    dmd.drawString( 1,8, "02", 2, GRAPHICS_NORMAL );
    break;
  case 3:
    dmd.drawString( 1,8, "03", 2, GRAPHICS_NORMAL );
    break;
  case 4:
    dmd.drawString( 1,8, "04", 2, GRAPHICS_NORMAL );
    break;
  case 5:
    dmd.drawString( 1,8, "05", 2, GRAPHICS_NORMAL );
    break;
  case 6:
    dmd.drawString( 1,8, "06", 2, GRAPHICS_NORMAL );
    break;
  case 7:
    dmd.drawString( 1,8, "07", 2, GRAPHICS_NORMAL );
    break;
  case 8:
    dmd.drawString( 1,8, "08", 2, GRAPHICS_NORMAL );
    break;
  case 9:
    dmd.drawString( 1,8, "09", 2, GRAPHICS_NORMAL );
    break;
  case 10:
    dmd.drawString( 1,8, "10", 2, GRAPHICS_NORMAL );
    break;
  case 11:
    dmd.drawString( 1,8, "11", 2, GRAPHICS_NORMAL );
    break;
  case 12:
    dmd.drawString( 1,8, "12", 2, GRAPHICS_NORMAL );
    break;
  case 13:
    dmd.drawString( 1,8, "13", 2, GRAPHICS_NORMAL );
    break;
  case 14:
    dmd.drawString( 1,8, "14", 2, GRAPHICS_NORMAL );
    break;
  case 15:
    dmd.drawString( 1,8, "15", 2, GRAPHICS_NORMAL );
    break;
  case 16:
    dmd.drawString( 1,8, "16", 2, GRAPHICS_NORMAL );
    break;
  case 17:
    dmd.drawString( 1,8, "17", 2, GRAPHICS_NORMAL );
    break;
  case 18:
    dmd.drawString( 1,8, "18", 2, GRAPHICS_NORMAL );
    break;
  case 19:
    dmd.drawString( 1,8, "19", 2, GRAPHICS_NORMAL );
    break;
  case 20:
    dmd.drawString( 1,8, "20", 2, GRAPHICS_NORMAL );
    break;
  case 21:
    dmd.drawString( 1,8, "21", 2, GRAPHICS_NORMAL );
    break;
  case 22:
    dmd.drawString( 1,8, "22", 2, GRAPHICS_NORMAL );
    break;
  case 23:
    dmd.drawString( 1,8, "23", 2, GRAPHICS_NORMAL );
    break;
  case 24:
    dmd.drawString( 1,8, "24", 2, GRAPHICS_NORMAL );
    break;
  }
}

void drawMinute()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  getDateDs1307(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  switch(minute)
  {
  case 0:
    dmd.drawString( 20,8, "00", 2, GRAPHICS_NORMAL );
    break;
  case 1:
    dmd.drawString( 20,8, "01", 2, GRAPHICS_NORMAL );
    break;
  case 2:
    dmd.drawString( 20,8, "02", 2, GRAPHICS_NORMAL );
    break;
  case 3:
    dmd.drawString( 20,8, "03", 2, GRAPHICS_NORMAL );
    break;
  case 4:
    dmd.drawString( 20,8, "04", 2, GRAPHICS_NORMAL );
    break;
  case 5:
    dmd.drawString( 20,8, "05", 2, GRAPHICS_NORMAL );
    break;
  case 6:
    dmd.drawString( 20,8, "06", 2, GRAPHICS_NORMAL );
    break;
  case 7:
    dmd.drawString( 20,8, "07", 2, GRAPHICS_NORMAL );
    break;
  case 8:
    dmd.drawString( 20,8, "08", 2, GRAPHICS_NORMAL );
    break;
  case 9:
    dmd.drawString( 20,8, "09", 2, GRAPHICS_NORMAL );
    break;
  case 10:
    dmd.drawString( 20,8, "10", 2, GRAPHICS_NORMAL );
    break;
  case 11:
    dmd.drawString( 20,8, "11", 2, GRAPHICS_NORMAL );
    break;
  case 12:
    dmd.drawString( 20,8, "12", 2, GRAPHICS_NORMAL );
    break;
  case 13:
    dmd.drawString( 20,8, "13", 2, GRAPHICS_NORMAL );
    break;
  case 14:
    dmd.drawString( 20,8, "14", 2, GRAPHICS_NORMAL );
    break;
  case 15:
    dmd.drawString( 20,8, "15", 2, GRAPHICS_NORMAL );
    break;
  case 16:
    dmd.drawString( 20,8, "16", 2, GRAPHICS_NORMAL );
    break;
  case 17:
    dmd.drawString( 20,8, "17", 2, GRAPHICS_NORMAL );
    break;
  case 18:
    dmd.drawString( 20,8, "18", 2, GRAPHICS_NORMAL );
    break;
  case 19:
    dmd.drawString( 20,8, "19", 2, GRAPHICS_NORMAL );
    break;
  case 20:
    dmd.drawString( 20,8, "20", 2, GRAPHICS_NORMAL );
    break;
  case 21:
    dmd.drawString( 20,8, "21", 2, GRAPHICS_NORMAL );
    break;
  case 22:
    dmd.drawString( 20,8, "22", 2, GRAPHICS_NORMAL );
    break;
  case 23:
    dmd.drawString( 20,8, "23", 2, GRAPHICS_NORMAL );
    break;
  case 24:
    dmd.drawString( 20,8, "24", 2, GRAPHICS_NORMAL );
    break;
  case 25:
    dmd.drawString( 20,8, "25", 2, GRAPHICS_NORMAL );
    break;
  case 26:
    dmd.drawString( 20,8, "26", 2, GRAPHICS_NORMAL );
    break;
  case 27:
    dmd.drawString( 20,8, "27", 2, GRAPHICS_NORMAL );
    break;
  case 28:
    dmd.drawString( 20,8, "28", 2, GRAPHICS_NORMAL );
    break;
  case 29:
    dmd.drawString( 20,8, "29", 2, GRAPHICS_NORMAL );
    break;
  case 30:
    dmd.drawString( 20,8, "30", 2, GRAPHICS_NORMAL );
    break;
  case 31:
    dmd.drawString( 20,8, "31", 2, GRAPHICS_NORMAL );
    break;
  case 32:
    dmd.drawString( 20,8, "32", 2, GRAPHICS_NORMAL );
    break;
  case 33:
    dmd.drawString( 20,8, "33", 2, GRAPHICS_NORMAL );
    break;
  case 34:
    dmd.drawString( 20,8, "34", 2, GRAPHICS_NORMAL );
    break;
  case 35:
    dmd.drawString( 20,8, "35", 2, GRAPHICS_NORMAL );
    break;
  case 36:
    dmd.drawString( 20,8, "36", 2, GRAPHICS_NORMAL );
    break;
  case 37:
    dmd.drawString( 20,8, "37", 2, GRAPHICS_NORMAL );
    break;
  case 38:
    dmd.drawString( 20,8, "38", 2, GRAPHICS_NORMAL );
    break;
  case 39:
    dmd.drawString( 20,8, "39", 2, GRAPHICS_NORMAL );
    break;
  case 40:
    dmd.drawString( 20,8, "40", 2, GRAPHICS_NORMAL );
    break;
  case 41:
    dmd.drawString( 20,8, "41", 2, GRAPHICS_NORMAL );
    break;
  case 42:
    dmd.drawString( 20,8, "42", 2, GRAPHICS_NORMAL );
    break;
  case 43:
    dmd.drawString( 20,8, "43", 2, GRAPHICS_NORMAL );
    break;
  case 44:
    dmd.drawString( 20,8, "44", 2, GRAPHICS_NORMAL );
    break;
  case 45:
    dmd.drawString( 20,8, "45", 2, GRAPHICS_NORMAL );
    break;
  case 46:
    dmd.drawString( 20,8, "46", 2, GRAPHICS_NORMAL );
    break;
  case 47:
    dmd.drawString( 20,8, "47", 2, GRAPHICS_NORMAL );
    break;
  case 48:
    dmd.drawString( 20,8, "48", 2, GRAPHICS_NORMAL );
    break;
  case 49:
    dmd.drawString( 20,8, "49", 2, GRAPHICS_NORMAL );
    break;
  case 50:
    dmd.drawString( 20,8, "50", 2, GRAPHICS_NORMAL );
    break;
  case 51:
    dmd.drawString( 20,8, "51", 2, GRAPHICS_NORMAL );
    break;
  case 52:
    dmd.drawString( 20,8, "52", 2, GRAPHICS_NORMAL );
    break;
  case 53:
    dmd.drawString( 20,8, "53", 2, GRAPHICS_NORMAL );
    break;
  case 54:
    dmd.drawString( 20,8, "54", 2, GRAPHICS_NORMAL );
    break;
  case 55:
    dmd.drawString( 20,8, "55", 2, GRAPHICS_NORMAL );
    break;
  case 56:
    dmd.drawString( 20,8, "56", 2, GRAPHICS_NORMAL );
    break;
  case 57:
    dmd.drawString( 20,8, "57", 2, GRAPHICS_NORMAL );
    break;
  case 58:
    dmd.drawString( 20,8, "58", 2, GRAPHICS_NORMAL );
    break;
  case 59:
    dmd.drawString( 20,8, "59", 2, GRAPHICS_NORMAL );
    break;
  }
}

void drawCol()
{
  dmd.drawString( 14,8, ":", 1, GRAPHICS_NORMAL );
}


void runClock()
{
  drawDay();  
  drawDate();
  drawHour();
  drawCol();
  drawMinute();
 // CheckAlarm();

}

void AlarmSequence() {
  drawDay();  
  drawDate();
  drawHour();
  drawCol();
  drawMinute();
  digitalWrite(Alarm, HIGH);
  delay(1000);
  dmd.clearScreen( true );
  digitalWrite(Alarm, LOW);
  delay(1000);
}

void CheckAlarm() {
  AlarmSet = digitalRead(AlarmSetPin);
  Snooze = digitalRead(SnoozePin);
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  getDateDs1307(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  /* Only Trigger Alarm If it is a day listed below. This can be changed by changing the numbers to any of the following:
   1 = Sunday
   2 = Monday
   3 = Tuesday
   4 = Wednesday
   5 = Thursday
   6 = Friday
   7 = Saturday
   */
  if(dayOfWeek == 2 || dayOfWeek == 3 || dayOfWeek == 4 || dayOfWeek == 5 ||dayOfWeek == 6) { //This is days ALLOWED to ring alarm
    if(hour == 18 && minute == 05 ) { //Set Time Here (In 24 hour Time) 
      if(AlarmSet == LOW) { //If alarm pin is on
        Snooze = digitalRead(SnoozePin);
        while(Snooze == HIGH)
        {
          Snooze = digitalRead(SnoozePin);
          AlarmSequence();
        }
      }
    }
  }
}
void loop()
{
  runClock();  
}
