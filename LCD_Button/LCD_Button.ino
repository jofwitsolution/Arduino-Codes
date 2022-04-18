#include <LiquidCrystal.h>


LiquidCrystal lcd(12,11,10,9,8,7);



const int  buttonPin = 13;    // the pin that the Up pushbutton is attached to

const int  buttonPin1 = 3;    // the pin that the Down pushbutton is attached to


// Variables will change:


int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState5 = 0;         // current state of the button
int buttonState6 = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button


void setup() {


  // initialize the button pin as a input:
   
   pinMode(buttonPin, INPUT);
   
   pinMode(buttonPin1, INPUT);
   
   
   lcd.begin(16,2);
   
   lcd.setCursor(0,1);
   
   lcd.print("Volume:");
   
}


void loop() {


   // read the pushbutton up input pin:
   
   buttonState5 = digitalRead(buttonPin);

  // compare the buttonState to its previous state

   if (buttonState5 != lastButtonState) {
    delay(200);
     
     // if the state has changed, increment the counter
     
     if (buttonState5 == LOW)
     
     {
       
      buttonPushCounter++;
      lcd.setCursor(7,1);
           
      lcd.print(buttonPushCounter);
     }
     
      

   }
   // save the current state as the last state,
  //for next time through the loop
   lastButtonState = buttonState5;
   
     // read the pushbutton down input pin:
   
   buttonState6 = digitalRead(buttonPin1);

  // compare the buttonState to its previous state

   if (buttonState6 != lastButtonState) {
     delay(200);
     // if the state has changed, decrement the counter
     
     if (buttonState6 == LOW)
     
     {
       
      buttonPushCounter--;
      lcd.setCursor(7,1);
          
      lcd.print(buttonPushCounter);
     }
     
             
   }
   // save the current state as the last state,
  //for next time through the loop
   lastButtonState = buttonState6; 
   
   
}

