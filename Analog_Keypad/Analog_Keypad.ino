const int rowOne = 13, rowTwo = 12, rowThree = 11, rowFour = 10;
const int colOne = A0, colTwo = A1, colThree = A2, colFour = A3;
void setup() {
  // put your setup code here, to run once:
  pinMode(rowOne, OUTPUT);
  pinMode(rowTwo, OUTPUT);
  pinMode(rowThree, OUTPUT);
  pinMode(rowFour, OUTPUT);

  digitalWrite(rowOne, LOW);
  digitalWrite(rowTwo, LOW);
  digitalWrite(rowThree, LOW);
  digitalWrite(rowFour, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad();
  if (key!=void) Serial.println(key);
}
char keypad()
{ 
  digitalWrite(rowOne, HIGH);
  digitalWrite(rowTwo, LOW);
  digitalWrite(rowThree, LOW);
  digitalWrite(rowFour, LOW);
  if(analogRead(colOne) > 512) return '0';
  if(analogRead(colTwo) > 512) return '1';
  if(analogRead(colThree) > 512) return '2';
  if(analogRead(colFour) > 512) return '3';
  
  digitalWrite(rowOne, LOW);
  digitalWrite(rowTwo, HIGH);
  digitalWrite(rowThree, LOW);
  digitalWrite(rowFour, LOW);
  if(analogRead(colOne) > 512) return '4';
  if(analogRead(colTwo) > 512) return '5';
  if(analogRead(colThree) > 512) return '6';
  if(analogRead(colFour) > 512) return '7';
  
  digitalWrite(rowOne, LOW);
  digitalWrite(rowTwo, LOW);
  digitalWrite(rowThree, HIGH);
  digitalWrite(rowFour, LOW);
  if(analogRead(colOne) > 512) return '8';'
  if(analogRead(colTwo) > 512) return '9';
  if(analogRead(colThree) > 512) return 'A';
  if(analogRead(colFour) > 512) return 'B';
  
  digitalWrite(rowOne, LOW);
  digitalWrite(rowTwo, LOW);
  digitalWrite(rowThree, LOW);
  digitalWrite(rowFour, HIGH);
  if(analogRead(colOne) > 512) return 'C';
  if(analogRead(colTwo) > 512) return 'D';
  if(analogRead(colThree) > 512) return 'E';
  if(analogRead(colFour) > 512) return 'F';

  return null;
}
