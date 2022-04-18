int decreaseButton = 12;
int increaseButton = 10;
int transistorInput = 11;
int stopButton = 8;
int led = 13;
int speedValue = 0;
void setup() {
  Serial.begin(9600);
  pinMode(decreaseButton, INPUT);
  pinMode(stopButton, INPUT);
  pinMode(increaseButton, INPUT);
  digitalWrite(increaseButton, HIGH);
  digitalWrite(decreaseButton, HIGH);
  digitalWrite(stopButton, HIGH);
  pinMode(transistorInput, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
 if (digitalRead(increaseButton)==LOW) {
  digitalWrite(led, HIGH);
  if(speedValue < 255) {
    speedValue = speedValue + 51;
    delay(500); //in order to see the led on
  }
 }
 if (digitalRead(decreaseButton) == LOW) {
  digitalWrite(led, HIGH);
  if(speedValue > 0) {
    speedValue = speedValue - 51;
    delay(500); //in order to see the led on
  }
 }
 if (digitalRead(stopButton) == LOW) {
  digitalWrite(led, HIGH);
  speedValue = 0;
  delay(500);
 }
 Serial.print("speed value = ");
 Serial.println(speedValue);
 
 analogWrite(transistorInput, speedValue);
}
