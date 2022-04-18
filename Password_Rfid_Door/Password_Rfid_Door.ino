#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

const int columnOne=2;
const int columnTwo=3;
const int columnThree=4;
const int DoorOne=12;
const int DoorTwo=13;
const int Buzzer=11;

//LiquidCrystal lcd(4,5,6,7,8,9);
LiquidCrystal lcd(10,9,8,7,6,5);
//SoftwareSerial rfid(10,1);
short wrongTimes = 0;
int tCurrent;
int tRfidNumberLocation;
String tRfidNumber;
String tPassword;

void setup() {
  // put your setup code here, to run once:
  
//  for (int i = 0; i < 512; i++)
//    EEPROM.write(i, 0);

  pinMode(columnOne,OUTPUT);
  pinMode(columnTwo,OUTPUT);
  pinMode(columnThree,OUTPUT);
  pinMode(DoorOne,OUTPUT);
  pinMode(DoorTwo,OUTPUT);
  pinMode(Buzzer,OUTPUT);
//  digitalWrite(Buzzer,HIGH);
  Serial.begin(9600);
//  rfid.begin(9600);

  lcd.begin(16,2);
  
  
  tRfidNumberLocation=-1;
  tCurrent=EEPROM.read(0);
  if(tCurrent==0||tCurrent==255) tCurrent=1;
  for(int i=10;i<310;i++)
  {
    if(i%10==0)
    {
      if(EEPROM.read(i)==0 || EEPROM.read(i)==255)
      {
        tRfidNumberLocation=i;
//        Serial.print("The Current Location for New Users will be ");
//        Serial.println(tRfidNumberLocation);
        break;
      }
    }
  }
  if(tRfidNumberLocation==-1) tRfidNumberLocation=300;
  lcd.setCursor(0,0);
  lcd.print("Starting System");
  delay(2000);
  lcd.clear();
  for(int i=0; i<3; i++){
  digitalWrite(Buzzer,HIGH);
  delay(500);
  digitalWrite(Buzzer,LOW);
  delay(250);
  }
  lcd.setCursor(0,0);
  lcd.print("     Ready     ");
  delay(1500);
  lcd.clear();
  if(EEPROM.read(2)==0 || EEPROM.read(2)==255)
  {
    //no master details exist thus must create one
//    Serial.println("Master Details does not exist, Create one");
    //add tag first
    
    //get tag number
    tRfidNumber="";
    lcd.setCursor(0,0);
    lcd.print("Swipe your card");
    while(Serial.available()<=0);
    lcd.setCursor(0,0);
    lcd.print(" Card detected ");
    long time=millis();
    while(millis()-time<1000)
    {
      if(Serial.available())
      {
        char charHolder=Serial.read();
        tRfidNumber+=charHolder;
      }
    }
    String lastFourNumbersOfIncomingTag=
    tRfidNumber.substring(tRfidNumber.length()-4);
//    Serial.print("Master Tag is ");
//    Serial.println(tRfidNumber);
    //add tag
    int inter=0;
    for(int i=2; i<6; i++)
    {
      EEPROM.write(i,lastFourNumbersOfIncomingTag
      .charAt(inter));
      inter++;
      delay(10);
      lcd.setCursor(0,0);
      lcd.print("RFID Card Saved.");
//      Serial.print("Saved last four digits as in ");
//      Serial.println(lastFourNumbersOfIncomingTag);
    }
    
    String confirmedPassword="eee";  
    while(confirmedPassword!=tPassword)
    {
      //then add password
//      Serial.println("Enter Master Password");
      tPassword="";
      int counter=0;
      lcd.setCursor(0,0);
      lcd.print("   Enter Pin    ");
      while(counter<4)
      {
        char charHolder='C';
        while(charHolder=='C' || charHolder=='B'||
        charHolder=='A') 
          charHolder=transMutate(keypad());
          
        lcd.setCursor(4+counter,1);
        lcd.print('*');
        //lcd.print(charHolder);
        tPassword+=charHolder;
        counter++;
        delay(300);
      }
//      Serial.println();
//      Serial.println("Master Password Entered");
      confirmedPassword="";
      counter=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter Pin Again.");
//      Serial.println("Confirm Password");
      while(counter<4)
      {
        char charHolder='C';
        while(charHolder=='C' || charHolder=='B'|| charHolder=='A')
        charHolder=transMutate(keypad());
//        Serial.print(charHolder);
        lcd.setCursor(4+counter,1);
        lcd.print('*');
        //lcd.print(charHolder);
        confirmedPassword+=charHolder;
        counter++;
        delay(300);
      }
//      Serial.println();
      counter=0;
      if(tPassword==confirmedPassword)
      {
        for(int i=6;i<10;i++)
        {
          EEPROM.write(i,tPassword.charAt(counter));
          counter++;
        }
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" Password Saved.");
        delay(500);
//        Serial.println("Saved Master Password");
      }
//      else Serial.println("Password MIsmatch");
    }
  }
  delay(1000);
  lcd.clear();
}
int countersing=0;

