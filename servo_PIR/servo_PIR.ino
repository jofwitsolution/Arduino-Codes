#include <Servo.h>

Servo myservo;
#define sensor1 11
#define sensor2 12
int val;
int pos = 90;
void setup() {
  myservo.attach(9);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
}

void loop() {
  int sensorOutput1 = digitalRead(sensor1);
  int sensorOutput2 = digitalRead(sensor1);

  if (sensorOutput1 == LOW) {
  //for ( pos <= 180; pos++) {
    myservo.write(180);
    delay(15);
  }
  
  else if (sensorOutput2 == LOW) {
   // for (pos >= 0; pos--; ) {
  myservo.write(0);
  delay(15);
  }
  else myservo.write(pos);
  
}

