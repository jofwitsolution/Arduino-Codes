#include <virtuabotixRTC.h> //Libraries needed
#include <LiquidCrystal.h>

const int hourButton = 13;
const int minuteButton = 3;
const int alarmPin = 2;
const int setButton = 1;
int minutes = 0;
int hours = 0;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7); // (rs, en, d4, d5, d6, d7)

virtuabotixRTC myRTC(6, 5, 4); //If you change the wiring change the pins here also

void setup() {
 Serial.begin(9600);
 lcd.begin (16,2); //Initialize the LCD

 pinMode (alarmPin, OUTPUT);
 pinMode (hourButton, INPUT);
 pinMode (minuteButton, INPUT);
 pinMode (setButton, INPUT);
 
 
 myRTC.setDS1302Time(0, 7, 2, 8, 1, 12, 2018); //Here you write your actual time/date as shown above 
 //but remember to "comment/remove" this function once you're done as I did
 //The setup is done only one time and the module will continue counting it automatically
 
}

void loop() {
 lcd.clear(); //Here after clearing the LCD we take the time from the module and print it on the screen with usual LCD functions
 myRTC.updateTime();
 lcd.setCursor(0,0);
 lcd.print("Date: ");
 lcd.print(myRTC.dayofmonth);
 lcd.print("/");
 lcd.print(myRTC.month);
 lcd.print("/");
 lcd.print(myRTC.year);
 lcd.setCursor(0,1);
 lcd.print("Time: ");
 lcd.print(myRTC.hours);
 lcd.print(":");
 lcd.print(myRTC.minutes);
 lcd.print(":");
 lcd.print(myRTC.seconds);
 delay(1000);
 
 if (digitalRead(hourButton)==LOW) {
  delay(20);
  hours++;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Alarm hour: ");
  lcd.print(hours);
  delay(400);
 }

 if (digitalRead(minuteButton)==LOW) {
  delay(20);
  minutes++;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Alarm min: ");
  lcd.print(minutes);
  delay(400);
 }
 if ((hours==myRTC.hours) && (minutes==myRTC.minutes)) {
   int a;
    if ( a == 0){
   for (int i=0; i<3; i++) {
    digitalWrite(alarmPin, HIGH);
    delay(200);
    digitalWrite(alarmPin, LOW);
    delay(200);
   
   }
 }
  if (digitalRead(setButton)==LOW){
    a=1;
    digitalWrite(alarmPin, LOW);
    delay(60000); 
    a=0; 
 }
 }
}

