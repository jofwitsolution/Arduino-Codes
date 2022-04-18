#define tempSensor A0  //LM35 temperature sensor used
#define buttonInput0 A1  //the mode select button
#define buttonInput1 A2  //the speed 1 button
#define buttonInput2 A3  //the speed 2 button
#define buttonInput3 A4  //the speed 3 button
int modeButton;
int button1;
int button2;
int button3;

void setup() {
  Serial.begin(9600);
  //pinMode(buttonInput0, INPUT);
  //pinMode(buttonInput1, INPUT);
  //pinMode(buttonInput2, INPUT);
  //pinMode(buttonInput3, INPUT);
}

void loop() {
  modeButton = analogRead(buttonInput0);
  button1 = analogRead(buttonInput1);
  button2 = analogRead(buttonInput2);
  button3 = analogRead(buttonInput3);
  Serial.println(modeButton);
    Serial.println(button1);
    Serial.println(button2);
    Serial.println(button3);
    Serial.println();
    delay(500);
}
