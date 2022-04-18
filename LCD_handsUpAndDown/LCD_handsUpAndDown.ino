#include<LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5= 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte handsDown[8] = {
  0b00100, 0b00100, 0b01010, 0b10101, 0b00100, 0b01110, 0b01010, 0b00000
};

byte handsUp[8] = {
  0b00100, 0b10101, 0b01010, 0b00100, 0b00100, 0b01110, 0b01010, 0b00000
};
void setup() {
  Serial.begin(9600);
  //create a new custom char
  lcd.createChar(0, handsDown);
  lcd.createChar(1, handsUp);
  lcd.begin(16, 2);
  //print the custom char HandDown to the lcd
  lcd.setCursor(6, 0);
  lcd.write(byte(0)); //when calling lcd.write() '0' must be cast as a byte
  delay(500);
  lcd.setCursor(6, 0);
  lcd.write(byte(1));
  delay(1000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(2, 0);
  lcd.print("Mariam hands");
  
  lcd.setCursor(7, 1);
  lcd.write(byte(0));
  delay(500);
  lcd.setCursor(7, 1);
  lcd.write(byte(1));
  delay(500);

  lcd.setCursor(1, 1);
  lcd.print("Up");
  lcd.setCursor(9, 1);
  lcd.print("Down");
}
