#define sensorPin 0
float celsius, voltage, fahrenheit;
int sensorValue;
void setup() {
Serial.begin(9600);
Serial.println("Initialising.....");
}
void loop() {
  int sensorValue= analogRead(sensorPin);
  voltage = ( float(sensorValue)/1024)*5;
  celsius = voltage/0.01;
Serial.print("sensorValue= ");
Serial.println(sensorValue);
Serial.print("Celsius: ");
Serial.println(celsius);
fahrenheit = (celsius * (9/5)) + 32;
Serial.print("Fahrenheit= ");
Serial.println(fahrenheit);
Serial.println();

delay(3000);
}
