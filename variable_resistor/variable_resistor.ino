void setup() {
 Serial.begin(9600);
}
void loop()
{ float val = analogRead(0);
  Serial.println(val);
  float voltage = (val*5)/1023;
  Serial.println(voltage);
  delay(1000);
}
