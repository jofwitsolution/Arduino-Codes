#include <SPI.h>
#include <Keypad.h>
#include <ShiftedLCD.h>

// initialize the library with the number of the sspin 
//(or the latch pin of the 74HC595)
LiquidCrystal lcd(10);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {3, 2, 8, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
   lcd.println("key pressed:");
   delay(3000);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    lcd.leftToRight();
    lcd.print(customKey);
    Serial.println(customKey);
    
  }
}
