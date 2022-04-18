const int ledPin = 12;
const int relayPin = 7;
const int micPinA = A0;
const int micPinD = 9;
int micValA;
int micValD = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(relayPin,OUTPUT);
  pinMode(micPinA,INPUT);
  pinMode(micPinD,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {

  micValA = analogRead(micPinA);
  micValD = digitalRead(micPinD);
  
  Serial.print("Micph analog val= ");
  Serial.println(micValA);
  delay(1000);
  Serial.print("Micph digital val= ");
  Serial.println(micValD);
  delay(1000);

  if (micValA>53) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayPin, HIGH);
    delay(micValA);
  }
  else {digitalWrite(ledPin, LOW);
  digitalWrite(relayPin, LOW);
  }
  
}
