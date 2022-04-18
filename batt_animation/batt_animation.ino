

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// make some custom characters:
byte heart[8] = {
  0b00000,// b means writing in binary
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte battEMPTY[8] = {
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b00000
};

byte battFULL[8] = {
  0b00000,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000
};

byte battHALF[8] = {
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b00000
};

byte battTHRID[8] = {
  0b00000,
  0b01110,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000
};

void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(0, heart);
  // create a new character
  lcd.createChar(1, battEMPTY);
  // create a new character
  lcd.createChar(2, battFULL);
  // create a new character
  lcd.createChar(3, battHALF);
  // create a new character
  lcd.createChar(4, battTHRID);

  // set the cursor to the top left
  lcd.setCursor(0, 0);

  // Print a message to the lcd.
  lcd.print("Hi ");
  lcd.write(byte(0)); // when calling lcd.write() '0' must be cast as a byte
  lcd.print(" ELECTRONICS ");
  //lcd.write((byte)1);
}

void loop() {
  // set the cursor to the bottom row, 5th position:
  lcd.setCursor(0, 1);
  // draw battery empty:
  lcd.write(1);
  delay(500);
  lcd.setCursor(0, 1);
  // draw battery half:
  lcd.write(3);
  delay(500);
  lcd.setCursor(0, 1);
  // draw battery third:
  lcd.write(4);
  delay(500);
  lcd.setCursor(0, 1);
  // draw battery full:
  lcd.write(2);
  delay(500);
}
