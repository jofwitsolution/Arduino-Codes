#define PIN_DMD_nOE 9 f
#define PIN_DMD_A 6 // D6
#define PIN_DMD_B 7 // D7
#define PIN_DMD_CLK 52
#define PIN_DMD_SCLK 53 /
#define PIN_DMD_R_DATA 51


#include <EEPROM.h>
//char text[70];
char mode ='0';
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println(testing());

  if (Serial.available()) {
      mode = Serial.read();
      Serial.println(mode);
   }
 
  if (mode == '1') {
    Serial.println("correct");
  }









//  char value[62];
//for (int i=0; i<61; i++) {
//  value[i] = EEPROM.read(101 + i);
//  //Serial.println(value[i]);
//}
//value[61] = '\0';
//for (int i=0; i<61; i++) {
//  Serial.println(value[i]);
//  delay(20);
//}
//
//String result = "";
//for (int i=0; i<sizeof(value); i++) {
//  result+=value[i];
//}
//
//delay(5000);
//Serial.println(result);
//delay(2000);

  
}

String testing() {
  char text[200] = "WELCOME TO THE DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";
  return String(text); 
}
