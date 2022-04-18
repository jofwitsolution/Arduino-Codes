void setup() {
  Serial.begin(9600);
   
}

void loop() {
  int alcoholLevel = analogRead(A1);
  Serial.println(alcoholLevel);
  delay(200);
}
