#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

SoftwareSerial BlueTooth(2, 3); // (TXD, RXD) of HC-05

char BT_input;
void setup() {
BlueTooth.begin(9600);
  Serial.begin(9600); 
}

 void loop() {
   if (BlueTooth.available()) {
      BT_input=BlueTooth.read();
   }
  Serial.println(BT_input); delay(1000);
 }

