int bulb = 9;
int button = 11;

boolean buttonPressed = false;
unsigned long timePressed = 0;
int bulbDelay = 5000;

void setup() {
  // initialize serial communication
  Serial.begin(9600);

  // set relay pin as output
  pinMode (bulb, OUTPUT);
  
  // set button pin as input
  pinMode (button, INPUT);

  // turn off all the relays at startup
  digitalWrite(bulb, LOW);

  // make the button high
  digitalWrite(button, HIGH);
  
}

void loop() {
  if (digitalRead(button) == LOW) {
    timePressed = millis();
    buttonPressed = true;
    Serial.println("Pressed");
  }

  if (buttonPressed && timePressed + bulbDelay > millis()) {
    digitalWrite(bulb, HIGH);
  }
  else {
    digitalWrite(bulb, LOW);
    buttonPressed = false;
  }
    
}
