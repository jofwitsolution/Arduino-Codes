#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int relayIn = 8;
const int ldrPin = A1;
int ldrValue;
int ledPin = 7;
 
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(relayIn, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  ldrValue = analogRead(ldrPin); 
  Serial.print("ldr value=");
  Serial.println(ldrValue);
  delay(20);
  if (ldrValue>400) {
    digitalWrite(relayIn, HIGH);
    digitalWrite(ledPin, HIGH);
  }
  else { digitalWrite(relayIn, LOW);
         digitalWrite(ledPin, LOW);}
  
  lcd.cursor();
  lcd.print("YOU ARE WELCOME");
  delay(1000);
  lcd.setCursor(3,1);
  lcd.print("TO SHELTER");
  delay(2000);
  for(int x=0; x<16; x++) {
  lcd.scrollDisplayRight(); // Scroll display right 16 times
  delay(400); }
   lcd.clear(); 

   lcd.setCursor(1,1);
   lcd.print("LDRVALUE= ");
   lcd.print(ldrValue);
   delay(3000);
   lcd.clear();
  
}

