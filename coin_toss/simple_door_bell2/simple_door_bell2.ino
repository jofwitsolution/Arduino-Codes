/*Design: simple door bell
 Features: button input (13), Buzzer (12)
 */

const  int buttonInput1 = 13;
  const int buzzerOutput = 12;
  const int buttonInput2 =11;
 
void setup() {

  pinMode(buttonInput1, INPUT);
  pinMode(buzzerOutput, OUTPUT);
  pinMode(buttonInput2, INPUT);
}

void loop() {
  
  if (digitalRead(buttonInput1)== LOW)
  {
    delay(500);
    //for (int x=1; x <= 5; x++)
    int x=0;
    while (x < 10)
    {
    digitalWrite(buzzerOutput, HIGH);
    delay(300);
    digitalWrite(buzzerOutput, LOW);
    delay(300);
    x++;
    
    }
  }
  else if (digitalRead(buttonInput2)== LOW)
  {
    delay(500);
    //for (int x=1; x <= 5; x++)
    int x=0;
    while (x < 5)
    {
    digitalWrite(buzzerOutput, HIGH);
    delay(300);
    digitalWrite(buzzerOutput, LOW);
    delay(300);
    x++;
    }
  }
  
}
