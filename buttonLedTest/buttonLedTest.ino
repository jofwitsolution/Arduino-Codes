
void setup() {
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  if (digitalRead(2)==HIGH) {
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(6, LOW);
  }
}
