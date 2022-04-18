byte LedPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int currentLed = 0;
int Direction = 1;


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
  for (int x=0; x<1; x++){
  for (int y=0; y<10; y++)
  {
    digitalWrite(LedPin[y], LOW);
    delay(10);
  }
  digitalWrite(LedPin[currentLed], HIGH);
  delay(30);
  currentLed += Direction;
  if (x=9){
  if (currentLed==9) {Direction=-1;}
  if (currentLed==0) {Direction=1;}
  }
}}

