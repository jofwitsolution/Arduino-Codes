
//#include <LiquidCrystal.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,20,4);

//LiquidCrystal lcd (13, 12, 11, 10, 9, 8);


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','4','7','A'},
  {'2','5','8','B'},
  {'3','6','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {6, 7, 8, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  //lcd.begin(16,2);
  //lcd.setCursor(2,0);
  //lcd.println("key pressed:");
   Wire.begin();
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.print("PHEMMYTE");
  delay(2000);
  lcd.clear();
  
}
  
void loop(){
  
  char key = myKeypad.getKey();
 // lcd.setCursor(3,1);
  if (key!=NO_KEY){
    lcd.leftToRight();
    lcd.print(key);
    Serial.println(key);
}    
}
