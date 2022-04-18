#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

String password = "1234"; //the default password

const int rowOne = 7, rowTwo = 6, rowThree = 5, rowFour = 4;    
const int colOne = A0, colTwo = A1, colThree = A2, colFour = A3;  //column scanning

int buzzer = 2;   //to indicate access denied
int redLed = 2;   //to indicate access denied
int greenLed = 3; //to indicate access granted

byte keypressed;
String key1, key2, key3, key4, pass;  //to hold each keypad input for the four character password

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  pinMode(greenLed, OUTPUT);
  //pinMode(red
  for(int i = 4; i <= 7; i++)//set row pins to output
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

  lcd.setCursor(3, 0);
  lcd.print("SHELTER");
  lcd.setCursor(1, 1);
  lcd.print("DOOR LOCKER");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (keypad()==16) {   //as long as no key is pressed i keep displaying on the lcd according to the code in this block
    lcd.home();
    lcd.setCursor(1, 0);
    lcd.print("Door locker v1");
    lcd.setCursor(0, 1);
    lcd.print("Press * 2Proceed");
  }
  if (keypad()==10) {   //checking for a '*' input on the lcd in order to enter password to unlock door
    lcd.clear();
    lcd.print("Loading....");
    delay(1000);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Enter Password");
    lcd.setCursor(0,1);
    lcd.print("Passwd: ");
    byte keypressed2 = 16;
      
      //here the screen is paused until a key is pressed
      while(keypressed2 == 16 && keypressed2 != 10 && keypressed2 != 11 && keypressed2 != 12 && keypressed2 != 13 && keypressed2 != 14 && keypressed2 != 15) keypressed2 = keypad();  
      delay(500);
      key1 = keypressed2;
      lcd.setCursor(8,1);
      lcd.print("*");   // '*' is printed on the lcd in order to hide the inputed password keys
      
      byte keypressed3 = 16;
      while(keypressed3 == 16 && keypressed3 != 10 && keypressed3 != 11 && keypressed3 != 12 && keypressed3 != 13 && keypressed3 != 14 && keypressed3 != 15 ) keypressed3 = keypad(); 
      delay(500);
      key2 = keypressed3;
      lcd.setCursor(9,1);
      lcd.print("*");

      byte keypressed4 = 16;
      while(keypressed4 == 16 && keypressed4 != 10 && keypressed4 != 11 && keypressed4 != 12 && keypressed4 != 13 && keypressed4 != 14 && keypressed4 != 15 ) keypressed4 = keypad(); 
      delay(500);
      key3 = keypressed4;
      lcd.setCursor(10,1);
      lcd.print("*");

      byte keypressed5 = 16;
      while(keypressed5 == 16 && keypressed5 != 10 && keypressed5 != 11 && keypressed5 != 12 && keypressed5 != 13 && keypressed5 != 14 && keypressed5 != 15 ) keypressed5 = keypad(); 
      delay(500);
      key4 = keypressed5;
      lcd.setCursor(11,1);
      lcd.print("*");

      pass = key1 + key2 +key3 + key4;    // i concatenated the inputed password keys and store it in string pass
      if (passwordCheck(pass)) {  // the passwordCheck() returns true if pass correspond with the existing password and the code in this block is executed
        lcd.clear();              // if it return false, it jumps to else
        lcd.setCursor(0,0);
        lcd.print("loading...");
        delay(1000);
        lcd.setCursor(1,1);
        lcd.print("Access Granted");
        successAlert();
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Welcome to");
        lcd.setCursor(0,1);
        lcd.print("Shelter Electro.");
        delay(3000);
        }

     else {   // this is executed if the inputed password is wrong
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("loading...");
        delay(1000);
        lcd.setCursor(1,1);
        lcd.print("Access Denied");
        failureAlert(); //buzzer sounds for 2secs and redLed also ON
      }
    }

   if (keypad()==12) {     //checking for setup button pressed on the keypad in order to enter password change setup
      lcd.clear();
      lcd.print("Entering.....");
      lcd.setCursor(0,1);
      lcd.print("Password Setup");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Password change");
      lcd.setCursor(0,1);
      lcd.print("Enter prev: ");

      byte keypressed2 = 16;
      
      //here the screen is paused until a key is pressed
      while(keypressed2 == 16 && keypressed2 != 10 && keypressed2 != 11 && keypressed2 != 12 && keypressed2 != 13 && keypressed2 != 14 && keypressed2 != 15) keypressed2 = keypad();  
      delay(500);
      
      //The lcd wait for the previuos password to be inputed
      
      key1 = keypressed2;
      lcd.setCursor(11,1);
      lcd.print("*");
      
      byte keypressed3 = 16;
      while(keypressed3 == 16 && keypressed3 != 10 && keypressed3 != 11 && keypressed3 != 12 && keypressed3 != 13 && keypressed3 != 14 && keypressed3 != 15 ) keypressed3 = keypad(); 
      delay(500);
      key2 = keypressed3;
      lcd.setCursor(12,1);
      lcd.print("*");

      byte keypressed4 = 16;
      while(keypressed4 == 16 && keypressed4 != 10 && keypressed4 != 11 && keypressed4 != 12 && keypressed4 != 13 && keypressed4 != 14 && keypressed4 != 15 ) keypressed4 = keypad(); 
      delay(500);
      key3 = keypressed4;
      lcd.setCursor(13,1);
      lcd.print("*");

      byte keypressed5 = 16;
      while(keypressed5 == 16 && keypressed5 != 10 && keypressed5 != 11 && keypressed5 != 12 && keypressed5 != 13 && keypressed5 != 14 && keypressed5 != 15 ) keypressed5 = keypad(); 
      delay(500);
      key4 = keypressed5;
      lcd.setCursor(14,1);
      lcd.print("*");

      pass = key1 + key2 +key3 + key4;
      
      if (passwordCheck(pass)) {  //  The code in this block is excuted if the entered password is equal to the existing one
        lcd.clear();              // otherwise go to else
        lcd.setCursor(0,0);
        lcd.print("New Password");
        lcd.setCursor(0,1);
        lcd.print("Enter: ");

        byte keypressed2 = 16;
      
      //here the screen is paused until a key is pressed
      while(keypressed2 == 16 && keypressed2 != 10 && keypressed2 != 11 && keypressed2 != 12 && keypressed2 != 13 && keypressed2 != 14 && keypressed2 != 15) keypressed2 = keypad();  
      delay(500);

      //The lcd wait for new password to be inputed
      
      key1 = keypressed2;
      lcd.setCursor(8,1);
      lcd.print("*");
      
      byte keypressed3 = 16;
      while(keypressed3 == 16 && keypressed3 != 10 && keypressed3 != 11 && keypressed3 != 12 && keypressed3 != 13 && keypressed3 != 14 && keypressed3 != 15 ) keypressed3 = keypad(); 
      delay(500);
      key2 = keypressed3;
      lcd.setCursor(9,1);
      lcd.print("*");

      byte keypressed4 = 16;
      while(keypressed4 == 16 && keypressed4 != 10 && keypressed4 != 11 && keypressed4 != 12 && keypressed4 != 13 && keypressed4 != 14 && keypressed4 != 15 ) keypressed4 = keypad(); 
      delay(500);
      key3 = keypressed4;
      lcd.setCursor(10,1);
      lcd.print("*");

      byte keypressed5 = 16;
      while(keypressed5 == 16 && keypressed5 != 10 && keypressed5 != 11 && keypressed5 != 12 && keypressed5 != 13 && keypressed5 != 14 && keypressed5 != 15 ) keypressed5 = keypad(); 
      delay(500);
      key4 = keypressed5;
      lcd.setCursor(11,1);
      lcd.print("*");

      pass = key1 + key2 +key3 + key4;
      password = pass;
      delay(1000);
      lcd.clear();
      lcd.print("Password change");
      lcd.setCursor(2,1);
      lcd.print("Successful");
      successAlert();   //greenLed blink twice for password change success
    }

    else {  //If the previous password entered is wrong
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Wrong Password");
       delay(1000);
       lcd.setCursor(3,1);
       lcd.print("Try again");
       failureAlert();
    }
  }
}
bool passwordCheck(String pass) { // to perform password check
  if (pass==password) return true;
  else return false;
}

