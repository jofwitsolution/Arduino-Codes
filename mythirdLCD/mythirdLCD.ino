//LM35 Pin Variables
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int sensorPin = 0;// The analog pin the LM35's Vout is connected to.
const int ledPin = 9; //the number of the LED Pin
/*
Initialize serial connection with the computer*/
void setup()
{
  lcd.begin(16,2);
Serial.begin(9600); // Begin serial connection with the computer
pinMode(ledPin, OUTPUT);
pinMode(sensorPin, INPUT);
}
void loop()
{
int reading = analogRead(sensorPin); // read data from LM35 using Arduino (A0) pin
float voltage = reading *5.0; // Convert sensor data to voltage
voltage /= 1024.0;
Serial.print(voltage); Serial.println("volts"); // Print voltage on serial monitor
float temperatureC=(0.5-voltage)*100;
//float temperatureF=(temperatureC*9.0/5.0)+32; //Convert voltage to temperature
Serial.println(temperatureC); //Serial.println("degrees F");// Print Temperature in C
if(temperatureC >30){
digitalWrite(ledPin, HIGH);
delay(1000);
digitalWrite(ledPin, LOW);
delay(1000);

}
else{
digitalWrite(ledPin, HIGH);
delay(100);
digitalWrite(ledPin, LOW);
delay(100);
}
lcd.setCursor(0,0);
lcd.print(temperatureC);
lcd.setCursor(6, 1); 
lcd.println(" degrees C ");
delay(10);// print data every 10milliseconds
}
