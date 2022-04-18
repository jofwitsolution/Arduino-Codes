#define button1  2644 
#define button2  1696
#define button3  2224
#define button4  352
#define button5  328
#define button6  348
#define button7  888
#define button8  744
#define button9  860
#define buttonAst  1756
#define button0  1276
#define buttonHashtag  1660 
#define buttonA  1984
#define buttonB  336
#define buttonC  796
#define buttonD  1440
void setup() {
  Serial.begin(9600);
}

void loop() {
  char keypressed = getKeyPressed ();
  Serial.println(keypressed);
  delay(100);
}
char getKeyPressed (){
  int sensorValue = analogRead(A0);
  float voltage = sensorValue*(5000/1023);
  char buttonPressed;
  int toll = 0.005;
    if (voltage>0) {

    if (voltage<=button1*(1+toll) && voltage>=button1*(1-toll)){
      buttonPressed = '1';
      }
      else if (voltage<=button2*(1+toll) && voltage>=button2*(1-toll)){
      buttonPressed = '2';
      }
      else if (voltage<=button3*(1+toll) && voltage>=button3*(1-toll)){
      buttonPressed = '3';
      }
      else if (voltage<=button4*(1+toll) && voltage>=button4*(1-toll)){
      buttonPressed = '4';
      }
      else if (voltage<=button5*(1+toll) && voltage>=button5*(1-toll)){
      buttonPressed = '5';
      }
      else if (voltage<=button6*(1+toll) && voltage>=button6*(1-toll)){
      buttonPressed = '6';
      }
      else if (voltage<=button7*(1+toll) && voltage>=button7*(1-toll)){
      buttonPressed = '7';
      }
      else if (voltage<=button8*(1+toll) && voltage>=button8*(1-toll)){
      buttonPressed = '8';
      }
      else if (voltage<=button9*(1+toll) && voltage>=button9*(1-toll)){
      buttonPressed = '9';
      }
      else if (voltage<=button0*(1+toll) && voltage>=button0*(1-toll)){
      buttonPressed = '0';
      }
      else if (voltage<=buttonAst*(1+toll) && voltage>=buttonAst*(1-toll)){
      buttonPressed = '*';
      }
      else if (voltage<=buttonHashtag*(1+toll) && voltage>=buttonHashtag*(1-toll)){
      buttonPressed = '#';
      }
      else if (voltage<=buttonA*(1+toll) && voltage>=buttonA*(1-toll)){
      buttonPressed = 'A';
      }
      else if (voltage<=buttonB*(1+toll) && voltage>=buttonB*(1-toll)){
      buttonPressed = 'B';
      }
      else if (voltage<=buttonC*(1+toll) && voltage>=buttonC*(1-toll)){
      buttonPressed = 'C';
      }
      else if (voltage<=buttonD*(1+toll) && voltage>=buttonD*(1-toll)){
      buttonPressed = 'D';
    }
    return buttonPressed;
  }
}