void failureAlert() {
  digitalWrite(redLed, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(2000);
  analogWrite(redLed, LOW);
   digitalWrite(buzzer, LOW);
}
byte keypad()
{
  digitalWrite(rowOne, HIGH);
  digitalWrite(rowTwo, LOW);
  digitalWrite(rowThree, LOW);
  digitalWrite(rowFour, LOW);
  if(analogRead(colOne) > 512) return 1;
  if(analogRead(colTwo) > 512) return 2;
  if(analogRead(colThree) > 512) return 3;
  if(analogRead(colFour) > 512) return 12;
  
  digitalWrite(rowOne, LOW);
  digitalWrite(rowTwo, HIGH);
  digitalWrite(rowThree, LOW);
  digitalWrite(rowFour, LOW);
  if(analogRead(colOne) > 512) return 4;
  if(analogRead(colTwo) > 512) return 5;
  if(analogRead(colThree) > 512) return 6;
  if(analogRead(colFour) > 512) return 13;
  
  digitalWrite(rowOne, LOW);
  digitalWrite(rowTwo, LOW);
  digitalWrite(rowThree, HIGH);
  digitalWrite(rowFour, LOW);
  if(analogRead(colOne) > 512) return 7;
  if(analogRead(colTwo) > 512) return 8;
  if(analogRead(colThree) > 512) return 9;
  if(analogRead(colFour) > 512) return 14;
  
  digitalWrite(rowOne, LOW);
  digitalWrite(rowTwo, LOW);
  digitalWrite(rowThree, LOW);
  digitalWrite(rowFour, HIGH);
  if(analogRead(colOne) > 512) return 10;
  if(analogRead(colTwo) > 512) return 0;
  if(analogRead(colThree) > 512) return 11;
  if(analogRead(colFour) > 512) return 15;

  return 16;
}
void successAlert() {
      digitalWrite(greenLed, HIGH);
      delay(500);
      digitalWrite(greenLed, LOW);
      delay(500);
      digitalWrite(greenLed, HIGH);
      delay(500);
      digitalWrite(greenLed, LOW);
}

