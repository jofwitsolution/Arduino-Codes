const int redLed = 13;
const int yellowLed = 12;
const int greenLed = 11;
byte com = 0;
byte input = 0;
int one = 0;
int two = 0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
  delay(2000);
  Serial.write(0xAA);
  Serial.write(0x37);
  delay(1000);
  Serial.write(0xAA);
  Serial.write(0x23);

}

void loop() {
// put your main code here, to run repeatedly:
//  while (Serial.available()) {
//    input = Serial.read();
//    Serial.println(input);
//    switch(com) {
//      case 0x12: digitalWrite(redLed, HIGH);
//      break;
//      case 0x13: digitalWrite(blueLed, HIGH);
//      break;
//      case 0x14: digitalWrite(greenLed, HIGH);
//      break;
//      case 0x15: offLeds();
//      break;
//    }
//  }
  
  while (Serial.available()) {
    com = Serial.read();
    Serial.println(com);
    switch(com) {
      case 0x11: digitalWrite(redLed, HIGH);
      break;
      case 0x12: digitalWrite(yellowLed, HIGH);
      break;
      case 0x13: digitalWrite(greenLed, HIGH);
      break;
      case 0x14: onLeds();
      break;
      case 0x15: offLeds();
      break;
      
    }

//  switch(com) {
//      case 0x11: one = 1;
//      break;
//      case 0x12: two = 2;
//      break;
//  }
//
//  if (one == 1 && two == 2) {
//    digitalWrite(redLed, HIGH);
//    one = 0;
//    two = 0;
//   }
  }
 }

void offLeds() {
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
}

void onLeds() {
  digitalWrite(redLed, HIGH);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(greenLed, HIGH);
}

