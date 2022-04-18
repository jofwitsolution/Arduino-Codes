
#include <IRremote.h>


int RECV_PIN = 8; 

IRrecv irrecv(RECV_PIN);

decode_results results;

long ONE= 534977760;
long TWO= 535010400;
long THREE= 535047120;
long FOUR= 535051200;

int state = 0;
int state2 = 0;
int brightness = 51;
int led1 = 6;
int led2 = 5;
int button1 = 10;
int button2 = 9;
int one = 0;


void setup() {

    pinMode (led1, OUTPUT);
    pinMode (led2, OUTPUT);
    pinMode (button1, OUTPUT);
    pinMode (button2, OUTPUT);
    digitalWrite(button1, HIGH);
    digitalWrite(button2, HIGH);
    Serial.begin(9600);

  irrecv.enableIRIn(); // Start the receiver
  //pinMode(led, OUTPUT);
 }
 
void loop() {

  setBrightness();
  Serial.println(brightness);
  if (digitalRead(button1)==LOW && irrecv.decode(&results)==false) {
    delay(100);
    state++;
  }
  if (digitalRead(button2)==LOW && irrecv.decode(&results)==false) {
    delay(100);
    state2++;
  }
    
  
 if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
      if(results.value==ONE) {
      state = state + 1;
    }
    if (results.value==TWO) {
      state2 = state2 + 1;
    }
 
     irrecv.resume(); // Receive the next value i.e to recieve the next input by clearing the previous one
     delay(100);
  }

  if (state == 1) analogWrite(led1, brightness);
  else digitalWrite(led1, LOW);

  if (state2 == 1) analogWrite(led2, brightness);
  else digitalWrite(led2, LOW);
  
  
  if (state == 2) state=0;
  if (state2 == 2) state2=0;
 delay(100);
} 

void setBrightness() {
  if (state!=0 || state2!=0) {
      if (irrecv.decode(&results)) {
        if (results.value==THREE && brightness<255) brightness=brightness+51;
        if (results.value==FOUR && brightness>50) brightness=brightness-51;
      }
  }
}

