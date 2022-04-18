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
  {'8','9','C','='},
  {'*','/','-','+'}
};
byte rowPins[ROWS] = {3, 2, 8, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

boolean firstNumState = true; // initialised to true so that the firstNum will be entered
String firstNum = "";  // to hold the first set of input value from keypad
String secondNum = ""; //to hold the second set of input value from keypad
float result = 0.0; //to store the result of calculation
char operatr = ' '; //to store the operator
 
void setup(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Arduino Calculator");
  lcd.setCursor(0,1);
  lcd.print("by Phemmyte");
  delay(1000);
  scrollDisplay();
  clr();
}
  
void loop(){
  char key = myKeypad.getKey();
  if (key!= NO_KEY && (key == '1' || key == '2' || key =='3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')) {

    if (firstNumState == true) {
      firstNum = firstNum + key; //adding key pressed on keypad to string firstNum

      lcd.print(key); //printing pressed key
    }
    else { //to be executed when the firstNumState becomes false i.e. after the operator is entered
      secondNum = secondNum + key;

      lcd.print(key);
    }
  }  
  if (key != NO_KEY && (key == '+' || key == '-' || key == '*' || key == '/')) { 
    if (firstNumState == true) {
      operatr = key;
      firstNumState = false; // it becomes false since the operator as been pressed
      lcd.setCursor(15, 0);
      lcd.print(operatr);
      lcd.setCursor(5, 1);
    }
  }
  if (key != NO_KEY && key == '=') {
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

  if (key == 'C' && (key != NO_KEY)) {
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

