byte ledArray[] = {4,5,6,7,8,9,10,11,12,13};
 int currentled=0;
  int Direction=1;
  int currentled2=0;
  int Direction2=1;
  int currentled3=0;
  int Direction3=1;
void setup (){
  for (int x=0; x<10; x++)
  {
    pinMode(ledArray[x], OUTPUT);
  }
}
void loop(){
  for (int x=0; x<10; x++)
  {
    digitalWrite(ledArray[x], LOW);
    delay(30);
  }
  oprtn1 ();
  
}
void oprtn1 () {
 
  digitalWrite(ledArray[currentled], HIGH);
  delay(30);
  currentled=currentled+Direction;
  if (currentled==9) {Direction=-1;}
  if (currentled==0) {oprtn2 ();}
}
void oprtn2 () {
 
  digitalWrite(ledArray[currentled2], HIGH);
  delay(30);
  currentled2=currentled2+Direction2;
  if (currentled2==8) {Direction2=-1;}
  if  (currentled2==0) {oprtn3 ();}
}
void oprtn3 () {
 
  digitalWrite(ledArray[currentled3], HIGH);
  delay(30);
  currentled3=currentled3+Direction3;
  if (currentled3==7) {Direction3=-1;}
  //if (currentled3==0) {Direction3=1;}
}
