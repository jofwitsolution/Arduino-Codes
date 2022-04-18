#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,20,4);

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys [ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {10, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

//Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
   Wire.begin();
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.print("PHEMMYTE");
  delay(2000);
 
  Serial.begin(9600);
}

void loop() {
  
  char key = keypad.getKeys();
  //if (key != NO_KEY) {

  if (key) {
    Serial.print(key);
  }
}
  

