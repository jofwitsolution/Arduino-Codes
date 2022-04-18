#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int redPin = 10;
const int greenPin = 11;
unsigned long key_value = 0;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    if (results.value ==0xFFFFFFFF) 
     results.value = key_value;
    

    switch (results.value) {
      case 0xFF38C7: digitalWrite(redPin, HIGH);
      delay(2000);
      //if (results.value==0xFF38C7)
      //digitalWrite(redPin, LOW);
      break;
      case 0xFF18E7: digitalWrite(greenPin, HIGH);
      delay(2000);
      digitalWrite(greenPin, LOW);
       
    }
         irrecv.resume();
    
  }
}

