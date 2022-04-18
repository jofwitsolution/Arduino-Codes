// Project 27
#include <Servo.h>
Servo servo1; // Create a servo object
int pot1;
void setup()
{
servo1.attach(5); // Attaches the servo on pin 5 to the servo1 object
servo1.write(90); // Put servo1 at home position
}
void loop()
{
pot1 = analogRead(3); // Read the X-Axis
pot1 = map(pot1,0,1023,0,180);
servo1.write(pot1);
delay(15);
}
