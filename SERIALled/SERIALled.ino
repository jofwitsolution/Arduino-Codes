
int led = 13;
int button = 12;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  
}

void loop() {
 if (digitalRead(button)==LOW)
 {
  delay(100);
  digitalWrite(led, HIGH);
  Serial.print("LED IS ON");
  delay(1000);
  digitalWrite(led, LOW);
  Serial.print("LED IS OFF");
  
 }
}
