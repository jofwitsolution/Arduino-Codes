void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue*(5000/1023);
  Serial.print(voltage);
  Serial.println(" V");
  delay(1);
}
