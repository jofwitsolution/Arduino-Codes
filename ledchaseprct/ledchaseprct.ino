
byte ledArray[] = {4,5,6,7,8,9,10,11,12,13};

void setup() {
  for (int x=0; x<10; x++)
  {
    pinMode(ledArray[x], OUTPUT);
  }
}

void loop() {
  for (int x=0; x<10; x++)
  {
    digitalWrite(ledArray[x], LOW);
    delay(10);
  }
  for (int x=0; x<10; x++)
  {
    digitalWrite(ledArray[x], HIGH);
    delay(30);
    if (x==9)
    {
      for (int y=9; y<10; y--)
      {
        digitalWrite(ledArray[y], HIGH);
        delay(30); 
      }
    }
  }
}
