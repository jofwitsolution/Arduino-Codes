/*
 * Arduino Wireless Communication Tutorial
 * Example 2 - Receiver Code
 *
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 *
 * Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
 */

 #include <SPI.h>
 #include <nRF24L01.h>
 #include <RF24.h>
 #include <Servo.h>

 #define button 2

 RF24 radio(7, 8); // CE, CSN
 const byte addresses[][6] = {"00001", "00002"};
 Servo myServo;
 boolean buttonState = 0;
 boolean button_State = 0;
 String serialInput;

 void setup() {
 pinMode(2, INPUT);
 pinMode(12, OUTPUT);
 myServo.attach(5);
 radio.begin();
 radio.openWritingPipe(addresses[0]); // 00001
 radio.openReadingPipe(1, addresses[1]); // 00002
 radio.setPALevel(RF24_PA_MIN);
 }
void loop() {
 delay(5);
 radio.startListening();
 if ( radio.available()) {
 while (radio.available()) {
 String receivedInput;
 radio.read(&receivedInput, sizeof(receivedInput));
 radio.read(&button_State, sizeof(button_State));
 if (button_State==HIGH){
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
 }
 Serial.println(receivedInput);
 
 }
 delay(5);
 radio.stopListening();
 if (Serial.available()>) {
  serialInput = Serial.readString();
 }
 buttonState = digitalRead(2);
 radio.write(&serialInput, sizeof(serialInput));
 radio.write(&buttonState, sizeof(buttonState));
}
}
