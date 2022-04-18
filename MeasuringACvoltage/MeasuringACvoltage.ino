int buzzerPin = 9;
void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
 
    digitalWrite(buzzerPin, HIGH);
    delay(5000);
    digitalWrite(buzzerPin, LOW);
}

void loop() {
  int adcValue = analogRead(A0);
  float voltage = (adcValue/1023.0)*5*2.2*21.81;
  voltage = voltage - 5;
  Serial.print("ADC value = ");
  Serial.println(adcValue);
  Serial.print("voltage = ");
  Serial.println(voltage);
  
}
