void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (analogRead(A5) > 650) {
    Serial.println("ON");
  }
}
