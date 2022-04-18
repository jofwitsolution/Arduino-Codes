#include <SoftwareSerial.h>
SoftwareSerial BlueTooth(2, 3); // (TXD, RXD) of HC-05

char BT_input; // to store input character received via BT.

void setup()  
{
  pinMode(13, OUTPUT);     // Arduino Board LED Pin
  BlueTooth.begin(9600);
  Serial.begin(9600);  
}

void loop() 
{
  if (BlueTooth.available())
  //if (Serial.available())
 
  {
    BT_input=(BlueTooth.read());
    //BT_input=(Serial.read());
    if (BT_input=='1')
    {
      digitalWrite(13, HIGH);
      BlueTooth.println(" LED ON"); //talking to the master after it has already initialize communication
      Serial.println(BT_input);
      Serial.println(" LED ON");
    }
    else if (BT_input=='0')
    {
      digitalWrite(13, LOW);
      BlueTooth.println(" LED OFF");  //talking to the master after it has already initialize communication
      Serial.println(BT_input);
      Serial.println(" LED OFF");
    }

  }
}

