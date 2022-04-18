#include <EEPROM.h>

const byte EEPROM_ID = 0x99;
int addr_0 = 0;

String text = "welcome home";
int lengthOfText = 0;

char * users[] = {
  "tom",
  "dick",
  "harry",
  "harry"
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {

  byte id = EEPROM.read(addr_0); // read the first byte from the EEPROM
  if( id == EEPROM_ID) {
    text = "";
    lengthOfText = EEPROM.read(1023);
    Serial.println(lengthOfText);
    for (int x=0; x<lengthOfText; x++) {
     // text += String(EEPROM.read(x + 1)); 
     Serial.println(EEPROM.read(x + 1));
    }
  }
  else {// this code is executed once after the program is uploaded on the controller
    EEPROM.write(addr_0, EEPROM_ID);
    lengthOfText = text.length() + 1;
    char charBuf[lengthOfText];
    Serial.println(lengthOfText);
    text.toCharArray(charBuf, lengthOfText);

    for (int x=0; x<lengthOfText; x++) {
      Serial.println(charBuf[x]);
      EEPROM.write(x+1, charBuf[x]);
    }
    EEPROM.write(1023, lengthOfText);
  }
  
  if (Serial.available()) {
    text = Serial.readString();
    lengthOfText = text.length() + 1;
    char charBuf[lengthOfText];
    Serial.println(lengthOfText);
    text.toCharArray(charBuf, lengthOfText);

    for (int x=0; x<lengthOfText; x++) {
      Serial.println(charBuf[x]);
      EEPROM.write(x+1, charBuf[x]);
    }
    EEPROM.write(1023, lengthOfText);
  }

  

  Serial.print("Text = ");
  Serial.println(text);
  delay(1000);
}


// This function split string. It takes two arg the String to split and the char to be used to split.
String * split(String dateTime, String Char) {
  
  int i = 0;
  int charPosition = 0; 
  static String result[7];  // static pointer string array
 
  do  {
    charPosition = dateTime.indexOf(Char);
    if(charPosition != -1) {
      //Serial.println( dateTime.substring(0, charPosition));
      result[i] = dateTime.substring(0, charPosition);  //return text starting from index 0 and less than charPosition(index)
      dateTime = dateTime.substring(charPosition+1, dateTime.length()); // overwrite dateTime with text after charPosition 
      i++;  // increment the array
    }
    else  { // here after the last char is found
      if(dateTime.length() > 0) {
      // if there is text after the last char, store it
      result[i] = dateTime;
        }
      }
    }
  while(charPosition >=0);

  return result;
} // end of split()


// This function split string. It takes two arg the String to split and the char to be used to split.
String * splitEx(String dateTime) {
  
  int i = 0;
  int Length = 1; 
  static String result[7];  // static pointer string array
 
  do  {
    if(Length != 0) {
      result[i] = dateTime.substring(0, 1);  //return text starting from index 0 and less than charPosition(index)
      dateTime = dateTime.substring(1, dateTime.length()); // overwrite dateTime with text after charPosition 
      Length = dateTime.length();
      i++;  // increment the array
    }
  }
  while(Length > 0);

  return result;
} // end of split()