void loop() 
{
//  if(countersing==0)
//{lcd.setCursor(0,0);lcd.print("Starting Loop");}
//  if(keypad()!=12) Serial.println(keypad());
        lcd.setCursor(0,0);
        lcd.print("    Welcome    ");
        lcd.setCursor(0,1);
        lcd.print("  Card, please  ");
  if(Serial.available()>0)
  {
    tRfidNumber="";
    long timering=millis();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Reading Card");
    while(millis()-timering<1000)
    {
      if(Serial.available())
      {
        char valve=Serial.read();
        tRfidNumber+=valve;
      }
    }
//    Serial.print("Tag is ");
//    Serial.println(tRfidNumber);
    String allTags=gatherAllTags();
    String lastFourNumbersOfIncomingTag=
    tRfidNumber.substring(tRfidNumber.length()-4);
    int indexer=allTags.indexOf(lastFourNumbersOfIncomingTag);
    if(indexer!=-1)
    {
      //card Exist within the database
      //go on to get Finger Print
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.println("Card Exists");
      int location=indexer/4+1;
      location*=10;
      location+=6;
      String recoveredPassword=getPassword(location);
      //Serial.print("Password expected is ");
      //Serial.println(recoveredPassword);
      delay(1000);
      
      tPassword="";
      int counter=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("   Enter PIN   ");
      while(counter<4)
      {
        char charHolder='C';
        while(charHolder=='C' || charHolder=='B'
        || charHolder=='A')
        charHolder=transMutate(keypad());
        lcd.setCursor(4+counter,1);
        lcd.print('*');
        //lcd.print(charHolder);
        tPassword+=charHolder;
        counter++;
        delay(300);
      }
      //Serial.print("Password inputed is ");
      //Serial.println(tPassword);
      lcd.clear();
      if(tPassword==recoveredPassword)
      {
        //its a match
        //open the door now
        lcd.setCursor(0,0);
        lcd.print("  Opening Door  ");
        digitalWrite(DoorOne,HIGH);
        digitalWrite(DoorTwo,LOW);
        delay(3000);
        lcd.setCursor(0,0);
        lcd.print("  Closing Door   ");
        digitalWrite(DoorOne,LOW);
        digitalWrite(DoorTwo,HIGH);
        delay(3000);
        digitalWrite(DoorOne,LOW);
        digitalWrite(DoorTwo,LOW);
        
      }
      else 
      {
        //tell them invalid password 
        //i.e. finger does not match card
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("  PIN not match ");
        //delay(2000);
        digitalWrite(Buzzer,HIGH);
        delay(500);
        digitalWrite(Buzzer,LOW);
        delay(500);
        digitalWrite(Buzzer,HIGH);
        delay(500);
        digitalWrite(Buzzer,LOW);
        delay(500);
        wrongTimes++;
      //delay(1500);
      lcd.clear();
      if(wrongTimes > 3)
      {
        //send message to server
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.println("Relax and ReThink");
        wrongTimes = 0;
        digitalWrite(Buzzer,HIGH);
        delay(5000);
        lcd.clear();
        digitalWrite(Buzzer,LOW);
           
      }
    }
    }
    else 
    {
      //tell them such card does not exist
      //within the database of the System
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("  Invalid Card  ");
      delay(2000);
      lcd.clear();
      }
    }
  
  else
  {
    //to add another password
    if(keypad()==11)
    {
      //it is in the new password mode
      // so move on to check tag
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.println("PIN Mode Entered");
      tRfidNumber="";
      while(Serial.available()<=0);
      long time=millis();
      while(millis()-time<1000)
      {
        if(Serial.available())
        {
          char charHolder=Serial.read();
          tRfidNumber+=charHolder;
        }
      }
      //Serial.print(" Number of Card is ");
      //Serial.println(tRfidNumber);
      String masterTag=getMasterCard();
      String lastFourNumbersOfIncomingTag=
      tRfidNumber.substring(tRfidNumber.length()-4);
      //Serial.println(masterTag);
      if(masterTag==lastFourNumbersOfIncomingTag)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.println(" Card is Master ");
        delay(1000);
        //it is the master Card
        
        String recoveredPassword=getPassword(6);
        //Serial.print("Password expected is ");
        //Serial.println(recoveredPassword);
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.println("Enter master PIN");
        tPassword="";
        int counter=0;
        while(counter<4)
        {
          char charHolder='C';
          while(charHolder=='C' || charHolder=='B'
          || charHolder=='A')
          charHolder=transMutate(keypad());
          tPassword+=charHolder;
          lcd.setCursor(4+counter,1);
          lcd.print('*');
          //lcd.print(charHolder);
          counter++;
          delay(300);
        }
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("PIN is Master");
        //Serial.println(tPassword);
        
        if(tPassword==recoveredPassword)
        {
          //add a new user
          if(tCurrent<=30)
          {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" Swipe card you ");
        lcd.setCursor(0,1);
        lcd.print("  wish to Add   ");
            tRfidNumber="";
            while(Serial.available()<=0);
            long timer=millis();
            while(millis()-timer<1000)
            {
              if(Serial.available())
              {
                char charHolder=Serial.read();
                tRfidNumber+=charHolder;
              }
            }
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Card Discovered");
            //Serial.println(tRfidNumber);
            lastFourNumbersOfIncomingTag="";
            String allTags=gatherAllTags();
            lastFourNumbersOfIncomingTag=
            tRfidNumber.substring(tRfidNumber.length()-4);
            int indexer=allTags.indexOf(lastFourNumbersOfIncomingTag);
            String confirmedPassword="eee";
            if(indexer==-1)
            {
              //tag does not exist,
              //thus can be added as a new tag
              //add tag 
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Tag does'nt exist");
              delay(1000);
              int inter=0;
              for(int i=tRfidNumberLocation; i<tRfidNumberLocation+4;i++)
              {
                EEPROM.write(i,lastFourNumbersOfIncomingTag.charAt(inter));
                inter++;
                delay(10);
              }
              //Serial.println("Tag Added");
              
              while(confirmedPassword!=tPassword)
              {
                //add password
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("  Enter New PIN ");
                tPassword="";
                int counter=0;
                while(counter<4)
                {
                  char charHolder='C';
                  while(charHolder=='C' || charHolder=='B'
                  || charHolder=='A')
                  charHolder=transMutate(keypad());
                  //Serial.print(keypad());
                  lcd.setCursor(7+counter,1);
                  lcd.print('*');
                  //lcd.print(charHolder);
                  tPassword+=charHolder;
                  counter++;
                  delay(1000);
                }
                //Serial.println();
                counter=0;
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Enter PIN Again");
                confirmedPassword="";
                while(counter<4)
                {
                  char charHolder='C';
                  while(charHolder=='C' || charHolder=='B'
                  || charHolder=='A')
                  charHolder=transMutate(keypad());
                  lcd.setCursor(7+counter,1);
                  lcd.print('*');
                  //lcd.print(charHolder);
                  //Serial.print(keypad());
                  confirmedPassword+=charHolder;
                  counter++;
                  delay(1000);
                }
                //Serial.println();
                counter=0;
                if(confirmedPassword==tPassword)
                {
                  for(int i=tRfidNumberLocation+6;i<tRfidNumberLocation+10;i++)
                  {
                    EEPROM.write(i,tPassword.charAt(counter));
                    counter++;
                  }
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("  Saved New PIN  ");
                }
                else 
                {
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.println("  PIN MisMatch  ");
                }
              }
              tRfidNumberLocation+=10;
              }
            else 
            {
              //tag already exists for a current user
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.println("Tag Already Exist");
            }
            }
          else 
          {
            //maximum number of finger prints have been added
            //Sorry you can no longer add more
            lcd.clear();
              lcd.setCursor(0,0);
            lcd.println(" Maximum Users  ");
          }
          }
        else 
        {
          //you have put in a wrong password
          lcd.clear();
              lcd.setCursor(0,0);
          lcd.print("Wrong PIN entered");
        }
        }
      else 
      {
        //it is a not the master tag
        //try againg with the master tag
        lcd.clear();
        lcd.print("Not Master Card");
      }
      }
    else if(keypad()==10)
    {
      //you want to change your password
      //Serial.println("Wanna Change an Existing Password!");
      //Serial.println(keypad());
      //get Tag details
      lcd.setCursor(0,0);
      lcd.print("  Swipe Card Now  ");
      tRfidNumber="";
      while(Serial.available()<=0);
      long time=millis();
      while(millis()-time<1000)
      {
        if(Serial.available())
        {
          char charHolder=Serial.read();
          tRfidNumber+=charHolder;
        }
      }
      //Serial.print("You are trying to change ");
      //Serial.println(tRfidNumber);
      //Serial.println(" Password");
      String lastFourNumbersOfIncomingTag="";
      String allTags=gatherAllTags();
      lastFourNumbersOfIncomingTag=
      tRfidNumber.substring(tRfidNumber.length()-4);
      int indexer=allTags.indexOf(lastFourNumbersOfIncomingTag);
      //Serial.print("EveryTag ");
      //Serial.println(allTags);
      //Serial.println(indexer);
      if(indexer!=-1)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("  Card Exists  ");
        delay(1000);
        int location=indexer/4+1;
        location*=10;
        location+=6;
        //Serial.print("location is ");
        //Serial.println(location);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("  Enter New PIN  ");
        
        tPassword="";
        int counter=0;
        while(counter<4)
        {
          char charHolder='C';
          while(charHolder=='C' || charHolder=='B'
          || charHolder=='A')
          charHolder=transMutate(keypad());
          tPassword+=charHolder;
                  lcd.setCursor(4+counter,1);
                  lcd.print('*');
                  //lcd.print(charHolder);
          counter++;
          delay(1000);
        }
        counter=0;
        //Serial.print("Password inputed is ");
        //Serial.println(tPassword);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("  Enter PIN again ");
        
        String confirmPassword="";
        while(counter<4)
        {
          char charHolder='C';
          while(charHolder=='C' || charHolder=='B'|| charHolder=='A')
          charHolder=transMutate(keypad());
          confirmPassword+=charHolder;
                  lcd.setCursor(4+counter,1);
                  lcd.print('*');
                  //lcd.print(charHolder);
          counter++;
          delay(1000);
        }
        //Serial.print("Confirm Password inputed is ");
        //Serial.println(confirmPassword);
        if(confirmPassword==tPassword)
        {
          changePassword(location,tPassword);
          lcd.clear();
          lcd.print("  PIN Changed  ");
        }
        else
        {
          //different Passwords in-putted
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.println("  PIN Mismatch  ");
        }
      }
      else 
      {
        //such card does not exist
        //Serial.println("You cannot change the password because a ");
//        Serial.println("user with such tag doesńt Exist");

          lcd.clear();
          lcd.setCursor(0,0);
          lcd.println("Tag Doesńt Exist");
      }
    }
  }
}
char transMutate(int theKey)
{
  switch(theKey)
  {
    case 0: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
  }
}

