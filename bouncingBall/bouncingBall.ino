#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 10, d5= 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte bouncingBall[8] = {
  0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11000, 0b11000, 0b00000
};
int x = 1;

void setup() {
  Serial.begin(9600);
  //create a new custom char
  lcd.createChar(0, bouncingBall);
  lcd.begin(16, 2);
  for (int i=15; i>=0; i--) {
  lcd.setCursor(i, x);
  lcd.write(byte(0));
  delay(200);
  lcd.clear();
  if (x == 1) x = 0;
  else x = 1;
  }  
  
}

void loop() {
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Bouncing");
  lcd.setCursor(6, 1);
  lcd.print("Ball");
  delay(2000);
  lcd.clear();
  for (int i=0; i<16; i++) {
  lcd.setCursor(i, x);
  lcd.write(byte(0));
  delay(400);
  lcd.clear();
  if (x == 1) x = 0;
  else x = 1;
  }  
}
