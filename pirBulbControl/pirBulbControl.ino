int relayPin = 8;
int pirPin = 9;
long int currentTime=0;
int buttonInput = 7;
void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonInput, INPUT);
  digitalWrite(buttonInput, HIGH);
}

void loop() {
  currentTime = millis();
  Serial.println(currentTime);
  if (digitalRead(pirPin) == HIGH) {
    //if (digitalRead(buttonInput) == LOW) {
    analogWrite(relayPin, HIGH);
    //delay(5000);
  }
  else digitalWrite(relayPin, LOW);
}

