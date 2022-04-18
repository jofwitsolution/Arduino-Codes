#include <LiquidCrystal.h>

//const int sensorIn = A1;
//const int voltaIn = A0;
int mVperAmp = 66;
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  pinMode(A0, INPUT);

Serial.begin(9600);
Serial.println("wattage");

}

void loop() {
 
  int readv = analogRead(A0);
  int VRMS = analogRead(A1);
  //double cal = 
  double readval = ((readv*4.37)/1023 * 51.34) ;
 
  float voltage=(VRMS * 4.97)/1023;
   float real_voltage= voltage - 2.49;
  double  AmpsRMS = (real_voltage * 1000)/mVperAmp;
   Serial.println("Voltage = " );
   Serial.println(readval);
   Serial.println("Current = ");
   Serial.println(AmpsRMS);
   
   delay(500);
  
  
}
