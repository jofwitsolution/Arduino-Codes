#include <Adafruit_Sensor.h>

#include <DHT.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd (12,11,5,4,3,2);

DHT dht;

void setup() {
  pinMode(A0, INPUT);
  lcd.begin(16,2);
}

void loop() {
  dht.read11(A0);
  lcd.setCursor(0,0);
  lcd.print(DHT.humidity); 
}
