#define button 9
#define greenLed 13
#define redLed 12
#define yellLed 11
int buttonInput;
int state=1;
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  buttonInput = digitalRead(button);
  
  if (buttonInput == HIGH) {
    delay(100);
    if (state == 1){
    for (int i=0; i>=0; i++) {
    digitalWrite(redLed, HIGH);
    delay(300);
    digitalWrite(redLed, LOW);
    delay(300);
    if (buttonInput == HIGH)
    state = 0;
    break;
    }
    }
    }
}
