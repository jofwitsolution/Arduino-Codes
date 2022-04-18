#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup()
{
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
         else Serial.println("Success");
         pinMode(2,OUTPUT);
         //pinMode(8,INPUT);
        // pinMode(9,INPUT);
         digitalWrite(2,HIGH);
         //digitalWrite(8,HIGH);
         //digitalWrite(9,HIGH);
         delay(1000);
         digitalWrite(2,LOW);
    for(int i =6;i<10;i++) 
    {
      pinMode(i,INPUT);
      digitalWrite(i,HIGH);
    }
}
//853//819//785//
void loop(){   
  const char *thief = "a";
    const char *usg="a";
    const char *dsg="b";
    const char *lsg="c";
    const char *rsg="d";
//    char con=Serial.read();
if(digitalRead(6)==LOW)
     {delay(150);
      for(int s=0;s<2;s++) driver.send((uint8_t *)thief, strlen(thief));
      digitalWrite(2,HIGH);
     }
    if(digitalRead(7)==LOW)
     {delay(150);
      for(int s=0;s<2;s++) driver.send((uint8_t *)usg, strlen(usg));
      digitalWrite(2,HIGH);
     }
    else if(digitalRead(7)==LOW)
     {delay(150);
      for(int s=0;s<2;s++) driver.send((uint8_t *)dsg, strlen(dsg));
      digitalWrite(2,HIGH);
     }
     else if(digitalRead(8)==LOW)
     {
      for(int s=0;s<2;s++) driver.send((uint8_t *)lsg, strlen(lsg));
      digitalWrite(2,HIGH);
     }
     else if(digitalRead(9)==LOW)
     {
      for(int s=0;s<2;s++) driver.send((uint8_t *)rsg, strlen(rsg));
      digitalWrite(2,HIGH);
     }
    driver.waitPacketSent();  //wait for the message to be received
    delay(500);
    digitalWrite(2,LOW);
}
