//Measuring DC voltage

float value;
float Vin;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  value = analogRead(A0);
  value = (value*5)/1023;
  Vin = (1/0.2474)*value;
  Serial.print("output voltage = ");
  Serial.println(Vin);
  delay(1000); 
}
