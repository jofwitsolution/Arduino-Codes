int led = 9;
int buttonInput = 8;
int tempSensor = A0;
int sensorValue;
float temp;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buttonInput, INPUT);
  
}
void loop() {
  
 
  delay(100);
if (digitalRead(buttonInput) == HIGH) {
    delay(200);
  for (int i = 0; i<100; i++) {
     sensorValue = analogRead(tempSensor);
  temp = ((sensorValue/1023.0)*5)/0.01;
  Serial.println(temp);
  if (temp < 26) {
    analogWrite(led, 80);
  }

  if (temp >= 26 && temp < 27) {
    analogWrite(led, 160);
  }
  
  if (temp >= 27) {
    analogWrite(led, 255); 
  }
  delay(100);
}
}
  else analogWrite(led, 0);
}
