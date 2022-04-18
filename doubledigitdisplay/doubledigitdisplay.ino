// define the pins connected to the segments
#define segment_a 3
#define segment_b 4
#define segment_c 5
#define segment_d 6
#define segment_e 7
#define segment_f 10
#define segment_g 9
#define segment_h 8

//define the common sink pins
#define sink_1 11  // enables 1st digit
#define sink_2 12  // enables 2nd digit

int digit;

byte segmentPin[] = { 
  segment_a, segment_b, segment_c, segment_d, segment_e, segment_f, segment_g, segment_h};

byte segmentPattern_1[] = { 
  0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x7f, 0xbf};

void setup()
{
  pinMode (segment_a, OUTPUT);
  pinMode (segment_b, OUTPUT);
  pinMode (segment_c, OUTPUT);
  pinMode (segment_d, OUTPUT);
  pinMode (segment_e, OUTPUT);
  pinMode (segment_f, OUTPUT);
  pinMode (segment_g, OUTPUT);
  pinMode (segment_h, OUTPUT);

  pinMode (sink_1, OUTPUT);
  pinMode (sink_2, OUTPUT);

  //counts from 00 to 99 and calls for display the two digits after each increment
  for(int i=0; i<100; i++){
    for(int j=0; j<10; j++){
      digit = i/10;  //determines value of 'tens' digit
      digitalWrite(sink_1,HIGH);
      digitalWrite(sink_2,LOW);
      setSegments(digit);
      delay (5);
      digit = i - digit*10;  //determines value of 'units' digit
      digitalWrite(sink_1,LOW);
      digitalWrite(sink_2,HIGH);
      setSegments(digit);
      delay (5);
    }
  }
}
void loop () 
{ 
  int sensorValue = analogRead(A0);
  sensorValue = map (sensorValue, 0, 1023, 0, 99);

  //display sensed value
  for(int j=0; j<50; j++){
    digit = sensorValue/10;  //determines value of 'tens' digit
    digitalWrite(sink_1,HIGH);
    digitalWrite(sink_2,LOW);
    setSegments(digit);
    delay (5);
    digit = sensorValue - digit*10;  //determines value of 'units' digit
    digitalWrite(sink_1,LOW);
    digitalWrite(sink_2,HIGH);
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
