
byte LedPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int currentLed = 0;
int Direction = 1;
int counter=0;
//int potPin = 2;
int ledDely;

void setup() {
  for (int y=0; y<10; y++)
  {
    pinMode(LedPin[y], OUTPUT);
  }
}

void loop() {
  
  changeLed1();
  changeLed2();
  changeLed3();
  changeLed4();
  changeLed5();
  changeLed6();
  changeLed7();
  changeLed8();
  changeLed9();
  
}

void changeLed1()
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
   
}
void changeLed2()
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
   if (currentLed==8) {Direction=-1;}
   
}
void changeLed3()
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
   if (currentLed==7) {Direction=-1;}
   
}
void changeLed4()
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
   if (currentLed==6) {Direction=-1;}
   
}
void changeLed5()
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
   if (currentLed==5) {Direction=-1;}
   
}
void changeLed6()
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
   if (currentLed==4) {Direction=-1;}
   
}
void changeLed7()
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
   if (currentLed==3) {Direction=-1;}
   
}
void changeLed8()
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
   if (currentLed==2) {Direction=-1;}
   
}
void changeLed9()
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
   if (currentLed==1) {Direction=-1;}
   
}

