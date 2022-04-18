
byte LedPin1[] = {4, 5, 6, 7, 8 };
byte LedPin2 [] = {13, 12, 11, 10, 9};
int currentLed = 0;
int Direction = 1;
int currentLed2 = 0;
int Direction2 = 1;


void setup() {
  for (int y=0; y<5; y++)
  {
    pinMode(LedPin1[y], OUTPUT);
  }
   for (int y=0; y<5; y++)
  {
    pinMode(LedPin2 [y], OUTPUT);
  }
}

void loop() {
  
  changeLed();
}

void changeLed()
{
  
  for (int y=0; y<5; y++)
  {
    digitalWrite(LedPin1[y], LOW);
    delay(10);
  }
  digitalWrite(LedPin1[currentLed], HIGH);
  delay(30);
  currentLed += Direction;
  if (currentLed==4) {Direction=-1;}
  if (currentLed==0) {Direction=1;}
   for (int y=0; y<5; y++)
  {
    digitalWrite(LedPin2 [y], LOW);
    delay(10);
  }
  digitalWrite(LedPin2 [currentLed2], HIGH);
  delay(30);
  currentLed2 += Direction2;
  if (currentLed2==4) {Direction2=-1;}
  if (currentLed2==0) {Direction2=1;}
}

