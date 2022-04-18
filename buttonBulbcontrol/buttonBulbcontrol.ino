int button = 12;
int relaypin = 11;
int state = 0;
void setup() {
  pinMode(relaypin, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
}

void loop() {
  
  if (digitalRead(button) == LOW) {
    delay(500);
    if (state == 0) {
    digitalWrite(relaypin, HIGH);
    }
   
  if (state == 1) {
    digitalWrite(relaypin, LOW);
  }
  state = state + 1;
  if (state == 2) {
    state = 0;
  }
}
}
