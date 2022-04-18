int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int led7 = 7;
int led8 = 6;
int sensor = 5;
int ledArray[8] = {13, 12, 11, 10, 9, 8, 7, 6};
void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  digitalWrite(sensor, HIGH);
  for (int i=0; i<8; i++) {
    pinMode(ledArray[i], OUTPUT);
  }
}

void loop() {
  if (digitalRead(sensor)==LOW) {
    for (int i=0; i<4; i++) {
      digitalWrite(ledArray[i], HIGH);
      delay(60);
      digitalWrite(ledArray[i], LOW);
      delay(60);
      if (i == 3) {
        for (int x=2; x>=1; x--) {
          digitalWrite(ledArray[x], HIGH);
          delay(60);
          digitalWrite(ledArray[x], LOW);
          delay(60);
        }
      }
    }
  }

  else {
    for (int i=4; i<8; i++) {
      digitalWrite(ledArray[i], HIGH);
      delay(60);
      digitalWrite(ledArray[i], LOW);
      delay(60);
      if (i == 7) {
        for (int x=6; x>=5; x--) {
          digitalWrite(ledArray[x], HIGH);
          delay(60);
          digitalWrite(ledArray[x], LOW);
          delay(60);
        }
      }
    }
  }
}

