/*This is to measure both voltage and current of a load
Printed on a PCB, connected with LM317 variable output voltage regulator
, ACS 712 current sensor, LCD and MCU. Other components include
a transformer, diodes, capacitors, variable resistors, fixed resistors, zener diode
*/
#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 =8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int voltagePin = 0;
int currentPin = 5;
//const int R;
 
void setup(){
  lcd.begin(16,2);
}
void loop(){
  float volt = analogRead(voltagePin);
    volt = (volt*5)/1023;
    volt = (volt*1);
    lcd.clear(); // Clear the display
    lcd.setCursor(0,0); 
    lcd.print("Voltage =    ");
    lcd.print(volt, 2);
  float curr = analogRead(currentPin);
    curr = ((curr-512)*5)/1023;
    curr = (curr * 1000)/66;
    lcd.setCursor(1,0);
    lcd.print("Current =    ");
    lcd.print(curr);
    delay(500);
}
