#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

byte loading[8] = {
  0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11000, 0b11000, 0b00000
};

// make some custom characters:
byte heart[8] = {
  0b00000,// b means writing in binary
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte battEMPTY[8] = {
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b00000
};

byte battFULL[8] = {
  0b00000,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000
};

byte battHALF[8] = {
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b00000
};

byte battTHRID[8] = {
  0b00000,
  0b01110,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000
};
int button = 5;
int ACValue, VarDCValue, batteryValue;
float ACVoltage, VarDCVoltage, batteryVoltage;
float batLevel;
int batPercent;
unsigned long currentTime = 0;
unsigned long previousTime = 600000;
int relay1 = 6;
int relay2 = 7;
int buzzerPin = 4;
int ChargState = 0;
int initial = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(button, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(button, HIGH);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  
  // create loading character
  lcd.createChar(5, loading);
  
  // create battery characters
  // create a new character
  lcd.createChar(0, heart);
  // create a new character
  lcd.createChar(1, battEMPTY);
  // create a new character
  lcd.createChar(2, battFULL);
  // create a new character
  lcd.createChar(3, battHALF);
  // create a new character
  lcd.createChar(4, battTHRID);

  lcd.setCursor(0,0);
  lcd.print("RECHARGEABLE PSU");
  lcd.setCursor(1,1);
  lcd.print("Version 1.1.1");
  digitalWrite(buzzerPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
  delay(1000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Designed by");
  for (int i=0; i<16; i++) {
  lcd.setCursor(i, 1);
  lcd.write(byte(5));
  delay(120);
  //lcd.clear();
  }
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("CLASS 20 & 21");
  lcd.setCursor(2,1);
  lcd.print("SWEP GROUP 8");
  delay(2000);
  lcd.clear();
}

void loop() {
  
  ACValue = analogRead(A4);
  ACVoltage = (ACValue/1023.0)*5;
  ACVoltage = ACVoltage * 4 * 12.8;
  int ACVoltag = int(ACVoltage);
  Serial.println(ACVoltag);
  VarDCValue = analogRead(A3);
  VarDCVoltage = (VarDCValue/1023.0)*5;
  VarDCVoltage = VarDCVoltage * 4;

  batteryValue = analogRead(A5);
  batteryVoltage = (batteryValue/1023.0)*5;
  batteryVoltage = batteryVoltage * 4;
  if (ACVoltag > 220) {
  batteryVoltage = batteryVoltage - 1.2;
  }
  //calculations for the battery percentage is done below
  batLevel = batteryVoltage - 10.5;
  if (batLevel < 0.0) batLevel = 0.0;
  if (batLevel > 3.5) batLevel = 3.5;
  batPercent = mapf(batLevel, 0.0, 3.5, 0, 100);
  Serial.println(batPercent);
  if (batteryVoltage >= 14.0) {
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
    ChargState = 0;
  }
  else  {
    if ((currentTime + previousTime <= millis()) || initial == 1) {
    digitalWrite(relay1, LOW);
    currentTime = millis();
    ChargState = 1;
    }
  }
  if (batteryVoltage <= 10.5) {
    digitalWrite(relay2, HIGH);
    for (int x = 0; x<5; x++) {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
    }
  }
  if(digitalRead(button)==LOW) {
    lcd.clear();
    lcd.print("Rechargeable PSU");
    lcd.setCursor(0,1);
    lcd.print("ACin=");
    lcd.setCursor(5,1);
    lcd.print(ACVoltag);
    lcd.print("V");
    lcd.setCursor(10,1);
    lcd.print("B=");
    lcd.print(batPercent);
    lcd.print("%");
    delay(2000);
    lcd.clear();
  }
  
  if (VarDCVoltage > 9 || batPercent > 9) {
    lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Vout = ");
  lcd.print(VarDCVoltage);
  lcd.print("V");
  
       if (ACVoltag > 90 && ChargState == 1) {
        lcd.setCursor(2, 0);
        lcd.print("Battery");
        lcd.setCursor(13, 0);
        // draw battery Heart:
        lcd.write(byte(0));
        lcd.setCursor(15, 0);
        // draw battery empty:
        lcd.write(1);
        delay(100);
        lcd.setCursor(15, 0);
        // draw battery half:
        lcd.write(3);
        delay(200);
        lcd.setCursor(15, 0);
        // draw battery third:
        lcd.write(4);
        delay(200);
        lcd.setCursor(15, 0);
        // draw battery full:
        lcd.write(2);
        delay(200);
            }
      else {

          lcd.setCursor(1, 0);
          lcd.print("Battery");
          lcd.setCursor(9, 0);
          lcd.print(batPercent);
          lcd.print("%");
          if (batPercent <= 20) {
            lcd.setCursor(15, 0);
            // draw battery empty:
            lcd.write(1);
          }
          else if (batPercent > 20 && batPercent < 75) {
             lcd.setCursor(15, 0);
             // draw battery half:
             lcd.write(3);
          }
          else if (batPercent >= 75 && batPercent < 100) {
            lcd.setCursor(15, 0);
            // draw battery third:
            lcd.write(4);
          }
          else {
            lcd.setCursor(15, 0);
            // draw battery full:
            lcd.write(2);
          }
            }
  
  }
  else {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Vout = ");
    lcd.print(VarDCVoltage);
    lcd.print("V");

      if (ACVoltag > 90 && ChargState == 1) {
        lcd.setCursor(2, 0);
        lcd.print("Battery");
        lcd.setCursor(13, 0);
        // draw battery Heart:
        lcd.write(byte(0));
      lcd.setCursor(15, 0);
      // draw battery empty:
      lcd.write(1);
      delay(100);
      lcd.setCursor(15, 0);
      // draw battery half:
      lcd.write(3);
      delay(200);
      lcd.setCursor(15, 0);
      // draw battery third:
      lcd.write(4);
      delay(200);
      lcd.setCursor(15, 0);
      // draw battery full:
      lcd.write(2);
      delay(200);
      }
      else {

          lcd.setCursor(1, 0);
          lcd.print("Battery");
          lcd.setCursor(9, 0);
          lcd.print(batPercent);
          lcd.print("%");
          if (batPercent <= 20) {
            lcd.setCursor(15, 0);
            // draw battery empty:
            lcd.write(1);
          }
          else if (batPercent > 20 && batPercent < 75) {
             lcd.setCursor(15, 0);
             // draw battery half:
             lcd.write(3);
          }
          else if (batPercent >= 75 && batPercent < 100) {
            lcd.setCursor(15, 0);
            // draw battery third:
            lcd.write(4);
          }
          else {
            lcd.setCursor(15, 0);
            // draw battery full:
            lcd.write(2);
          }
            }
  
  }
  initial = 0;
  if (ChargState == 0 || ACVoltag < 90)  delay(800);  //when not charging 
}

int mapf(float x, float in_min, float in_max, int out_min, int out_max) {
  int result;
  result = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return result;
}

