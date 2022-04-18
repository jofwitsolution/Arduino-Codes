#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

SoftwareSerial BlueTooth(2, 3); // (TXD, RXD) of HC-05

char BT_input;

String password = "1234"; //the default password

int buzzer = 7;   //to indicate access denied
int redLed = 7;   //to indicate access denied
int greenLed = 6; //to indicate access granted

byte keypressed;
String key1, key2, key3, key4, pass;  //to hold each keypad input for the four character password

void setup() {
  BlueTooth.begin(9600);
  Serial.begin(9600);  
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  pinMode(greenLed, OUTPUT);
  
  lcd.setCursor(3, 0);
  lcd.print("SHELTER");
  lcd.setCursor(1, 1);
  lcd.print("DOOR LOCKER");
  delay(2000);
  lcd.clear();
}

void loop() {
  //as long as no key is pressed i keep displaying on the lcd according to the code in this block
    lcd.home();
    lcd.setCursor(1, 0);
    lcd.print("Door locker v1");
    lcd.setCursor(0, 1);
    lcd.print("Press * 2Proceed");

    if (BlueTooth.available()) {
      BT_input=(BlueTooth.read());

  if (BT_input=='*') {   //checking for a '*' input on the lcd in order to enter password to unlock door
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
      while(keypressed2 == 16 ) {
        if (BlueTooth.available()) keypressed2=(BlueTooth.read()); 
      }
      key1 = keypressed2;
      lcd.setCursor(8,1);
      lcd.print(key1);   // '*' is printed on the lcd in order to hide the inputed password keys
      
      byte keypressed3 = 16;
      while(keypressed3 == 16 ) {
        if (BlueTooth.available()) keypressed3=(BlueTooth.read());
      }
      key2 = keypressed3;
      lcd.setCursor(9,1);
      lcd.print(key2);

      byte keypressed4 = 16;
      while(keypressed4 == 16 ) {
        if (BlueTooth.available()) keypressed4=(BlueTooth.read()); 
      }            
      key3 = keypressed4;
      lcd.setCursor(10,1);
      lcd.print(key3);

      byte keypressed5 = 16;
      while(keypressed5 == 16 ) {
        if (BlueTooth.available()) keypressed5=(BlueTooth.read()); 
      }            
      key4 = keypressed5;
      lcd.setCursor(11,1);
      lcd.print(key4);

      pass = key1 + key2 + key3 + key4;    // i concatenated the inputed password keys and store it in string pass
      if (passwordCheck(pass)) {  // the passwordCheck() returns true if pass correspond with the existing password and the code in this block is executed
        lcd.clear();              // if it return false, it jumps to else
        lcd.setCursor(0,0);
        lcd.print("loading...");
        BlueTooth.println("granted");
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
        BlueTooth.println("denied");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("loading...");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Access Denied");       
        failureAlert(); //buzzer sounds for 2secs and redLed also ON
        lcd.clear();
      }
    }

   if (BT_input=='#') {     //checking for setup button pressed on the keypad in order to enter password change setup
      lcd.clear();
      lcd.print("Entering.....");
      lcd.setCursor(0,1);
      lcd.print("Password Setup");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Change Password");
      lcd.setCursor(0,1);
      lcd.print("Enter prev: ");

      byte keypressed2 = 16;
      
      //here the screen is paused until a key is pressed
      while(keypressed2 == 16 ) {
        if (BlueTooth.available()) keypressed2=(BlueTooth.read()); 
      }        
      
      //The lcd wait for the previuos password to be inputed
      
      key1 = keypressed2;
      lcd.setCursor(11,1);
      lcd.print(key1);
      
      byte keypressed3 = 16;
      while(keypressed3 == 16 ) {
        if (BlueTooth.available()) keypressed3=(BlueTooth.read()); 
      }        
      key2 = keypressed3;
      lcd.setCursor(12,1);
      lcd.print(key2);

      byte keypressed4 = 16;
      while(keypressed4 == 16 ) {
        if (BlueTooth.available()) keypressed4=(BlueTooth.read()); 
      }        
      key3 = keypressed4;
      lcd.setCursor(13,1);
      lcd.print(key3);

      byte keypressed5 = 16;
      while(keypressed5 == 16 ) {
        if (BlueTooth.available()) keypressed5=(BlueTooth.read()); 
      }        
      key4 = keypressed5;
      lcd.setCursor(14,1);
      lcd.print(key4);

      pass = key1 + key2 +key3 + key4;
      
      if (passwordCheck(pass)) {  //  The code in this block is excuted if the entered password is equal to the existing one
        lcd.clear();              // otherwise go to else
        lcd.setCursor(0,0);
        BlueTooth.println("correct");
        lcd.print("New Password");
        lcd.setCursor(0,1);
        lcd.print("Enter: ");

        byte keypressed2 = 16;
      
      //here the screen is paused until a key is pressed
      while(keypressed2 == 16 ) {
        if (BlueTooth.available()) keypressed2=(BlueTooth.read()); 
      }
      key1 = keypressed2;
      lcd.setCursor(8,1);
      lcd.print(key1);   // '*' is printed on the lcd in order to hide the inputed password keys
      
      byte keypressed3 = 16;
      while(keypressed3 == 16 ) {
        if (BlueTooth.available()) keypressed3=(BlueTooth.read()); 
      }      
      key2 = keypressed3;
      lcd.setCursor(9,1);
      lcd.print(key2);

      byte keypressed4 = 16;
      while(keypressed4 == 16 ) {
        if (BlueTooth.available()) keypressed4=(BlueTooth.read()); 
      }            
      key3 = keypressed4;
      lcd.setCursor(10,1);
      lcd.print(key3);

      byte keypressed5 = 16;
      while(keypressed5 == 16 ) {
        if (BlueTooth.available()) keypressed5=(BlueTooth.read()); 
      }            
      key4 = keypressed5;
      lcd.setCursor(11,1);
      lcd.print(key4);

      pass = key1 + key2 +key3 + key4;
      password = pass;    //assigning the new password
      BlueTooth.println("pswdChngSucc");
      delay(1000);
      lcd.clear();
      lcd.print("Password change");
      lcd.setCursor(2,1);
      lcd.print("Successful");
      successAlert();   //greenLed blink twice for password change success
      lcd.clear();
    }

    else {  //If the previous password entered is wrong
       lcd.clear();
       lcd.setCursor(0,0);
       BlueTooth.println("wrong");
       lcd.print("Wrong Password");
       delay(1000);
       lcd.setCursor(3,1);
       lcd.print("Try again");
       failureAlert();
       lcd.clear();
    }
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
void successAlert() {
      digitalWrite(greenLed, HIGH);
      delay(500);
      digitalWrite(greenLed, LOW);
      delay(500);
      digitalWrite(greenLed, HIGH);
      delay(500);
      digitalWrite(greenLed, LOW);
}

