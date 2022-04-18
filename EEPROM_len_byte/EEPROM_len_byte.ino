#include <EEPROM.h> 

const byte EEPROM_ID = 0x99;
int addr_0 = 0;
String text = "Save String to EEPROM. Save String to EEPROM. Save String to EEPROM. Save String to EEPROM. Save String to EEPROM. Save String to EEPROM. Save String to EEPROM. Save String to EEPROM. Save String to EEPROM. Save String to EEPROM.";
//String newStr2;

void setup() { 
  Serial.begin(9600); 
  
} 

  void loop() {

    byte id = EEPROM.read(addr_0); // read the first byte from the EEPROM
  if( id == EEPROM_ID) {
     text = readStringFromEEPROM(100);  
  }
  else {// this code is executed once after the program is uploaded on the controller
    EEPROM.write(addr_0, EEPROM_ID);
    int textLen = writeStringToEEPROM(100, text);
    
  }
  
  if (Serial.available()) {
    text = Serial.readString();
    int textLen = writeStringToEEPROM(100, text);
  }

  

  Serial.print("Text = ");
  Serial.println(text);
  delay(1000);
} 
      
int writeStringToEEPROM(int addrOffset, const String &strToWrite) { 
  int count = 1;
  int len = strToWrite.length(); 
  Serial.println(len);
  if (len > 254) {  // if string length is greater than a byte(255)
    EEPROM.write(addrOffset, 254);  // write 254 to EEPROM
    int remainder = len - 254;      //  get the remainder
    while (remainder > 254) {       // while the remainder is still greater than 254
       EEPROM.write(addrOffset + count, 254); // write 254 to the next address
       remainder = remainder - 254;
       count++;   //  increment address
       if (count == 3) break; // break bcus we dont want length of charact to exceed EEPROM limit
    }
    if (remainder > 254) return 0; // return if the remaining character length is too much for the EEPROM
    
    byte remByte = remainder;
    Serial.println(remByte);
    EEPROM.write(addrOffset + count, remByte);  // store the remaining length in EEPROM
    count++;  // move to the next address
  }
  else { // otherwise
    EEPROM.write(addrOffset, len);  
  }
   
  for (int i = 0; i < len; i++) { 
    EEPROM.write(addrOffset + count + i, strToWrite[i]);  // write characters to EEPROM
    } 
    
    return len; // return length of characters
 } 

String readStringFromEEPROM(int addrOffset) { 
    int count = 1;
    int totalLen = 0;
    int newStrLen = EEPROM.read(addrOffset);
    totalLen = newStrLen;
    
    while (newStrLen == 254) {
      newStrLen = EEPROM.read(addrOffset + count);
      totalLen += newStrLen;
      Serial.println(totalLen);
      count++;
    }
    
    Serial.println(count);
    char data[totalLen + 1]; 
    for (int i = 0; i < totalLen; i++) { 
      data[i] = EEPROM.read(addrOffset + count + i); 
     } 

     data[totalLen] = '\0';  
     
     return String(data);
} 
