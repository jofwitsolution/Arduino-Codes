//define buttons according to analog voltage read
#include <SPI.h>
#include<LiquidCrystal.h>
#define button1  2644 
#define button2  1696
#define button3  2224
#define button4  352
#define button5  328
#define button6  348
#define button7  888
#define button8  744
#define button9  860
#define buttonAst  1756
#define button0  1276
#define buttonHashtag  1660 
#define buttonA  1984
#define buttonB  336
#define buttonC  796
#define buttonD  1440
LiquidCrystal lcd (7, 6, 5, 4, 3, 2);
#define toll 0.005
const int trigPin = 8;
const int echoPin = 9;
const int buzzer = 12;
long duration;
int distance, initialDistance, currentDistance, i;
int screenOffMsg = 0;
String password="1234";
String tempPassword;
boolean activated = false; // State of the alarm
boolean isActivated;
boolean activateAlarm = false;
boolean alarmActivated = false;
boolean enteredPassword; // State of the entered password to stop the alarm
boolean passChangeMode = false;
boolean passChanged = false; 
char keypressed;
long getDistance(){
//int i=10;  
//while( i<=10 ) {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);  
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance = duration*0.034/2;
//sumDistance += distance;
//}
//int averageDistance= sumDistance/10;
return distance;
}
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println("..booting");
   pinMode(buzzer, OUTPUT); // Set buzzer as an output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.setCursor(2,0);
  lcd.print("ULTRASONIC");
  lcd.setCursor(1,1);
  lcd.print("RANGE FINDER");
  delay(3000);
  lcd.clear();
}
 void enterPassword() {
  int k=5;
  tempPassword = "";
  activated = true;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" *** ALARM *** ");
  lcd.setCursor(0,1);
  lcd.print("Pass>");
  while (activated) {
    keypressed = getKeyPressed();
      if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
      keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
      keypressed == '8' || keypressed == '9' ) {
      tempPassword += keypressed;
      lcd.setCursor(k,1);
      lcd.print("*");
      k++;
}
if (k > 9 || keypressed == '#') {
  tempPassword = "";
  k = 5;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" *** ALARM *** ");
  lcd.setCursor(0,1);
  lcd.print("Pass>");
}
if (keypressed == '*') {
  if (tempPassword == password) {
    activated = false;
    alarmActivated = false;
    noTone(buzzer);
    screenOffMsg = 0; 
}
else if (tempPassword != password) {
lcd.setCursor(0,1);
lcd.print("Wrong! Try Again");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" *** ALARM *** ");
lcd.setCursor(0,1);
lcd.print("Pass>");
  }
}
  }
}


