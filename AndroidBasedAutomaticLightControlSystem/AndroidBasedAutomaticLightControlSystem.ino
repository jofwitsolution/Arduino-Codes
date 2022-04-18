int bulb1 = 12;         //relay1
int bulb2 = 11;         //relay2
int bulb3 = 10;          //relay3
int led = 8;             //indicator led

unsigned long currentTime = 0;
unsigned  long delayTime = 0;
String BT_input = "0";
String point = "0";

void setup() {
  // initialize serial communication
  Serial.begin(9600);
  
  // set relay pins as output
  pinMode (bulb1, OUTPUT);
  pinMode (bulb2, OUTPUT);
  pinMode (bulb3, OUTPUT);
  pinMode (led, OUTPUT);

  // turn off all the relays at startup
  digitalWrite(bulb1, LOW);
  digitalWrite(bulb2, LOW);
  digitalWrite(bulb3, LOW);

  // turn on green LED to indicate power on
  digitalWrite(led, HIGH);
  delay(1500);
  digitalWrite(led, LOW);

}

void loop() {

   if (Serial.available()) {
      BT_input = Serial.readString();
      point = BT_input;

      if (BT_input == "0") {
       Serial.println("All bulb are Off");
         point = "0";
      }
      if (BT_input == "1") {
        Serial.println("Bulb 1 Activated");
      }
      if (BT_input == "2") {
        Serial.println("Bulb 2 Activated");
      }
      if (BT_input == "3") {
        Serial.println("Bulb 3 Activated");
      }  
      if (BT_input == "11") {
        Serial.println("Bulb 2 and 3 Activated");
       }  
      if (BT_input == "111") {
        Serial.println("All Bulb Activated");
       }  
   }

  if (analogRead(A5) > 900) { // if ADC value is greater than 900
      currentTime = millis();
      delayTime = 5000;
      //point = "111";
  }

  if (currentTime + delayTime > millis()) { // make bulbs on for 5secs when LDR sense darkness
    point = "111";
    digitalWrite(led, HIGH);
  } else {  // turn bulbs off
      point = BT_input;
      digitalWrite(led, LOW);
  }
  
  if (point == "0") {
    digitalWrite(bulb1, LOW);
    digitalWrite(bulb2, LOW);
    digitalWrite(bulb3, LOW);
  }

  if (point == "1") {
    digitalWrite(bulb1, HIGH);
    digitalWrite(bulb2, LOW);
    digitalWrite(bulb3, LOW);
  }

  if (point == "2") {
    digitalWrite(bulb1, LOW);
    digitalWrite(bulb2, HIGH);
    digitalWrite(bulb3, LOW);
  }

  if (point == "3") {
    digitalWrite(bulb1, LOW);
    digitalWrite(bulb2, LOW);
    digitalWrite(bulb3, HIGH);
  }

  if (point == "11") {
    digitalWrite(bulb1, LOW);
    digitalWrite(bulb2, HIGH);
    digitalWrite(bulb3, HIGH);
  }
  
  if (point == "111") {
    digitalWrite(bulb1, HIGH);
    digitalWrite(bulb2, HIGH);
    digitalWrite(bulb3, HIGH);
  }
  
}
