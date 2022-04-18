int led = 9;
int potentiometer = A0;
int sensorValue;
float temp;
int value = 255;
String input;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  
}
void loop() {
  if (Serial.available()) {
    input = Serial.readString();
    value = input.toInt();
  }
    analogWrite(led, value);
//    digitalWrite(led, HIGH);
 
}
