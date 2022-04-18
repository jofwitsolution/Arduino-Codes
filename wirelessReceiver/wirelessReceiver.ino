#include <SPI.h>
#include <RH_ASK.h>

RH_ASK driver;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   if(!driver.init()) Serial.println("init failed");
   else Serial.println("Success");
   pinMode(13,OUTPUT);
   digitalWrite(13,HIGH);
   
      for(int i =2;i<6;i++) 
    {
      pinMode(i,OUTPUT);
    }
    delay(1000);
   digitalWrite(13,LOW);
 }

void loop() {
uint8_t buf[5];
  uint8_t buflen = sizeof(buf);
  if(driver.recv(buf, &buflen))   //wait for the receiver to receive a data
  {
    digitalWrite(13,HIGH);
    String maker="";
    for(int i=0;i<5;i++)
    {
      if(buf[i]!=0 || buf[i]!=255)
      {
        maker+=(char)buf[i];
      }
    } 
    Serial.println(maker);
  
if(maker.indexOf("a")!=-1) 
    {
      Serial.println("Successfull 1");
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      delay(2000);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
    }
if(maker.indexOf("b")!=-1) 
     {
      Serial.println("Successfull 2");
       digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      delay(2000);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      }

if(maker.indexOf("c")!=-1)  
    {
      Serial.println("Successfull 3");
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      delay(2000);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
    }
if(maker.indexOf("d")!=-1)  
    {
      Serial.println("Successfull 4");
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      delay(2000);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
    }
}
digitalWrite(13,LOW);
}

