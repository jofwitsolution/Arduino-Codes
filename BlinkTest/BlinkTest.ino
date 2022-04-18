/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
  
*/
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
int led = 11;

byte segmentPin[] = { 
  segment_a, segment_b, segment_c, segment_d, segment_e, segment_f, segment_g};

byte segmentPattern_1[] = { 
  0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67
  };
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);

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
  Serial.println("Before seven segment");
  delay(500);
  //counts from 0 to 9 and calls for display the digit after each increment
  for(int i=0; i<10; i++){  // 0 to 9 in two secs
    for(int j=0; j<10; j++){
      digit = i%10;  //determines value of unit digit
      digitalWrite(sink_1, HIGH);
      setSegments(digit);
      delay (50);
    }
  }
  Serial.println("After seven segment");
  delay(500);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Now in void loop");
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
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
