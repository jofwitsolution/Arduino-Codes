#define buzzer 12

#define outputPin 10

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(outputPin, INPUT);
}

void loop() {
    int readOutput = digitalRead(outputPin);

    if (readOutput == LOW) {
      digitalWrite(buzzer, HIGH);
      
    }
    else  digitalWrite(buzzer, LOW);
    
    }
  //}
