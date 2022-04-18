const int ledPin = 8;
const int sensorPin = 0;

const int minDuration = 100;
const int maxDuration = 1000;
char oldString[] = "I want this character array in a String object";
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorReading = analogRead(sensorPin);
  Serial.println(sensorReading);
  int rate = map(sensorReading, 380, 900, minDuration, maxDuration);
  rate = rate / 100; //Add this line for audio frequency
  Serial.println(rate);
  digitalWrite(ledPin, HIGH);
  delay(rate);
  digitalWrite(ledPin, LOW);
  delay(rate);
 Serial.println(oldString[5]);
}
