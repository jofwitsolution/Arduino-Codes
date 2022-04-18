int buttonInput = 12;
int buzzerOutput = 11;
//int buttonInput2 =11;

void setup() {

  pinMode(buttonInput, INPUT);
  pinMode(buzzerOutput, OUTPUT);
//  pinMode(buttonInput2, INPUT);
}

void loop() {
  
  if (digitalRead(buttonInput)==LOW)
  { delay(500);
    for (int y =0; y < 5; y++){
    digitalWrite(buzzerOutput, HIGH);
    delay(500);
    digitalWrite(buzzerOutput, LOW);
    delay(500);
    }
  }
//  if (digitalRead(buttonInput2)==LOW)
  //{ delay(500);
    //for (int y =0; y < 10; y++){
    //digitalWrite(buzzerOutput, HIGH);
    //delay(500);
    //digitalWrite(buzzerOutput, LOW);
    //delay(500);
    //}
  //}

}
