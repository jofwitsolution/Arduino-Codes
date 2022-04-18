
byte LedPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int currentLed = 0;
int Direction = 1;
//int potPin = 2;
int ledDely;

void setup() {
  for (int y=0; y<10; y++)
  {
    pinMode(LedPin[y], OUTPUT);
  }
}

void loop() {
  
  changeLed();
}

void changeLed()
{
  //int ledDelay = analogRead(potPin);
  for (int y=0; y<10; y++)
  {
    digitalWrite(LedPin[y], LOW);
    //delay(ledDelay);
    delay(10);
  }
  digitalWrite(LedPin[currentLed], HIGH);
  //delay(ledDelay);
  delay(30);
  currentLed += Direction;
  if (currentLed==9) {Direction=-1;}
  if (currentLed==0) {Direction=1;}
}

