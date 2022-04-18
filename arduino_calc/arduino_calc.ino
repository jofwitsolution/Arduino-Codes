
#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd (13, 12, 11, 10, 9, 8);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','4','C'},
  {'2','5','/'},
  {'3','6','='},
  {'*','0','+'}
};
byte rowPins[ROWS] = {7, 6, 5, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3, 2, 1}; //connect to the column pinouts of the keypad

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

boolean firstNumState = true;
String firstNum = "";
String secondNum = "";
float result = 0.0;
char operatr = ' ';
 
void setup(){
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("Arduino Calculator");
  lcd.setCursor(0,1);
  lcd.print("by Phemmyte");
  delay(1000);
  srollDisplay();
  clr();
}
  
void loop(){
  char key = myKeypad.getKey();
  if (key!= NO_KEY && (key == '1' || key == '2' || key =='3' || key == '4' || key == '5' || key == '6' || key == '0')) {

    if (firstNumState == true) {
      firstNum = firstNum + key;

      lcd.print(key);
    }
    else {
      secondNum = secondNum + key;

      lcd.print(key);
    }
  }  
  if (key != NO_KEY && (key == '+' || key == '-' || key == '*' || key == '/')) { 
    if (firstNumState == true) {
      operatr = key;
      firstNumState = false;
      lcd.setCursor(15, 0);
      lcd.print(operatr);
      lcd.setCursor(5, 1);
    }
  }
  if (newKey != NO_KEY && newKey == '=') {
    if (operatr == '+') {
      result = firstNum.toFloat() + secondNum.toFloat();
    }

    if (operatr == '-') {
      result = firstNum.toFloat() - secondNum.toFloat();
    }

    if (operatr == '*') {
      result = firstNum.toFloat() * secondNum.toFloat();
    }

    if (operatr == '/') {
      result = firstNum.toFloat() / secondNum.toFloat();
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(firstNum);
    lcd.print(operatr);
    lcd.print(secondNum);
    lcd.setCursor(0, 1);
    lcd.print("=");
    lcd.print(result);
    firstNumState = true;
  }

  if (newKey != NO_KEY && newKey == 'C') {
    clr();
  }
}

void scrollDisplay() {
  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
  }
  delay(1000);

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(300);
  }
  delay(2000);
}

void clr() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1st: ");
  lcd.setCursor(12, 0);
  lcd.print("op ");
  lcd.setCursor(0, 1);
  lcd.print("2nd: ");
  lcd.setCursor(5, 0);
  firstNum = "";
  secondNum = "";
  result = 0;
  operatr = ' ';
}

