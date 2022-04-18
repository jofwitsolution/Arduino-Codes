//This code is to use with DS1302 RTC module, it permits you to setup the actual time and date
//And you can visualize them on the LCD i2c screen
//This code is a modified version of the code provided in virtuabotixRTC library
//Refer to Surtrtech Youtube chhannel/Facebook page for more information

#include <virtuabotixRTC.h> //Libraries needed
#include <LiquidCrystal.h>

const int setButton = 13;
const int upButton = 3;
const int downButton = 1;
const int buzzerPin = 2;
int alarmMinutes=0;
int alarmHours=1;
int timer = 0;
int count=0;
int setButtonState=1;
int upButtonState=1;
int downButtonState=1;
int lastButtonState=1;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7); // (rs, en, d4, d5, d6, d7)
//Wiring SCLK -> 6, I/O -> 7, CE -> 8
//Or CLK -> 6 , DAT -> 7, Reset -> 8

virtuabotixRTC myRTC(6, 5, 4); //If you change the wiring change the pins here also

void setup() {
 Serial.begin(9600);
 lcd.begin (16,2); //Initialize the LCD

 pinMode (buzzerPin, OUTPUT);
 pinMode (setButton, INPUT);
 pinMode (upButton, INPUT);
 pinMode (downButton, INPUT);
 digitalWrite(buzzerPin, HIGH);
 delay(500);
 digitalWrite(buzzerPin, LOW);
 delay(500);
 
 myRTC.setDS1302Time(12, 4, 1, 8, 30, 11, 2018); //Here you write your actual time/date as shown above 
 //but remember to "comment/remove" this function once you're done as I did
 //The setup is done only one time and the module will continue counting it automatically
 
}

void loop() {
 lcd.clear(); //Here after clearing the LCD we take the time from the module and print it on the screen with usual LCD functions
 myRTC.updateTime();
 lcd.setCursor(0,0);
 lcd.print(myRTC.dayofmonth);
 lcd.print("/");
 lcd.print(myRTC.month);
 lcd.print("/");
 lcd.print(myRTC.year);
 lcd.setCursor(0,1);
 lcd.print(myRTC.hours);
 lcd.print(":");
 lcd.print(myRTC.minutes);
 lcd.print(":");
 lcd.print(myRTC.seconds);
 delay(1000);

 if (digitalRead(setButton)==LOW){
  setMODE();
 }
                          
  

  
if ((myRTC.hours == alarmHours ) && (myRTC.minutes == alarmMinutes )) {
  alarm();
}
}
  
  void alarm(){
    int a;
    if(a =0){
    for (int i=0; i<5; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
    }
    }
    if (digitalRead(upButton)==LOW){
      a=1;
  digitalWrite(buzzerPin, LOW);
  delay(60000);
  a=0;
  }
}

void setMODE(){
                          delay(20); 
                           if(count>=2) 
                           count = 0;
                           count++;
                           Serial.print(count);
                            
 
 switch(count) {
          case 1: if(digitalRead(upButton)==LOW){ delay(20);
              alarmHours++;
              //lcd.clear();
              lcd.setCursor(9,1);
              lcd.print("A: ");
              lcd.print(alarmHours);
              lcd.print(":");
              delay(500);
                }
          if (digitalRead(downButton)==LOW){ delay(20);
              alarmHours--;
              //lcd.clear();
              lcd.setCursor(9,1);
              lcd.print("A: ");
              lcd.print(alarmHours);
              lcd.print(":");
              delay(500);
                }
             break;   
    

     case 2: if (digitalRead(upButton)==LOW){ delay(20);
              alarmMinutes++;
             // lcd.clear();
              lcd.setCursor(14,1);
              //lcd.print("minutes: ");
              lcd.print(alarmMinutes);
              delay(500);
                }
          if (digitalRead(downButton)==LOW){ delay(20);
                alarmMinutes--;
                //lcd.clear();
                lcd.setCursor(14,1);
               // lcd.print("minutes: ");
                lcd.print(alarmMinutes);
                delay(500);
                }
                break;
    }
    
}


 



