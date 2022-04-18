#include "SPI.h"
#include "DMD.h"
#include "TimerOne.h"
#include "Arial_black_16.h"
/* you can remove the fonts if unused */
#include "SystemFont5x7.h"
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1
DMD dmd( DISPLAYS_ACROSS , DISPLAYS_DOWN );

void ScanDMD(){
dmd.scanDisplayBySPI();
}

void setup(){
  Timer1.initialize( 5000 );
  Timer1.attachInterrupt( ScanDMD );
  dmd.clearScreen( true );
}
  String textToScroll="SHELTER";
  

void drawText( String dispString ){
  dmd.clearScreen( true );
  //dmd.selectFont( SystemFont5x7 );
  dmd.selectFont( Arial_Black_16 );
  char newString[256];
  int sLength = dispString.length();
  dispString.toCharArray( newString, sLength+1 );
  dmd.drawMarquee( newString , sLength , ( 32*DISPLAYS_ACROSS )-1 ,0);
  long start=millis();
  long timer=start;
  long timer2=start;
  boolean ret=false;
  while( !ret ){
  if ( ( timer+100 ) < millis() ) {
  ret=dmd.stepMarquee( -1 , 0 );
  timer=millis();
    }
  }
}
void loop(){
 drawText(textToScroll);
}
