#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;
const int relayIn = 8;
int relay[] = {0, 0};
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(relayIn, OUTPUT);
  
}

void loop() {
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    if (results.value ==0xFFFFFFFF) 
     results.value = key_value;

  if (results.value == 0x20DF10EF) {
     if (relay[1] == 1) {
    digitalWrite(relayIn, LOW);
       relay[1] = 0; }    
     else {
      digitalWrite(relayIn, HIGH);
     // delay(5000);
      relay[1] = 1; }
    
  }
         irrecv.resume();
    
  }
}

