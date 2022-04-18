int tempSensor = A0;  //LM35 temperature sensor used
int buttonInput0 =  A1;  //the mode select button
int buttonInput1 = A2; //the speed 1 button
int buttonInput2 = A3;  //the speed 2 button
int buttonInput3 = A4;  //the speed 3 button
int speed1 = 11;         //relay1
int speed2 = 10;         //relay2
int speed3 = 9;         //relay3
// define the pins connected to the segments
#define segment_a 8
#define segment_b 7
#define segment_c 6
#define segment_d 5
#define segment_e 4
#define segment_f 3
#define segment_g 2


//define the common sink pins
#define sink_1 13  // enables 1st digit
#define sink_2 12  // enables 2nd digit
byte segmentPin[] = { 
  segment_a, segment_b, segment_c, segment_d, segment_e, segment_f, segment_g};

byte segmentPattern_1[] = { 
  0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int db = 0;
int digit;
int value;
float result;
float tempValue;
int state = 0;
int button1, button2, button3, modeButton;
int speedLevel = 0;
int displayValue = 0;
unsigned long ledDelay = 15000;
int timer = 0;

void setup() {
  pinMode(db, OUTPUT);
  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  pinMode(speed3, OUTPUT);
  pinMode (segment_a, OUTPUT);
  pinMode (segment_b, OUTPUT);
  pinMode (segment_c, OUTPUT);
  pinMode (segment_d, OUTPUT);
  pinMode (segment_e, OUTPUT);
  pinMode (segment_f, OUTPUT);
  pinMode (segment_g, OUTPUT);

  pinMode (sink_1, OUTPUT);
  pinMode (sink_2, OUTPUT);
   //counts from 00 to 19 and calls for display the two digits after each increment
  for(int i=0; i<20; i++){
    for(int j=0; j<10; j++){
      digit = i/10;  //determines value of 'tens' digit
      digitalWrite(sink_1,LOW);
      digitalWrite(sink_2,HIGH);
      setSegments(digit);
      delay (5);
      digit = i - digit*10;  //determines value of 'units' digit
      digitalWrite(sink_1,HIGH);
      digitalWrite(sink_2,LOW);
      setSegments(digit);
      delay (5);
    }
  }
}

void loop() {
  value = analogRead(tempSensor);
  result = (float(value)/1023)*5;
  tempValue = result/0.01; //since LM35 is 0.01v per degree celsius
  //Serial.print("Temp = ");
  //Serial.println(tempValue);
  //modeButton  = analogRead(buttonInput0); //to read the mode select button
   //button1 = analogRead(buttonInput1);
  //button2 = analogRead(buttonInput2);
  //button3 = analogRead(buttonInput3);
  
 //Here, one can select between the two modes 
  if (analogRead(buttonInput0) <512) {
    delay(100);
    state = state + 1;
  }
  if (state == 3) {
    state = 0;
  }
  if (state == 1) {
    autoMode();
    }
  else if (state == 2) {
    manualMode();
  }

//Here the led is made to display tempValue and speedLevel each in every 15 seconds
if (millis() > ledDelay) {
  ledDelay = ledDelay + 15000;
  timer = timer + 1;
}
if (timer == 2){
  timer = 0;
}

if (timer == 0) {
  displayValue = tempValue;
}
else if (timer == 1) {
  displayValue = speedLevel;
}
  for (int j=0; j<10; j++) {
digit = displayValue/10;  //determines value of 'tens' digit
    digitalWrite(sink_1,LOW);
    digitalWrite(sink_2,HIGH);
    setSegments(digit);
    delay (10);
    digit = displayValue - digit*10;  //determines value of 'units' digit
    digitalWrite(sink_1,HIGH);
    digitalWrite(sink_2,LOW);
    setSegments(digit);
    delay(10);
  }
}
void autoMode() {
  digitalWrite(db, LOW);
  if (tempValue < 18) {
    digitalWrite(speed1, LOW);
    digitalWrite(speed2, LOW);
    digitalWrite(speed3, LOW);
  }
  else if ((tempValue > 18) && (tempValue < 25)) {
    digitalWrite(speed1, HIGH);
    digitalWrite(speed2, LOW);
    digitalWrite(speed3, LOW);
    speedLevel = 1; 
  }
   else if ((tempValue > 24) && (tempValue < 29)) {
    digitalWrite(speed1, LOW);
    digitalWrite(speed2, HIGH);
    digitalWrite(speed3, LOW); 
    speedLevel = 2;
  }
   else if (tempValue > 28) {
    digitalWrite(speed1, LOW);
    digitalWrite(speed2, LOW);
    digitalWrite(speed3, HIGH);
    speedLevel = 3; 
  }
  
}

void manualMode() {
   digitalWrite(speed1, LOW);
    digitalWrite(speed2, LOW);
    digitalWrite(speed3, LOW); 
    speedLevel = 0;
    digitalWrite(db, HIGH); 
  if (analogRead(buttonInput1) <512) {
    //delay(10);
    digitalWrite(speed1, HIGH);
    digitalWrite(speed2, LOW);
    digitalWrite(speed3, LOW);
    speedLevel = 1; 
  }

  if (analogRead(buttonInput2) <512) {
    //delay(10);
    digitalWrite(speed1, LOW);
    digitalWrite(speed2, HIGH);
    digitalWrite(speed3, LOW);
    speedLevel = 2; 
  }

  if (analogRead(buttonInput3) <512) {
    //delay(5);
    digitalWrite(speed1, LOW);
    digitalWrite(speed2, LOW);
    digitalWrite(speed3, HIGH);
    speedLevel = 3; 
  }
  
}
// setting the bits of the digit to be displayed
void setSegments(byte digit){
  byte mask = 1;
  for(int i=0; i<8; i++){
    if((segmentPattern_1[digit] & mask) == 0) digitalWrite(segmentPin[i],LOW);
    else digitalWrite(segmentPin[i],HIGH);
    mask = mask <<1;
  }
}
