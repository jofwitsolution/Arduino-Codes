/*
 * Arduino Wireless Communication Tutorial
 * Example 2 - Transmitter Code
 *
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 *
 * Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
 */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define led 6
 RF24 radio(7, 8); // CE, CSN
 const byte addresses[][6] = {"00001", "00002"};
 boolean buttonState = 0;
 String serialInput;
 String receivedInput;
 boolean transmButtonState = 0;

 void setup() {
  Serial.begin(9600);
 pinMode(6, OUTPUT);
 pinMode(2, INPUT);

 radio.begin();
 radio.openWritingPipe(addresses[1]); // 00002
 radio.openReadingPipe(1, addresses[0]); // 00001
 radio.setPALevel(RF24_PA_MIN);
 }

 void loop() {
  if (Serial.available()>0) {
    serialInput = Serial.readString();
  }
 delay(5);
  transmButtonState = digitalRead(2);
  
  radio.stopListening();
  //while (!Serial.available());
  int str_len = serialInput.length()+1;
  char char_array[str_len];
serialInput.toCharArray(char_array, str_len);
  //char serialInput[] = "\serialInput";
  Serial.println(char_array);
  //while (!transmButtonState==HIGH);
  radio.write(&char_array, sizeof(char_array));
  //radio.write(&transmButtonState, sizeof(transmButtonState));

 delay(5);
 radio.startListening();
 //while (!radio.available());
 radio.read(&receivedInput, sizeof(receivedInput));
 radio.read(&buttonState, sizeof(buttonState));
 //Serial.print(receivedInput);
 if (buttonState == HIGH) {
 digitalWrite(led, HIGH);
 delay(500);
 digitalWrite(led, LOW);
 }
 else {
 digitalWrite(led, LOW);
}
}
