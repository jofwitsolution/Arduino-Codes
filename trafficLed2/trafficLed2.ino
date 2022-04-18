int redLedPin = 13;
int yellLedPin = 12;
int greenLedPin = 11;

void setup() {

  pinMode(redLedPin, OUTPUT);
  pinMode(yellLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}
void loop() {
  for (int c=0; c<5; c++)
  {
     digitalWrite(redLedPin, HIGH);
   digitalWrite(yellLedPin, LOW);
  digitalWrite(greenLedPin,LOW);
  delay(1000);
  
  
  }
    for (int c=0; c<3; c++)
  {
     digitalWrite(redLedPin, HIGH);
   digitalWrite(yellLedPin, HIGH);
  digitalWrite(greenLedPin,LOW);
  delay(1000);
  
  
  }
   for (int c=0; c<5; c++)
  {
     digitalWrite(redLedPin, LOW);
   digitalWrite(yellLedPin, LOW);
  digitalWrite(greenLedPin,HIGH);
  delay(1000);
  
  
  }
   for (int c=0; c<3; c++)
  {
     digitalWrite(redLedPin, LOW);
   digitalWrite(yellLedPin, HIGH);
  digitalWrite(greenLedPin,HIGH);
  delay(1000);
  
  
  }
}
