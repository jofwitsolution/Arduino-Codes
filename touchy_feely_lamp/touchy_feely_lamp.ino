//include the capacitiveSensor library
#include <CapacitiveSensor.h>
//create an instance of the capacitiveSensor library
//and identify what pin it will use
//pin 4 is the send pin, pin 2 is the sensor pin
CapacitiveSensor capSensor = capacitiveSensor(4,2);

//vriable to determine threshold at which light will turn on
int threshold = 1000;

cont int ledPin= 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //read the sensor value into a local variable
  //the argument is the number of sample the sensor takes
  long sensorValue = capSensor.capacitiveSensor(30);

  Serial.println(sensorValue);

  //use an if...else statement to determine if the sensor has
  //a higher value than the threshold
  if (sensorValue > threshold){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  delay(10);
}
