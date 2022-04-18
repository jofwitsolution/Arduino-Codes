#include <Wire.h>
#include <EEPROM.h>
#include "RTClib.h"
//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
//LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
RTC_DS1307 RTC;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {6, 7, 8, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int relayPin1 = 12;
int relayPin2 = 11;
String startHour1, startHour2, endHour1, endHour2, startMin1, startMin2, endMin1, endMin2;
int countH = 0;
int countM = 0;
int setState = 0; 
int HOUR, MINUT;
int x=0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.init();
  lcd.backlight();
  RTC.begin();
  if (! RTC.isrunning()) {
    lcd.print("RTC NOT running");
  }
  lcd.print("WELCOME");
  delay(2000);
  lcd.clear();
  RTC.adjust(DateTime(F(__DATE__), F(__TIME__))); //auto update from computer time
  //RTC.adjust(DateTime(2018, 11, 29, 18, 15, 10)); // to set the time manually
 
}
void loop() {
  
  DateTime now = RTC.now();
  HOUR = now.hour();
  MINUT = now.minute();
  if (setState==0) {
  lcd.setCursor(0, 0);
  lcd.print("Time:");
  lcd.setCursor(6, 0);
  lcd.print(HOUR);
  lcd.print(":");
  lcd.print(MINUT);
  lcd.print(":");
  lcd.print(now.second(), DEC);
  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  lcd.print(now.day(), DEC);
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(now.year(), DEC);
  }
   char key = myKeypad.getKey();
  if (key!=NO_KEY) {
    //Serial.print(key);
    if (key=='*')  setState = setState + 1;
   //lcd.clear();
    Serial.println(setState);   
    }
    if (key!=NO_KEY) {
     if (setState == 1) {
        if (x<1){
        if (x==0)   lcd.clear();
        lcd.print("Cker1 Start Time");
        lcd.setCursor(0,1);
        lcd.print("Hr:");
        lcd.setCursor(3,1);
        x=x+1;
        }
        key = myKeypad.getKey();
       
       if (key==0 || key==1 || key==2 || key==3 || key==4 || key==5 || key==6 || key==7 || key==8 || key==9) {
        
       startHour1+=key;
       countH = countH + 1;     
       lcd.print(startHour1); }
       
       if (countH == 2) {
            lcd.setCursor(5,1);
            lcd.print("Min:");
            lcd.setCursor(9,1);
            
            key = myKeypad.getKey();
           
        if (key!='D' && key!='*' && key!='#' && key!='A' && key!='B' && key!='C') {
            
            startMin1+=key;
            countM+= 1;    
            lcd.print(startMin1);
            delay(1000);            }
            
       }    
            Serial.println(startHour1);
            if (countM==2) {
              lcd.clear();
              lcd.print("Cker1 End Time");
              lcd.setCursor(0,1);
              lcd.print("Hr:");
              lcd.setCursor(3,1);
              //Serial.println(startMin1);
              //Serial.println(key);

             key = myKeypad.getKey();
            
         if (key!='D' && key!='*' && key!='#' && key!='A' && key!='B' && key!='C') {

            endHour1+=key;
            countH+=1;   
            lcd.print(endHour1);    }
            }
          
            if (countH==4) {
                lcd.setCursor(5,1);
                lcd.print("Min:");
                lcd.setCursor(9,1);

              key = myKeypad.getKey();
           
         if (key!='D' && key!='*' && key!='#' && key!='A' && key!='B' && key!='C') {

             endMin1+=key;
             countM+=1;
             lcd.print(endMin1);
             delay(1000);    
             if (countM==4) {
                lcd.clear();
                lcd.print("Cooker1 Set");
             }
            }
         }
            
            
            Serial.println(x);
       }
    }
    if (setState==2) {
        if (countH==4) countH=0;
        if (countM==4) countM=0;
        lcd.clear();
        lcd.print("Cker2 Start Time");
        lcd.setCursor(0,1);
        lcd.print("Hr:");
        lcd.setCursor(3,1);
        
        key = myKeypad.getKey();
        if (key!=NO_KEY) {
   if (key!='D' && key!='*' && key!='#' && key!='A' && key!='B' && key!='C') {

       startHour2+=key;
       countH = countH + 1;
       lcd.print(startHour2);   }
        }
       if (countH == 2) {
       lcd.setCursor(5,1);
       lcd.print("Min:");
       lcd.setCursor(9,1);

            key = myKeypad.getKey();
            if (key!=NO_KEY) {
        if (key!='D' && key!='*' && key!='#' && key!='A' && key!='B' && key!='C') {

            startMin2+=key;
            countM+= 1;
            lcd.print(startMin2);   }
            }
       }
            if (countM==2) {
              lcd.clear();
              lcd.print("Cker2 End Time");
              lcd.setCursor(0,1);
              lcd.print("Hr:");
              lcd.setCursor(3,1);

              key = myKeypad.getKey();
              if (key!=NO_KEY) {
         if (key!='D' && key!='*' && key!='#' && key!='A' && key!='B' && key!='C') {

            endHour2+=key;
            countH+=1;
            lcd.print(endHour2);    }
              }
            }
            if (countH==4) {
                lcd.setCursor(5,1);
                lcd.print("Min:");
                lcd.setCursor(9,1);
                
              key = myKeypad.getKey();
            if (key!=NO_KEY) {
         if (key!='D' && key!='*' && key!='#' && key!='A' && key!='B' && key!='C') {

             endMin2+=key;
             countM+=1;
             lcd.print(endMin2);
             delay(1000);         }
            }
            }
             if (countM==4) {
                lcd.clear();
                lcd.print("Cooker2 Set");
             }
       
      }

    int cooker1StartHour = startHour1.toInt();
    int cooker1StartMin = startMin1.toInt();
    int cooker1EndHour = endHour1.toInt();
    int cooker1EndMin = endMin1.toInt();
    int cooker2StartHour = startHour2.toInt();
    int cooker2StartMin = startMin2.toInt();
    int cooker2EndHour = endHour2.toInt();
    int cooker2EndMin = endMin2.toInt();
    
    if (cooker1StartHour==HOUR && cooker1StartMin==MINUT) {
      
       digitalWrite(relayPin1, HIGH);  
    }

    if (cooker2StartHour==HOUR && cooker2StartMin==MINUT) {
       digitalWrite(relayPin2, HIGH);  
    }

    if (cooker1EndHour==HOUR && cooker1EndMin==MINUT) {
       digitalWrite(relayPin1, LOW);  
    }

    if (cooker2EndHour==HOUR && cooker2EndMin==MINUT) {
       digitalWrite(relayPin2, LOW);  
    }
   if (setState==3)   {setState=0; countH=0; countM=0; } 
    //Serial.println(setState);
    //Serial.println(countH);
}
