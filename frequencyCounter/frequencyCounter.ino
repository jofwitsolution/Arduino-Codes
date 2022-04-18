/*
Interrupts sketch
AC frequency counter with Arduino
*/
#define INT0 2

volatile unsigned long currentTime;
volatile unsigned long previousTime;
volatile byte counter = 0;
volatile byte frequency;
volatile unsigned long results[10];
void setup() {
  Serial.begin(9600);
  currentTime = 0;
  attachInterrupt(digitalPinToInterrupt(INT0), freqCount, RISING); // encoder pin on interrupt 0 (pin 2);

}
void loop() {
  while (currentTime + 1000 >= millis()) frequency = counter; //wait and store cycles completed in one second
  //while (millis() - currentTime < 1000) frequency = counter;
  Serial.print("Freq = ");
  Serial.println(frequency);

    //print the duration for ten complete cycles of the sine wave
    Serial.println("Durations in Milliseconds are:") ;
    for( byte i=0; i < 10; i++) {
      Serial.println(results[i]);
      }
  counter = 0;  //Restart counter
  currentTime = millis(); //Restart Timer

}
void freqCount() {

    //Taking reading of the time interval for ten complete cycles
    if (counter >= 0) {
     if (counter < 10) 
     results[counter] = millis() - previousTime;
    }
     counter = counter + 1;   //counting the frequency at rising edge of the clock pulse
     previousTime = millis(); //Restart timer

}
