int bulb = 9;
int led = 8;
int potentiometer = A5;
int value = 150;

void setup() {
  //Serial.begin(9600);
  pinMode(bulb, OUTPUT);
  pinMode(led, OUTPUT);
}
void loop() {
  digitalWrite(led, HIGH);
  
  value = analogRead(potentiometer);
  value = map (value, 0, 1023, 0, 255);
  //Serial.println(value);
  delay(200);
  
  analogWrite(bulb, value);
  
 
}
