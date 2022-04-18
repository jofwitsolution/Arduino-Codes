// PROJECT 23
#include <LiquidCrystal.h>
// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Create an lcd object and assign the pins

void setup() {
lcd.begin(16, 2); // Set the display to 16 columns and 2 rows
}
void loop() {
// Run the seven demo routines
basicPrintDemo();
displayOnOffDemo();
//setCursorDemo();
//scrollLeftDemo();
//scrollRightDemo();
//cursorDemo();
//createGlyphDemo();
}
void basicPrintDemo() {
lcd.clear(); // Clear the display
lcd.print("Basic Print"); // Print some text
delay(2000);
}
void displayOnOffDemo() {
lcd.clear(); // Clear the display
lcd.print("Display On/Off"); // Print some text
for(int x=0; x < 5; x++) { // Loop 3 times
lcd.noDisplay(); // Turn display off
delay(1000);
lcd.display(); // Turn it back on again
delay(1000);
}
}
void setCursorDemo() {
lcd.clear(); // Clear the display
lcd.print("SetCursor Demo"); // Print some text
delay(1000);
lcd.clear(); // Clear the display
lcd.setCursor(5,0); // Cursor at column 5 row 0
lcd.print("5,0");
delay(2000);
lcd.setCursor(10,1); // Cursor at column 10 row 1
lcd.print("10,1");
delay(2000);
lcd.setCursor(3,1); // Cursor at column 3 row 1
lcd.print("3,1");
delay(2000);
}

void scrollLeftDemo() {
lcd.clear(); // Clear the display
lcd.print("Scroll Left Demo");
delay(1000);
lcd.clear(); // Clear the display
lcd.setCursor(7,0);
lcd.print("Beginning");
lcd.setCursor(9,1);
lcd.print("Arduino");
delay(1000);
for(int x=0; x<16; x++) {
lcd.scrollDisplayLeft(); // Scroll display left 16 times
delay(250);
}
}
void scrollRightDemo() {
lcd.clear(); // Clear the display
lcd.print("Scroll Right");
lcd.setCursor(0,1);
lcd.print("Demo");
delay(1000);
lcd.clear(); // Clear the display
lcd.print("Beginning");
lcd.setCursor(0,1);
lcd.print("Arduino");
delay(1000);
for(int x=0; x<16; x++) {
lcd.scrollDisplayRight(); // Scroll display right 16 times
delay(250);
}
}
void cursorDemo() {
lcd.clear(); // Clear the display
lcd.cursor(); // Enable cursor visible
lcd.print("Cursor On");
delay(3000);
lcd.clear(); // Clear the display
lcd.noCursor(); // Cursor invisible
lcd.print("Cursor Off");
delay(3000);
lcd.clear(); // Clear the display
lcd.cursor(); // Cursor visible
lcd.blink(); // Cursor blinking
lcd.print("Cursor Blink On");
delay(3000);
lcd.noCursor(); // Cursor invisible
lcd.noBlink(); // Blink off
}
void createGlyphDemo() {
lcd.clear();
byte happy[8] = { // Create byte array with happy face
B00000,
B00000,
B10001,
B00000,
B10001,
B01110,
B00000,
B00000};
byte sad[8] = { // Create byte array with sad face
B00000,
B00000,
B10001,
B00000,
B01110,
B10001,
B00000,
B00000};
lcd.createChar(3, happy); // Create custom character 0
lcd.createChar(6, sad); // Create custom character 1
for(int x=0; x<5; x++) { // Loop animation 5 times
lcd.setCursor(8,0);
lcd.write(5); // write custom char 3
delay(1000);
lcd.setCursor(8,0);
lcd.write(1); // Write custom char 1
delay(1000);
}
}
