#include "SPI.h"
#include "DMD.h"
#include "TimerOne.h"
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#include "SystemFont3x5.h"
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1

DMD dmd( DISPLAYS_ACROSS , DISPLAYS_DOWN );
void ScanDMD()
{
dmd.scanDisplayBySPI();
}
void setup()
{
Timer1.initialize( 5000 );
Timer1.attachInterrupt( ScanDMD );
dmd.clearScreen( true );
}
String textToScroll="Welcome To Phemmyte Electronics";
void drawText( String dispString )
{
dmd.clearScreen( true );
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
if ( ( timer+60 ) < millis() ) {
ret=dmd.stepMarquee( -1 , 0 );
timer=millis();
}
}
}
void loop()
{
dmd.selectFont( SystemFont3x5 );
dmd.drawString( 0,0, "PHEMMYTE", 8, GRAPHICS_NORMAL);
dmd.drawString( 6,9, "TECH.", 4, GRAPHICS_NORMAL);
delay(6000);
dmd.clearScreen ( true );
drawText(textToScroll);
dmd.selectFont( SystemFont3x5 );
dmd.drawString( 0,0, "TEL:081-", 7, GRAPHICS_NORMAL);
dmd.drawString( 0,9, "37192766", 9, GRAPHICS_NORMAL);
delay(6000);
dmd.clearScreen ( true );
}

