const int ldrPin = A1;
int ldrValue;
int ledPin = 7;
const int relayIn = 8;

void setup() {
 Serial.begin(9600);
  pinMode(relayIn, OUTPUT);
   pinMode(ledPin, OUTPUT);
}

void loop() {
  ldrValue = analogRead(ldrPin); 
  Serial.print("ldr value=");
  Serial.println(ldrValue);
  delay(200);
   if (ldrValue>400) {
    digitalWrite(relayIn, HIGH);
    digitalWrite(ledPin, HIGH);
  }
  else { digitalWrite(relayIn, LOW);
         digitalWrite(ledPin, LOW);}
}

