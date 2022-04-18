#include <SPI.h>
#include <Keypad.h>
#include <ShiftedLCD.h>

// initialize the library with the number of the sspin 
//(or the latch pin of the 74HC595)
LiquidCrystal lcd(10);

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
byte rowPins[ROWS] = {3,2,8,9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7,6,5,4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 
//*****************scientific buttons******************

int curx=0,cury=0;
char msg[140];
int space=7;
int spacey=10;

int waittime=500;

int times[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long timelapse=millis();
int index=0;
//*****************************************************


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Input text");
  delay(2000);
  lcd.clear();
}

void loop() {
  text();
}
void setallzero(){
  int i;
  for(i=0;i<14;i++)
    times[i]=0;
}

void text(){
  while(1){
      char c;
  
  customKey = customKeypad.getKey();
  if(customKey!=NO_KEY)
  {
    if(customKey=='=')
      break;
  switch(customKey)
  {
     case '1':
    if(times[1]==0)
      { c='@';
        msg[index]=c;
        index++;
        times[1]=1;
        timelapse=millis();
      }
    else if(times[1]==1)
    {
      index--;
      c='#';
      msg[index]=c;
      index++;
      curx-=space;
      times[1]=2;
      timelapse=millis();  
    }
    else
    {
      index--;
      c='.';
      msg[index]=c;
      index++;
      curx-=space;
      times[1]=0;
      timelapse=0;
    }
    break;


    
    case '2':
    if(times[2]==0)
      { c='a';
        msg[index]=c;
        index++;
        times[2]=1;
        timelapse=millis();
      }
    else if(times[2]==1)
    {
      index--;
      c='b';
      msg[index]=c;
      index++;
      curx-=space;
      times[2]=2;
      timelapse=millis();  
    }
    else
    {
      index--;
      c='c';
      msg[index]=c;
      index++;
      curx-=space;
      times[2]=0;
      timelapse=0;
    }
    break;

    
    case '3':
    if(times[3]==0)
      { c='d';
        msg[index]=c;
        index++;
        times[3]=1;
        timelapse=millis();
      }
    else if(times[3]==1)
    {
      index--;
      c='e';
      msg[index]=c;
      index++;
      curx-=space;
      times[3]=2;
      timelapse=millis();  
    }
    else
    {
      index--;
      c='f';
      msg[index]=c;
      index++;
      curx-=space;
      times[3]=0;
      timelapse=0;
    }
    break;

        case '4':
    if(times[4]==0)
      { c='g';
        msg[index]=c;
        index++;
        times[4]=1;
        timelapse=millis();
      }
    else if(times[4]==1)
    {
      index--;
      c='h';
      msg[index]=c;
      index++;
      curx-=space;
      times[4]=2;
      timelapse=millis();  
    }
    else
    {
      index--;
      c='i';
      msg[index]=c;
      index++;
      curx-=space;
      times[4]=0;
      timelapse=0;
    }
    break;


            case '5':
    if(times[5]==0)
      { c='j';
        msg[index]=c;
        index++;
        times[5]=1;
        timelapse=millis();
      }
    else if(times[5]==1)
    {
      index--;
      c='k';
      msg[index]=c;
      index++;
      curx-=space;
      times[5]=2;
      timelapse=millis();  
    }
    else
    {
      index--;
      c='l';
      msg[index]=c;
      index++;
      curx-=space;
      times[5]=0;
      timelapse=0;
    }
    break;


            case '6':
    if(times[6]==0)
      { c='m';
        msg[index]=c;
        index++;
        times[6]=1;
        timelapse=millis();
      }
    else if(times[6]==1)
    {
      index--;
      c='n';
      msg[index]=c;
      index++;
      curx-=space;
      times[6]=2;
      timelapse=millis();  
    }
    else
    {
      index--;
      c='o';
      msg[index]=c;
      index++;
      curx-=space;
      times[6]=0;
      timelapse=0;
    }
    break;

            case '7':
    if(times[7]==0)
      { c='p';
        msg[index]=c;
        index++;
        times[7]=1;
        timelapse=millis();
      }
    else if(times[7]==1)
    {
      index--;
      c='q';
      msg[index]=c;
      index++;
      curx-=space;
      times[7]=2;
      timelapse=millis();  
    }
    else if(times[7]==2)
    {
      index--;
      c='r';
      msg[index]=c;
      index++;
      curx-=space;
      times[7]=3;
      timelapse=millis();
    }
       else
    {
      index--;
      c='s';
      msg[index]=c;
      index++;
      curx-=space;
      times[7]=0;
      timelapse=0;
    }
    break;

            case '8':
    if(times[8]==0)
      { c='t';
        msg[index]=c;
        index++;
        times[8]=1;
        timelapse=millis();
      }
    else if(times[8]==1)
    {
      index--;
      c='u';
      msg[index]=c;
      index++;
      curx-=space;
      times[8]=2;
      timelapse=millis();  
    }
    else
    {
      index--;
      c='v';
      msg[index]=c;
      index++;
      curx-=space;
      times[8]=0;
      timelapse=0;
    }
    break;


                case '9':
    if(times[9]==0)
      { c='w';
        msg[index]=c;
        index++;
        times[9]=1;
        timelapse=millis();
      }
    else if(times[9]==1)
    {
      index--;
      c='x';
      msg[index]=c;
      index++;
      curx-=space;
      times[9]=2;
      timelapse=millis();  
    }
    else if(times[9]==2)
    {
      index--;
      c='y';
      msg[index]=c;
      index++;
      curx-=space;
      times[9]=3;
      timelapse=millis();
    }
       else
    {
      index--;
      c='z';
      msg[index]=c;
      index++;
      curx-=space;
      times[9]=0;
      timelapse=0;
    }
    break;
    case 'C':
    {
      if(curx!=0)
        curx=curx-space;
      else 
        {
          curx=133;
          int tempy=cury;
          cury-=spacey;
          
        }
      msg[index-1]='\0';
      if(index>0)
      index--;
      
      c=' ';
      //lcd.setCursor(curx,cury);
      //lcd.print(".");
    }
    break;
    case '0':
    c=' ';
    msg[index]=c;
    index++;
    curx+=space;
    break;
  }
  lcd.setCursor(curx,cury);
  if(c<='z'&&c>='a'||c==' '||c=='@'||c=='#'||c=='.')
  {  lcd.print(c);
      if(c!=' ')
      curx+=space;
  }
  Serial.println(msg);
  Serial.println(index);

  
  }
 if(millis()>timelapse+waittime)
  setallzero(); 
  if(curx>=140&&millis()>timelapse+waittime){
    curx=0;
    cury+=spacey;
  }
  }
}

