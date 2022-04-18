#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

byte loading[8] = {
  0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11000, 0b11000, 0b00000
};
int button = 4;
int ACValue, DCValue;
float ACVoltage, DCVoltage;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
  lcd.createChar(0, loading);
  
  lcd.setCursor(0,0);
  lcd.print("MULTIPURPOSE PSU");
  lcd.setCursor(1,1);
  lcd.print("Version 1.1.1");
  delay(2000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Designed by");
  for (int i=0; i<16; i++) {
  lcd.setCursor(i, 1);
  lcd.write(byte(0));
  delay(120);
  //lcd.clear();
  }
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("PHEMMYTE");
  lcd.setCursor(2,1);
  lcd.print("ELECTRONICS");
  delay(2000);
  lcd.clear();
}

void loop() {
  
  ACValue = analogRead(A5);
  ACVoltage = (ACValue/1023.0)*5;
  ACVoltage = ACVoltage * 5 * 15;
  int ACVoltag = int(ACVoltage);
  
  DCValue = analogRead(A4);
  DCVoltage = (DCValue/1023.0)*5;
  DCVoltage = DCVoltage * 5;

  if(digitalRead(button)==LOW) {
    lcd.clear();
    lcd.print("PHEMMYTE DESIGN");
    lcd.setCursor(1,1);
    lcd.print("AC Input = ");
    lcd.setCursor(12,1);
    lcd.print(ACVoltag);
    delay(2000);
    lcd.clear();
  }

  if (DCVoltage > 9) {
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Freq = 50.000 Hz");
  lcd.setCursor(0,1);
  lcd.print("Vout = ");
  lcd.print(DCVoltage);
  lcd.print("V");
  }
  else {
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Freq = 50.000 Hz");
  lcd.setCursor(0,1);
  lcd.print("Vout = ");
  lcd.print(DCVoltage);
  lcd.print("V");
  }
  delay(800);
}
