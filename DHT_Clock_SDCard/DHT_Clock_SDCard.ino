#include <SPI.h> //for the SD card module
#include <SD.h> // for the SD card
#include <DHT.h> // for the DHT sensor
#include <RTClib.h> // for the RTC

#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

//define DHT pin
#define DHTPIN 2     // what pin we're connected to

// uncomment whatever type you're using
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);


const int chipSelect = 10; 

// Create a file to store the data
File myFile;

// RTC
RTC_DS1307 rtc;

unsigned long minutes = 600000;
unsigned long currentTime = 0;
unsigned long previousTime = 0;
int number = 1;
float temp=0;

void setup() {
  lcd.begin(16, 2);
  //initializing the DHT sensor
  dht.begin();

  //initializing Serial monitor
  Serial.begin(9600); //just for debugging purpose
  
  // setup for the RTC
    if(! rtc.begin()) {
      Serial.println("Couldn't find RTC");  
      while (1);
    }
    else {
      // following line sets the RTC to the date & time this sketch was compiled
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    if(! rtc.isrunning()) {
      Serial.println("RTC is NOT running!");
    }
    
  // setup for the SD card
  Serial.print("Initializing SD card...");

  if(!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
    
  //open file
  myFile=SD.open("DATA.txt", FILE_WRITE);

  // if the file opened ok, write to it:
  if (myFile) {
    Serial.println("File opened ok");
    // print the headings for our data
    myFile.println("Date,Time,Temperature ºC, Humidity");
  }
  myFile.close();

  logTime();
  logTemperature();
  Serial.println(number + ". written");
}

void logTime() {
  DateTime now = rtc.now();
  myFile = SD.open("DATA.txt", FILE_WRITE);
  if (myFile) {
    myFile.print(now.year(), DEC);
    myFile.print('/');
    myFile.print(now.month(), DEC);
    myFile.print('/');
    myFile.print(now.day(), DEC);
    myFile.print(',');
    myFile.print(now.hour(), DEC);
    myFile.print(':');
    myFile.print(now.minute(), DEC);
    myFile.print(':');
    myFile.print(now.second(), DEC);
    myFile.print(",");
  }
  //debugging purposes
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.println(now.day(), DEC);
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);
  myFile.close();
  delay(1000);  
}

void logTemperature() {
    temp = dht.readTemperature();
    float humi = dht.readHumidity();
   
  // Check if any reads failed and exit early (to try again).
  if  (isnan(temp) /*|| isnan(f)*/) {    
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  //debugging purposes
  Serial.print("Temperature: "); 
  Serial.print(temp);
  Serial.println(" *C");

  myFile = SD.open("DATA.txt", FILE_WRITE);
  if (myFile) {
    Serial.println("open with success");  //just for debugging purpose
    myFile.print(temp);
    myFile.print(", ");
    myFile.println(humi);
  }
  myFile.close();
}

void loop() {
  /*if (currentTime == 0) {
    logTime();
  logTemperature();
  }*/
  DateTime now = rtc.now();
  currentTime = millis();
  //minutes = now.minute();
  float humi = dht.readHumidity();
  temp = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("T=");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(9, 0);
  lcd.print("H=");
  lcd.print(humi);
  lcd.setCursor(0, 1);
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.second());
  lcd.print("   ");
  if (previousTime + minutes <= currentTime)  {
  previousTime = previousTime + minutes;
  logTime();
  logTemperature();
  number++;
  Serial.println(number + ". written");
  
}
delay(500);
}
