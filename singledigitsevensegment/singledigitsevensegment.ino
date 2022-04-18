// define the pins connected to the segments
#define segment_a 8
#define segment_b 7
#define segment_c 6
#define segment_d 5
#define segment_e 4
#define segment_f 3
#define segment_g 2

//define the common sink pins
#define sink_1 9

int digit;

byte segmentPin[] = { 
  segment_a, segment_b, segment_c, segment_d, segment_e, segment_f, segment_g};

byte segmentPattern_1[] = { 
  0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67
  };

void setup() {
  // put your setup code here, to run once:
  // Set all the seven segment pins as output
  pinMode (segment_a, OUTPUT);
  pinMode (segment_b, OUTPUT);
  pinMode (segment_c, OUTPUT);
  pinMode (segment_d, OUTPUT);
  pinMode (segment_e, OUTPUT);
  pinMode (segment_f, OUTPUT);
  pinMode (segment_g, OUTPUT);

  // set seven segment common pin as output
  pinMode (sink_1, OUTPUT);

  //counts from 0 to 9 and calls for display the digit after each increment
  for(int i=0; i<10; i++){  // 0 to 9 in two secs
    for(int j=0; j<10; j++){
      digit = i%10;  //determines value of unit digit
      digitalWrite(sink_1, HIGH);
      setSegments(digit);
      delay (50);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

// setting the bits of the digit to be displayed
void setSegments(byte digit){
  byte mask = 1;
  for(int i=0; i<8; i++){
    if((segmentPattern_1[digit] & mask) == 0) digitalWrite(segmentPin[i], HIGH);
    else digitalWrite(segmentPin[i], LOW);
    mask = mask <<1;
  }
}
