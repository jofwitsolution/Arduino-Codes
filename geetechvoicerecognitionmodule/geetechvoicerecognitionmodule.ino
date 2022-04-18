const int latch = 12;
const int redLed = 8;
const int instruction = 5;
const int greenLed = 7;
byte com = 0;
int One = 0;
int Two = 0;
int Three = 0;
bool wrongInput = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(latch, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(instruction, INPUT);
  pinMode(greenLed, OUTPUT);

  digitalWrite(latch, LOW);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  
  Serial.begin(9600);
  delay(2000);
  
  Serial.write(0xAA);
  Serial.write(0x37);
  delay(1000);
  Serial.write(0xAA);
  Serial.write(0x22);

}

void loop() {
// put your main code here, to run repeatedly:
  
  while (Serial.available()) {
    com = Serial.read();
    Serial.println(com);
    switch(com) {
      case 0x11: digitalWrite(redLed, HIGH);
      break;
      case 0x12: digitalWrite(latch, HIGH);
      break;
      case 0x13: digitalWrite(greenLed, HIGH);
      break;
      case 0x14: onLeds();
      break;
      case 0x15: offLeds();
      break;
      
    }
  }

//      switch(com) {
//      case 0x11: One = 1;
//      break;
//      case 0x14: Two = 2;
//      break;
//      case 0x15: Three = 3;
//      break;
//  }
//
//  // unlock door
//  if (One == 1 && Two == 2) {
//    digitalWrite(greenLed, HIGH);
//    digitalWrite(redLed, LOW);
//    digitalWrite(latch, HIGH);
//    delay(1000);
//    //delay(200);   
//    digitalWrite(2, LOW);           
//    One = 0;
//    Two = 0;
//     wrongInput = false;
//   }
//
//   // lock door
//   if (One == 1 && Three == 3) {
//    digitalWrite(greenLed, LOW);
//    digitalWrite(redLed, HIGH);
//    digitalWrite(latch, LOW);      
//    One = 0;
//    Three = 0;
//    wrongInput = false;
//   }
//
//   // wrong voice input 
//   if (wrongInput) {
//      digitalWrite(redLed, HIGH);
//      delay(1000);
//      digitalWrite(redLed, LOW);
//     
//    }
// 
//   }
//
//   wrongInput = true; // set back to true
//  }

 }

void offLeds() {
  digitalWrite(redLed, LOW);
  digitalWrite(latch, LOW);
  digitalWrite(greenLed, LOW);
}

void onLeds() {
  digitalWrite(redLed, HIGH);
  digitalWrite(latch, HIGH);
  digitalWrite(greenLed, HIGH);
}
