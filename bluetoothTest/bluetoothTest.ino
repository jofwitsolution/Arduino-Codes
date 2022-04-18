#include <SoftwareSerial.h>

//SoftwareSerial BlueTooth(0, 1); // (TXD, RXD) of HC-05

String mode;

void setup() {
  // put your setup code here, to run once:
  //BlueTooth.begin(9600);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
//if (BlueTooth.available()) {
//      mode = BlueTooth.readString();
//      //Serial.println(mode);
//   }

if (Serial.available()) {
      mode = Serial.readString();
      //Serial.println(mode);
   }
}
