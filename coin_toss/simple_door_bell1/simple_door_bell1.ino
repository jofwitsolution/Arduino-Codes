/*Design: simple door bell
 Features: button input (13), Buzzer (12)
 */

const  int buttonInput = 13;
  const int buzzerOutput = 12;
 
void setup() {
  pinMode(buttonInput, INPUT);
  pinMode(buzzerOutput, OUTPUT);
}

void loop() {
  Serial.begin(9600);
  if (digitalRead(buttonInput)== LOW)
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
    
    }
  }
  int sum, y; 
  y = 5;
  sum = ++y;
 Serial.print("sum =");
}
