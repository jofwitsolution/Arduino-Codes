#include <LiquidCrystal.h>

const int rs=13, en=12, d4=11, d5=10, d6=9, d7=8;

LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(2, 0);
  lcd.println("SHELTER");
  
}

void loop()
{
  lcd.setCursor(0, 1);
  lcd.print("WELCOME TO SHELTER.");
  
  for(int x=0; x<16; x++) {
  lcd.scrollDisplayRight(); // Scroll display right 16 times
  delay(400);
  }
}
