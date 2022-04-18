#include <SoftwareSerial.h>
SoftwareSerial gsm(7,6);

//       --a--
//    f |     | b
//      |--g--|
//    e |     | c
//       --d--  O h
// define the pins connected to the segments
#define segment_a 2
#define segment_b 3
#define segment_c 4
#define segment_d 5
#define segment_e 8
#define segment_f 9
#define segment_g 10

//define the common sink pins
#define sink_1 11  // enables 1st digit
#define sink_2 12  // enables 2nd digit
#define sink_3 13  // enables 3rd digit

#define buzzer 14

int digit;

byte segmentPin[] = { 
  segment_a, segment_b, segment_c, segment_d, segment_e, segment_f, segment_g};

byte segmentPattern_1[] = { 
  0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x7f, 0xbf};

void setup()
{
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT");
  //gsm.println("ATD08060476057;");
  pinMode (buzzer, OUTPUT);
  digitalWrite(buzzer,HIGH);
  pinMode (segment_a, OUTPUT);
  pinMode (segment_b, OUTPUT);
  pinMode (segment_c, OUTPUT);
  pinMode (segment_d, OUTPUT);
  pinMode (segment_e, OUTPUT);
  pinMode (segment_f, OUTPUT);
  pinMode (segment_g, OUTPUT);
  
  pinMode (sink_1, OUTPUT);
  pinMode (sink_2, OUTPUT);
  pinMode (sink_3, OUTPUT);


  
  //counts from 00 to 99 and calls for display the three digits after each increment
  for(int i=0; i<100; i++){
    for(int j=0; j<9; j++){
      digit = i/100;  //determines value of 'tens' digit
      digitalWrite(sink_1,HIGH);
      digitalWrite(sink_2,LOW);
      digitalWrite(sink_3,LOW);
      setSegments(digit);
      delay(5);
      digit = (i/10)%10;  //determines value of 'tens' digit
      digitalWrite(sink_1,LOW);
      digitalWrite(sink_2,HIGH);
      digitalWrite(sink_3,LOW);
      setSegments(digit);
      delay(5);
      digit = i%10;  //determines value of 'units' digit
      digitalWrite(sink_1,LOW);
      digitalWrite(sink_2,LOW);
      digitalWrite(sink_3,HIGH);
      setSegments(digit);
      delay(5);    
    }
  }
  gsm.println("AT");
  gsm.println("ATD08137192766;");
  delay(1000);
  digitalWrite(buzzer,LOW);
  Serial.println("here");
}

void loop () 
{ 
   int voltage = getVolts();
  //display sensed value
  for(int j=0; j<50; j++){
    digit = voltage/100;  //determines value of 'tens' digit
    digitalWrite(sink_1,HIGH);
    digitalWrite(sink_2,LOW);
    digitalWrite(sink_3,LOW);
    setSegments(digit);
    delay (5);
    digit = (voltage/10)%10;  //determines value of 'units' digit
    digitalWrite(sink_1,LOW);
    digitalWrite(sink_2,HIGH);
    digitalWrite(sink_3,LOW);
    setSegments(digit);
    delay (5);
    digit = voltage%10;  //determines value of 'units' digit
    digitalWrite(sink_1,LOW);
    digitalWrite(sink_2,LOW);
    digitalWrite(sink_3,HIGH);
    setSegments(digit);
    delay (5);
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

float getVolts()
{
  int result;
  int readValue;
  int maxValue = 0;
  int minValue = 1024;
  uint32_t startTime = millis();
  while(millis() - startTime < 10)
  {
    readValue = analogRead(A0);
    if(readValue > maxValue) maxValue = readValue;
    if(readValue < minValue) minValue = readValue;
  }
  result = (maxValue + minValue) / 2.0;
  result = result * 0.36013788136029222616658949426352;//for short one
  return result;
}
