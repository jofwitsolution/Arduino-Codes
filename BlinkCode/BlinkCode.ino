int ledPin1 = 6;
int ledPin2 = 5;
int ledPin3 = 4;
int ledPin4 = 12;
int ledPin5 = 13;

void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin4, HIGH);
  delay(2000);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin4, LOW);
  delay(2000);
}
