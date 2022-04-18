int analogPinA0 = A0;
float rawA0;

void setup() {
  analogReference(DEFAULT);
  Serial.begin(9600);
}

void loop() {
  rawA0 = analogRead(analogPinA0);
  //rawA0 = (rawA0*5)/1023;
  //rawA0 = (rawA0*5)*10.55;
  rawA0= rawA0 * 0.2608;
  Serial.println(rawA0);
//  Serial.print("  ");
//  Serial.println((float)rawA0 / 1023.0);
//  Serial.print("  ");
//  Serial.println((rawA0/1023.0)*5);
  delay(500);
}
