#include<LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5= 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte handsDown[8] = {
  0b00100, 0b00100, 0b01010, 0b10101, 0b00100, 0b01110, 0b01010, 0b00000
};

byte handsUp[8] = {
  0b00100, 0b10101, 0b01010, 0b00100, 0b00100, 0b01110, 0b01010, 0b00000
};

byte ball1[8] = {
  0b00000, 0b00000, 0b00001, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000
};

byte ball2[8] = {
  0b00000, 0b00000, 0b10000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000
};
int x = 1;
long int Delay = 10000;
int timer = 1;
void setup() {
  Serial.begin(9600);
  //create a new custom char
  lcd.createChar(0, handsDown);
  lcd.createChar(1, handsUp);
  lcd.createChar(2, ball1);
  lcd.createChar(2, ball2);
  lcd.begin(16, 2);
  //print the custom char HandDown to the lcd
  lcd.setCursor(6, 0);
  lcd.write(byte(0)); //when calling lcd.write() '0' must be cast as a byte
  delay(500);
  lcd.setCursor(6, 0);
  lcd.write(byte(1));
  delay(1000);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Two men");
  lcd.setCursor(0, 1);
  lcd.print("Bouncing Ball");
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
  lcd.write(byte(1));
  delay(100);
  for (int i=1; i<15; i++) {
  lcd.setCursor(i, x);
  lcd.write(byte(2));
  delay(200);
  lcd.clear();
  if (x == 1) x = 0;
  else x = 1;
  }
  lcd.setCursor(15, 1);
  lcd.write(byte(0));
  lcd.setCursor(15, 1);
  lcd.write(byte(1));
  delay(400);
  x = 0;
  for (int i=14; i>=1; i--) {
  lcd.setCursor(i, x);
  lcd.write(byte(2));
  delay(200);
  lcd.clear();
  if (x == 1) x = 0;
  else x = 1;
  }
  
  if (millis() > Delay) {
  Delay = Delay + 10000;
  timer = timer + 1;
}
if (timer == 2){
    lcd.clear();
    lcd.setCursor(4, 0);
  lcd.print("Two men");
  lcd.setCursor(0, 1);
  lcd.print("Bouncing Ball");
  delay(2000);
  lcd.clear();
  }
if (timer == 2){
  timer = 0;
}

 }
