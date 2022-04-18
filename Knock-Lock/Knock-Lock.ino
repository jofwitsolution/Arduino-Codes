#include <Servo.h>

Servo myServo;

const int piezo = A0; // pin the piezo is attached to
const int switchPin = 2; // pin the switch is attached to
const int yellowLed = 3; // pin the yellow LED is attached to
const int greenLed = 4; // pn the green LED is attached to
const int redLed = 8; // pin the red LED is attached to

// variable for the piezo value
int knockVal;
// variable for the switch value
int switchVal;

// variable for the high and low limits of the knock value
const int quietKnock = 10;
const int loudKnock = 400;

// variable to indicate if locked or not
bool locked = false;
// how many valid knocks you've received
int numberOfKnocks = 0;

void setup() {
  // attach the servo to pin 9
  myServo.attach(5);

  // make the led pins output
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  // set the switch pin as an input
  pinMode(switchPin, INPUT);

  Serial.begin(9600);

  digitalWrite(greenLed, HIGH);

  // move the servo to the unlocked position
  myServo.write(0);

  //print status to the serial monitor
  Serial.println("the box is unlocked!");
}

void loop() {

  // if the box is unlocked
  if (locked == false) {

    // read the value of the switch pin
    switchVal = digitalRead(switchPin);

    // if the button is pressed lock the box
    if (switchVal == HIGH) {
      // set the locked varaible to "true"
      locked = true;

      // change the status LEDs
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);

      // move the servo to the locked position
      myServo.write(90);

      // print out status
      Serial.println("the box is locked!");

      // wait for the servo to move into position
      delay(1000);
    }
  }

  // if the box is locked
  if (locked == true) {

    // check the value of the piezo
    knockVal = analogRead(piezo);
    Serial.println(knockVal);
    delay(400);

    // if there are not enough valid knocks
    if (numberOfKnocks < 3 && knockVal > 0) {

      //check to see if the knock is in range
      if (checkForKnock(knockVal) == true) {

        // increment the number of valid knocks
        numberOfKnocks++;
      }

      //print status of knocks
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }

    // if there are three knocks
    if (numberOfKnocks >= 3) {
      // unlock the box
      locked = false;

      // move the servo to the unlocked position
      myServo.write(0);

      // wait for it to move
      delay(20);

      // change status LEDs
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("the box is unlocked!");

      numberOfKnocks = 0;
    }
  }
}

// this function check to see if a detected knock is within maximum and minimum range
bool checkForKnock(int value) {
  // if the value of the knock is greater than the minimum and larger than the maximum
  if (value > quietKnock && value < loudKnock) {
    // turn the status LED on
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    // print out the status
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }
  // if the knock is not within range
  else {
    // print status
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false; 
  }
}