int keypad()
{
  digitalWrite(columnOne,HIGH);
  digitalWrite(columnTwo,LOW);
  digitalWrite(columnThree,LOW);
  if(analogRead(0)>512) return 1;
  if(analogRead(1)>512) return 4;
  if(analogRead(2)>512) return 7;
  if(analogRead(3)>512) return 10;
  
  digitalWrite(columnOne,LOW);
  digitalWrite(columnTwo,HIGH);
  digitalWrite(columnThree,LOW);
  if(analogRead(0)>512) return 2;
  if(analogRead(1)>512) return 5;
  if(analogRead(2)>512) return 8;
  if(analogRead(3)>512) return 0;
  

  digitalWrite(columnOne,LOW);
  digitalWrite(columnTwo,LOW);
  digitalWrite(columnThree,HIGH);
  if(analogRead(0)>512) return 3;
  if(analogRead(1)>512) return 6;
  if(analogRead(2)>512) return 9;
  if(analogRead(3)>512) return 11;
  
  return 12;
}
String gatherAllTags()
{
  String myReturnString="";
  for(int i=10; i<310; i++)
  {
    if(i%10<4 && i%10>-1)
    {
      char getChar=EEPROM.read(i);
      if(getChar==0 || getChar==255);
      else myReturnString+=(char)EEPROM.read(i);
    }
  }
  return myReturnString;
}

String getMasterCard()
{
  String returnString="";
  for(int i=2;i<6;i++)
  {
    returnString+=(char)EEPROM.read(i);
  }
  return returnString;
}

String getPassword(int startLocation)
{
  String gPassword="";
  for(int i=startLocation;i<startLocation+4;i++)
  {
    char charHolder=EEPROM.read(i);
    gPassword+=charHolder;
  }
  return gPassword;
}

void changePassword(int startLocation,String password)
{
  int counter=0;
  for(int i=startLocation;i<startLocation+4;i++)
  {
    EEPROM.write(i,password.charAt(counter));
    counter++;
    delay(10);
  }
}

