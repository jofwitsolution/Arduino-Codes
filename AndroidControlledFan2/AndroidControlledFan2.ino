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

int speed1 = 12;         //relay1
int speed2 = 11;         //relay2
int speed3 = 10;          //relay3

int button1 = A5; //the speed 1 button
int button2 = A4;  //the speed 2 button
int button3 = A3;  //the speed 3 button

int digit;
String currentSpeed = "0";
String BT_input = "0";
String BT_control = "0";

byte segmentPin[] = { 
  segment_a, segment_b, segment_c, segment_d, segment_e, segment_f, segment_g};

byte segmentPattern_1[] = { 
  0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67
  };


void setup() {
  // initialize serial communication
  Serial.begin(9600);

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

  // set relay pins as output
  pinMode (speed1, OUTPUT);
  pinMode (speed2, OUTPUT);
  pinMode (speed3, OUTPUT);

//  // set button pins as input
//  pinMode (button1, INPUT);
//  pinMode (button2, INPUT);
//  pinMode (button3, INPUT);

  // turn off all the relays at startup
  digitalWrite(speed1, LOW);
  digitalWrite(speed2, LOW);
  digitalWrite(speed3, LOW);

//  // make all buttons low
//  digitalWrite(button1, LOW);
//  digitalWrite(button2, LOW);
//  digitalWrite(button3, LOW);
  
  //counts from 0 to 9 and calls for display the digit after each increment
  for(int i=0; i<10; i++){  // 0 to 9 in two secs
    for(int j=0; j<10; j++){
      digit = i%10;  //determines value of unit digit
      digitalWrite(sink_1, HIGH);
      setSegments(digit);
      delay (50);
    }
  }

  digit = 0; // set digit to current speed
  setSegments(digit);
}

void loop() {

  if (Serial.available() || digitalRead(button1) == HIGH || digitalRead(button2) == HIGH || digitalRead(button3) == HIGH) {
      BT_input = Serial.readString();
      
      if (BT_input == "0") {
       // Serial.println("Fan is Off");
       Serial.println("Fan is Off");
         currentSpeed = "0";
         BT_input == "";
      }
      if (BT_input == "1" || digitalRead(button1) == HIGH) {
        if (BT_input == "1")  Serial.println("Speed 1 Activated");
        currentSpeed = "1";
        BT_input == "";
        BT_control = "1";
      }
      if (BT_input == "2" || digitalRead(button2) == HIGH) {
        if (BT_input == "2")  Serial.println("Speed 2 Activated");
        currentSpeed = "2";
        BT_input == "";
        BT_control = "1";
      }
      if (BT_input == "3" || digitalRead(button3) == HIGH) {
        if (BT_input == "3")  Serial.println("Speed 3 Activated");
        currentSpeed = "3";
        BT_input == "";
        BT_control = "1";
      }

      // if the Fan is no longer controlled by bluetooth
      if (digitalRead(button1) == HIGH || digitalRead(button2) == HIGH || digitalRead(button3) == HIGH) BT_control = "0"; 
   }

  if (digitalRead(button1) == LOW && digitalRead(button2) == LOW && digitalRead(button3) == LOW && BT_control == "0") {
    currentSpeed = "0";
  }

  if (currentSpeed == "0") {
    digitalWrite(speed1, LOW);
    digitalWrite(speed2, LOW);
    digitalWrite(speed3, LOW);
    digit = 0;
  }

  if (currentSpeed == "1") {
    digitalWrite(speed1, HIGH);
    digitalWrite(speed2, LOW);
    digitalWrite(speed3, LOW);
    digit = 1;
  }

  if (currentSpeed == "2") {
    digitalWrite(speed1, LOW);
    digitalWrite(speed2, HIGH);
    digitalWrite(speed3, LOW);
    digit = 2;
  }

  if (currentSpeed == "3") {
    digitalWrite(speed1, LOW);
    digitalWrite(speed2, LOW);
    digitalWrite(speed3, HIGH);
    digit = 3;
  }
  
 digitalWrite(sink_1, HIGH);
 setSegments(digit);
 delay (20); 
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
