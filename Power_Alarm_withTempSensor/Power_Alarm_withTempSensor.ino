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

int tempSensor = A3;
int ledSink[] = {11,12,13,3}; 
int buzzer = 3;
void setSegments (byte digit);

int digit;
int voltage;
int Value;

unsigned long currentTime;
unsigned long Timer=0;
unsigned long voltTimer=0;
unsigned long voltReadTimer=0;
unsigned long previousTime=0;
unsigned long stopTime=0;
int voltReadDelay=5000;

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

  pinMode (sink_1, OUTPUT);
  pinMode (sink_2, OUTPUT);
  pinMode (sink_3, OUTPUT);

  currentTime = millis();

// The buzzer sounds 8 times in one second and the leds also flickers
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
  int button1 = analogRead(A2);
  int button2 = analogRead(A1);
  int button3 = analogRead(A0);
  currentTime = millis();
  int tvalue = analogRead(tempSensor);
  float result = (tvalue/1023.0)*5;
  int tempValue = result/0.01; 
 //int sensorValue = analogRead(A5);
  Serial.println(tvalue);

  if (analogRead(A0) <= 512) {
    stopTime = currentTime;
    stopTime = stopTime + 3600000;  //stop till the next 20 minutes
  }
  
  voltage = voltage_Read();
  
  if (voltage <= 150 && stopTime <= currentTime) {
    if (previousTime + 600000 <= currentTime) {
    previousTime = previousTime + 1200000;
    lowVoltage();
  }
  }
  Serial.print("But1 = ");
  Serial.println(button1);
  Serial.print("But2 = ");
  Serial.println(button2);
  Serial.println(voltage);
  Serial.print("temp = ");
  Serial.println(tempValue);
  
  if (analogRead(A2)<=512) {
    delay(200);
    Timer = currentTime;
    state = 1;
  }
  if (analogRead(A1)<=512) {
    delay(200);
    Timer = currentTime;
    state = 2;  
  }

 if (Timer > 0 && (Timer+5000)>=currentTime && state==1) {
    tempDisplay(tempValue);
    }
 else if (Timer != 0 && state == 2 && (Timer+5000)>=currentTime) timeDisplay(currentTime);
     
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
  if (voltReadTimer==0) Value = analogRead(A5);
  if (voltReadTimer + voltReadDelay <= currentTime){
    Value = analogRead(A5);
    voltReadTimer = currentTime;
  }
   float voltage = (Value/1023.0)*5;      //here i am converting the ADC reading
  voltage = voltage * 5;    //here i am multiplying by the 5 we used to divide
  voltage = voltage * 19.38;
  return voltage;
   }

void tempDisplay(int valu) {
  
   for(int j=0; j<50; j++){
    digit = valu/10;
      digitalWrite(sink_1,HIGH);
      digitalWrite(sink_2, LOW);
      digitalWrite(sink_3, LOW);
      setSegments(digit);
      delay (5);
      digit = valu%10;
      digitalWrite(sink_1,LOW);
      digitalWrite(sink_2, HIGH);
      digitalWrite(sink_3, LOW);
      setSegments(digit);
      delay (5);
      digitalWrite(sink_1,LOW);
      digitalWrite(sink_2, LOW);
      digitalWrite(sink_3, HIGH);
      setSegments(10);
      delay (5);
  } 
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

void lowVoltage() {
    for (int x =0; x<5; x++) {
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
  
// setting the bits of the digit to be displayed
void setSegments(byte digit){
  byte mask = 1;
  for(int i=0; i<8; i++){
    if((segmentPattern_1[digit] & mask) == 0) digitalWrite(segmentPin[i],LOW);
    else digitalWrite(segmentPin[i],HIGH);
    
    mask = mask <<1;
  }
}    
