const int sensorPin=A0;
int baselineTemp=22;
void setup() {
  Serial.begin(9600);
  for (int x=2; x<5; x++){
  pinMode(x, OUTPUT);
  digitalWrite(x, LOW);
  }
}

void loop() {
  int sensorVal=analogRead(sensorPin);
  Serial.print(sensorVal);
  Serial.print(" ADC, ");
  float voltage=(sensorVal/1024.0)*5.0;
  Serial.print(voltage);
  Serial.print(" volts, ");
  float temperature=(voltage/0.01);
  Serial.print(temperature);
  Serial.println(" degrees C");
  delay(1000);
  if (temperature<baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature>= baselineTemp+2 && temperature<baselineTemp){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
else if (temperature>= baselineTemp+4 && temperature<baselineTemp){
  digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
}
else if (temperature>=baselineTemp+6){
  digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
}
delay(1000);
}
