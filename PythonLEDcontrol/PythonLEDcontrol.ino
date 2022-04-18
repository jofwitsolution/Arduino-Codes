int led=13;
int bulb=12;
int button=11;
char userInput;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(bulb, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  
  if (Serial.available()>0) {

    userInput = Serial.read();
  
    if (userInput == '1') {
      digitalWrite(bulb, HIGH);
      digitalWrite(led, HIGH);
    }
  
    if (userInput == '0') {
      digitalWrite(bulb, LOW);
      digitalWrite(led, LOW);
    }
  }
  }
