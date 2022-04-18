#include <IRremote.h>
 
#define first_key  12495
#define second_key 6375  
#define third_key  31365
#define fourth_key 4335
#define fifth_key  14535
int receiver_pin = 8;   
unsigned long key_value = 0;

int first_led_pin = 7;
int second_led_pin = 6;
int third_led_pin = 5;
int fourth_led_pin = 4;
int fifth_led_pin = 2;
int ledArray[] = {7,6,5,4,2}; //creating an array of leds
int led[] = {0,0,0,0,0}; //setting an initial value zero for all led
IRrecv receiver(receiver_pin); 
decode_results output;
 
void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn();  
  pinMode(first_led_pin, OUTPUT);
  pinMode(second_led_pin, OUTPUT);
  pinMode(third_led_pin, OUTPUT);
  pinMode(fourth_led_pin, OUTPUT);
  pinMode(fifth_led_pin, OUTPUT);
  }
 
void loop() {
  if (receiver.decode(&output)) {
    unsigned int value = output.value;
    if (value== 65535)
    value = key_value;
    switch(value) {
       case first_key:    
         if(led[1] == 1)  //test if the first led[1] is 1, if it's not 1, go to the else loop and put ON the led . 
         {       
            digitalWrite(first_led_pin, LOW);
            led[1] = 0; //led[1] becomes zero, so that when the remote is pressed again the led will be ON.          
         } else {                      
             digitalWrite(first_led_pin, HIGH); 
             led[1] = 1;  //led[1] becomes 1 so that when the remote is pressed second time the led is OFF.        
         }
          break; 
       case second_key:
      
         if(led[2] == 1) {
            digitalWrite(second_led_pin, LOW);
            led[2] = 0;
         } else {
             digitalWrite(second_led_pin, HIGH);
             led[2] = 1;
         }
          break;
       case third_key:
      
         if(led[3] == 1) {
            digitalWrite(third_led_pin, LOW);
            led[3] = 0;
         } else {
             digitalWrite(third_led_pin, HIGH);
             led[3] = 1;
         }
          break;   
          case fourth_key:
            if(led[4] == 1) {
                 digitalWrite(fourth_led_pin, LOW); 
                  led[4] = 0;         
         }                       
             else {digitalWrite(fourth_led_pin, HIGH); 
             led[4] = 1; }          
         break;
       case fifth_key:
            if(led[5] == 1) {
                 digitalWrite(fifth_led_pin, LOW); 
                  led[5] = 0;         
         }                       
             else {digitalWrite(fifth_led_pin, HIGH); 
             led[5] = 1; }          
         break;
         default :
                   Serial.print(value);
                   Serial.println(" was received but not expected");
                     break;  
                  
    }
    if (value == 26775) {
      for (int i=0; i<=4; i++) {
    digitalWrite(ledArray[i], LOW);    
      }
    }
    if (value == 49725) {
    for (int i=0; i<=4; i++) {
    digitalWrite(ledArray[i], HIGH);    
      }  
    }
    
    
    Serial.println(value); 
receiver.resume();
  }
}
