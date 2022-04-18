#include<LiquidCrystal.h>
LiquidCrystal lcd (7, 6, 5, 4, 3, 2);
int personIn=0;
int personOut=0;
int Remain=0;
const int trigPin1 = 8; //entrance
const int echoPin1 = 9; //entrance
const int trigPin2 = 10; //exit
const int echoPin2 = 11; //exit
const int bulb = 12;
const int buzzerPin = 13;
long duration1, duration2;
int distance1, distance2;
int initDist = 10;


void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(bulb, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.print("Automatic Light");
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("In=");
  lcd.setCursor(8,0);
  lcd.print("Out=");
  lcd.setCursor(0,1);
  lcd.print("Remain=");
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2); // to wake up the circuitry
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // to send out a burst of ultrasound wave
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH); //for how long the echoPin was high is stored in duration
  distance1 = duration1*(0.034/2);

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2); // to wake up the circuitry
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // to send out a burst of ultrasound wave
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH); //for how long the echoPin was high is stored in duration
  distance2 = duration2*(0.034/2);
  
  if (distance1 < initDist) {
    personIn +=1;
    //Remain = personIn-personOut;
  }
    if (distance2 < initDist) {
    personOut+=1;
    //Remain = personIn-personOut;
    //personIn--;
  }
  Remain = personIn-personOut;
  if (Remain <= 0){
    personOut=0;
    personIn=0;
    Remain = 0;
   }
   //if (Remain <= 0) {
    //Remain = 0;
    //personIn = personOut;
   //}
    lcd.setCursor(4,0);
    lcd.print(personIn);
    lcd.setCursor(12,0);
    lcd.print(personOut);
    lcd.setCursor(7,1);
    lcd.print(Remain);
  
  
  if ( personIn >= 1 && Remain>=1 ) {
    digitalWrite(bulb, HIGH);
   
  }
   else  { 
   digitalWrite(bulb, LOW);
   }
   
 for (int i=0; i>=0; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
  }
   }
  else{ digitalWrite(buzzerPin, LOW);}
   
   delay(3000);
  }
