// define the pins connected to the segments
#define segment_a 4
#define segment_b 5
#define segment_c 6
#define segment_d 7
#define segment_e 8
#define segment_f 9
#define segment_g 10
#define segment_h 2

//define the common source pins
#define sink_1 11  // enables 1st digit
#define sink_2 12  // enables 2nd digit
#define sink_3 13  // enables 3rd digit

int ledSink[] = {11,12,13,3}; 
int buzzer = 3;
void setSegments (byte digit);

int digit;
int voltage;
int Value;

unsigned long currentTime;
unsigned long Timer=0;

int state = 0;

byte segmentPin[] = { 
  segment_a, segment_b, segment_c, segment_d, segment_e, segment_f, segment_g, segment_h};

byte segmentPattern_1[] = { 
  0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0xc6, 0xbf};

void setup() {
  analogReference(DEFAULT);
    Serial.begin(9600);
  pinMode (segment_a, OUTPUT);
  pinMode (segment_b, OUTPUT);
  pinMode (segment_c, OUTPUT);
  pinMode (segment_d, OUTPUT);
  pinMode (segment_e, OUTPUT);
  pinMode (segment_f, OUTPUT);
  pinMode (segment_g, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode (2, INPUT);
  digitalWrite(2, HIGH);

  pinMode (sink_1, OUTPUT);
  pinMode (sink_2, OUTPUT);
  pinMode (sink_3, OUTPUT);

  currentTime = millis();

// The buzzer turn on and off 8 times in 8 seconds and the leds also flickers
  for (int x =0; x<8; x++) {
      for (int y=0; y<4; y++) {
        digitalWrite(ledSink[y], HIGH);
      }
      for (int z=0; z<7; z++) {
        digitalWrite(segmentPin[z], LOW);
      }
      delay(500);

      for (int v=0; v<4; v++) {
        digitalWrite(ledSink[v], LOW);
      }
      delay(500);
  }
}
void loop (){
  currentTime = millis();
   
  voltage = voltage_Read(); 
  //delay(750);
  if (digitalRead(2)==LOW) {
    delay(200);
    Timer = currentTime;
    state = 1;
  }
  
if (Timer > 0 && (Timer+10000)>=currentTime && state==1) {
    timeDisplay(currentTime);
    }
 else{
  
  for(int j=0; j<50; j++){
    digit = (voltage/100)%10;
      digitalWrite(sink_1,HIGH);
      digitalWrite(sink_2, LOW);
      digitalWrite(sink_3, LOW);
      setSegments(digit);
      delay (5);
      digit = (voltage/10)%10;
      digitalWrite(sink_1,LOW);
      digitalWrite(sink_2, HIGH);
      digitalWrite(sink_3, LOW);
      setSegments(digit);
      delay (5);
      digit = (voltage % 10);
      digitalWrite(sink_1,LOW);
      digitalWrite(sink_2, LOW);
      digitalWrite(sink_3, HIGH);
      setSegments(digit);
      delay (5);
  }
}
Serial.println(state);
Serial.println(currentTime);
if ((Timer+10000)<=currentTime) {
      state=0;
      Timer=0;
    }
    
}

float voltage_Read() {
  float maxi;
  int val[5];
  for (int x=0; x<5; x++) {
  Value = analogRead(A5);
   float voltage = Value*0.4727; 
   //float voltage = (Value/1023.0)*5;      //here i am converting the ADC reading
 // voltage = voltage * 5;    //here i am multiplying by the 5 we used to divide
  //voltage = voltage * 15.2;
  val[x] = voltage; 
  }
   maxi = val[0];

   for (int x=0; x<5; x++) {
    if (maxi < val[x])  maxi = val[x];
   }

  return maxi;
   }

int timeDisplay(unsigned long milliVal) {
  int minutes = 0;
  float seconds = milliVal/1000;
  if (seconds >= 60) {
    minutes = seconds/60;
  }

  for(int j=0; j<50; j++){
    digit = (minutes/100)%10;
      digitalWrite(sink_1,HIGH);
      digitalWrite(sink_2, LOW);
      digitalWrite(sink_3, LOW);
      setSegments(digit);
      delay (5);
      digit = (minutes/10)%10;
      digitalWrite(sink_1,LOW);
      digitalWrite(sink_2, HIGH);
      digitalWrite(sink_3, LOW);
      setSegments(digit);
      delay (5);
      digit = (minutes % 10);
      digitalWrite(sink_1,LOW);
      digitalWrite(sink_2, LOW);
      digitalWrite(sink_3, HIGH);
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
