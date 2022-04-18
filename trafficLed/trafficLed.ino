
int redLedPin = 13;
int yellLedPin = 12;
int greenLedPin = 11;

void setup() {

  pinMode(redLedPin, OUTPUT);
  pinMode(yellLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  digitalWrite(redLedPin, HIGH);
   digitalWrite(yellLedPin, LOW);
  digitalWrite(greenLedPin,LOW);
  delay(10000);
  
  digitalWrite(redLedPin, HIGH);
   digitalWrite(yellLedPin, HIGH);
  digitalWrite(greenLedPin,LOW);
  delay(3000);
  digitalWrite(redLedPin, LOW);
   digitalWrite(yellLedPin, LOW);
  digitalWrite(greenLedPin,HIGH);
  delay(10000);
  digitalWrite(redLedPin, LOW);
   digitalWrite(yellLedPin, HIGH);
  digitalWrite(greenLedPin,HIGH);
  delay(3000);
  
}
