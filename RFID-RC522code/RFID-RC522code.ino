#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above
#define redLed          0
#define greenLed        1
#define buzzerPin       2

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
String read_rfid;
String ok_rfid_1 = "257d542b";
String ok_rfid_2 = "82f4c73";

LiquidCrystal lcd(8, 7, 6, 5, 4, 3);

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  lcd.begin (16,2); //Initialize the LCD
  lcd.setCursor(2,0);
  lcd.print("WELCOME TO");
  lcd.setCursor(3,1);
  lcd.print("COMPUTER");
  delay(5000);
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  
  pinMode (buzzerPin, OUTPUT);
  pinMode (redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}
// helper routine to dump a byte array as hex values to serial.

void dmp_byte_array(byte *buffer, byte bufferSize) {
  read_rfid = "";
  for (byte i = 0; i < bufferSize; i++) {
    read_rfid = read_rfid + String(buffer[i], HEX);
  }
}

void open_lock() {
  digitalWrite(greenLed, HIGH);
  delay(2000);
  digitalWrite(greenLed, LOW);
}

void close_lock() {
  digitalWrite(redLed, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(2000);
  digitalWrite(redLed, LOW);
   digitalWrite(buzzerPin, LOW);
}

void loop() {

  //look for new cards
  if (! mfrc522.PICC_IsNewCardPresent())
    return;

  //select one of the cards
  if (! mfrc522.PICC_ReadCardSerial())
    return;

  dmp_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println(read_rfid);
  if (read_rfid == ok_rfid_1) {
    //ok, open the door.
    Serial.println(ok_rfid_1);
    Serial.println("Access granted");
    lcd.clear();
    lcd.print("Access granted");
    open_lock();
  }
//   if (read_rfid == ok_rfid_2) {
//    //also ok
//    Serial.println("Access granted");
//    open_lock();
//
//  }
  else {
    Serial.println("Access denied");
    lcd.clear();
    lcd.print("Access denied");
    close_lock();
  }
}
