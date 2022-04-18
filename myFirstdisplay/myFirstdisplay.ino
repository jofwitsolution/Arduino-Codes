#include <LiquidCrystal.h>

const int rs=12, en=11, d4=13, d5=10, d6=9, d7=2;

LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

void setup()
{
  lcd.begin(16,2);
}
void loop()
{
  lcd.cursor();
  lcd.print("YOU ARE WELCOME");
  delay(1000);
  lcd.setCursor(3,1);
  lcd.print("TO SHELTER");
  delay(2000);
  for(int x=0; x<16; x++) {
  lcd.scrollDisplayRight(); // Scroll display right 16 times
  delay(400);
}
  lcd.clear();
  lcd.print("HOME OF DIGITAL");
  delay(1000);
  lcd.setCursor(2, 1);
  lcd.print("ELECTRONICS");
  delay(2000);
   for(int x=0; x<16; x++) {
  lcd.scrollDisplayLeft(); // Scroll display right 16 times
  delay(400);
}
  lcd.clear();
  lcd.clear();
  lcd.print("FOR ELECTRONIC");
  delay(1000);
  lcd.setCursor(4, 1);
  lcd.print("DESIGNS");
  delay(2000);
   for(int x=0; x<16; x++) {
  lcd.scrollDisplayRight(); // Scroll display right 16 times
  delay(400);
}
  lcd.clear();
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("PATRONIZE");
  delay(1000);
  lcd.setCursor(3, 1);
  lcd.print("SHELTER");
  delay(2000);
   for(int x=0; x<16; x++) {
  lcd.scrollDisplayLeft(); // Scroll display right 16 times
  delay(400);
}
  lcd.clear();
}