void loop() {
  keypressed = getKeyPressed();
  Serial.println(keypressed);
  delay(400);
  if (activateAlarm) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Alarm will be");
  lcd.setCursor(0,1);
  lcd.print("activated in");

  int countdown = 9;  // 9 seconds count down before activating the alarm
  while (countdown != 0) {
  lcd.setCursor(13,1);
  lcd.print(countdown);
  countdown--;
  tone(buzzer, 700, 100);
  delay(1000);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Alarm Activated!");
  initialDistance = getDistance();
  activateAlarm = false;
  alarmActivated = true;
}
  if (alarmActivated == true){
  currentDistance = getDistance() + 10;
  if ( currentDistance < initialDistance) {
  tone(buzzer, 1000); // Send 1KHz sound signal 
  lcd.clear();
  enterPassword();
}
}

  if (!alarmActivated) {
  if (screenOffMsg == 0) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A - Activate");
  lcd.setCursor(0,1);
  lcd.print("B - Change Pass");
  screenOffMsg == 1;
  }
  keypressed = getKeyPressed();
  if (keypressed == 'A'){ //If A is pressed, activate the alarm
    tone (buzzer, 1000, 200);
    activateAlarm = true;
    }
  else if (keypressed == 'B'){
      lcd.clear();
      int i = 1;
      tone(buzzer, 2000, 100);
      tempPassword = "";
      lcd.setCursor(0,0);
      lcd.print("Current Password");
      lcd.setCursor(0,1);
      lcd.print(">");
      passChangeMode = true;
      passChanged = true;
      while (passChanged) {
        keypressed = getKeyPressed();
      if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
      keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
      keypressed == '8' || keypressed == '9' ) {
      tempPassword += keypressed;
      lcd.setCursor(i,1);
      lcd.print("*");
      i++;
      tone(buzzer, 2000, 100);
      }
      if (i > 5 || keypressed == '#') {
      tempPassword = "";
      i=1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Current Password");
      lcd.setCursor(0,1);
      lcd.print(">"); 
      }
      if ( keypressed == '*') {
      i=1;
      tone(buzzer, 2000, 100);
      if (password == tempPassword) {
      tempPassword="";
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Set New Password");
      lcd.setCursor(0,1);
      lcd.print(">");
      while (passChangeMode) {
        keypressed = getKeyPressed();
      if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
      keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
      keypressed == '8' || keypressed == '9' ) {
      tempPassword += keypressed;
      lcd.setCursor(i,1);
      lcd.print("*");
      i++;
      tone(buzzer, 2000, 100);
      }
      }
      if (i > 5 || keypressed == '#') {
      tempPassword = "";
      i=1;
      tone(buzzer, 2000, 100);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Set New Password");
      lcd.setCursor(0,1);
      lcd.print(">");
}
  if (keypressed == '*') {
    i = 1;
    tone(buzzer, 2000, 100);
    password = tempPassword;
    passChangeMode = false;
    passChanged = false;
    screenOffMsg = 0;
}
}
}
}
}
}
}
char getKeyPressed (){
  int sensorValue = analogRead(A0);
  float voltage = sensorValue*(5000/1023);
  char buttonPressed;
    if (voltage>0) {

    if (voltage<=button1*(1+toll) && voltage>=button1*(1-toll)){
      buttonPressed = '1';
      }
      else if (voltage<=button2*(1+toll) && voltage>=button2*(1-toll)){
      buttonPressed = '2';
      }
      else if (voltage<=button3*(1+toll) && voltage>=button3*(1-toll)){
      buttonPressed = '3';
      }
      else if (voltage<=button4*(1+toll) && voltage>=button4*(1-toll)){
      buttonPressed = '4';
      }
      else if (voltage<=button5*(1+toll) && voltage>=button5*(1-toll)){
      buttonPressed = '5';
      }
      else if (voltage<=button6*(1+toll) && voltage>=button6*(1-toll)){
      buttonPressed = '6';
      }
      else if (voltage<=button7*(1+toll) && voltage>=button7*(1-toll)){
      buttonPressed = '7';
      }
      else if (voltage<=button8*(1+toll) && voltage>=button8*(1-toll)){
      buttonPressed = '8';
      }
      else if (voltage<=button9*(1+toll) && voltage>=button9*(1-toll)){
      buttonPressed = '9';
      }
      else if (voltage<=button0*(1+toll) && voltage>=button0*(1-toll)){
      buttonPressed = '0';
      }
      else if (voltage<=buttonAst*(1+toll) && voltage>=buttonAst*(1-toll)){
      buttonPressed = '*';
      }
      else if (voltage<=buttonHashtag*(1+toll) && voltage>=buttonHashtag*(1-toll)){
      buttonPressed = '#';
      }
      else if (voltage<=buttonA*(1+toll) && voltage>=buttonA*(1-toll)){
      buttonPressed = 'A';
      }
      else if (voltage<=buttonB*(1+toll) && voltage>=buttonB*(1-toll)){
      buttonPressed = 'B';
      }
      else if (voltage<=buttonC*(1+toll) && voltage>=buttonC*(1-toll)){
      buttonPressed = 'C';
      }
      else if (voltage<=buttonD*(1+toll) && voltage>=buttonD*(1-toll)){
      buttonPressed = 'D';
    }
    return buttonPressed;
  }
}
