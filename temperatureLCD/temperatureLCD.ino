//LM35 Pin Variables
int sensorPin = 0;// The analog pin the LM35's Vout is connected to.
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/*
Initialize serial connection with the computer*/
void setup(){
Serial.begin(9600); // Begin serial connection with the computer
lcd.begin(16,2);
//analogReference(INTERNAL);
pinMode(sensorPin, INPUT);
}
void loop()
{
int reading = analogRead(sensorPin); // read data from LM35 using Arduino (A0) pin
float temperatureC=reading*0.488;
//float voltage = reading *5.0; // Convert sensor data to voltage
//voltage /=1024.0;
Serial.println(reading);  // Print voltage on serial monitor
delay(500);
//float temperatureC=((100*1.1*voltage)/1024)*100;
float temperatureF=(temperatureC*(9.0/5.0))+32; //Convert voltage to temperature
Serial.print(temperatureC); Serial.println(" degrees C");// Print Temperature in C
// display Temperature on LCD
lcd.setCursor(0,0);
lcd.print("Temperature=");
lcd.setCursor(0,1);
lcd.print(temperatureC); lcd.println(" degrees C ");
delay(10);// print data every 10milliseconds
}
