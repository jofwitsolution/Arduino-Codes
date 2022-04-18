#include <SPI.h>
#include <Keypad.h>
#include <ShiftedLCD.h>

// initialize the library with the number of the sspin 
//(or the latch pin of the 74HC595)
//LiquidCrystal lcd(10);
const int trigPin = 8;
const int echoPin = 7;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
//  lcd.begin(16,2);
//  lcd.setCursor(2,0);
//  lcd.print("ULTRASONIC");
//  lcd.setCursor(1,1);
//  lcd.print("RANGE FINDER");
//  delay(3000);
//  lcd.clear();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // to wake up the circuitry

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // to send out a burst of ultrasound wave
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); //for how long the echoPin was high is stored in duration
  distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
//  delay(1000);
//  lcd.print("Distance=");
//  lcd.setCursor(10,0);
//  lcd.print(distance);
//  delay(500);
//  lcd.setCursor(14,0);
//  lcd.print("cm");
  
  
}
