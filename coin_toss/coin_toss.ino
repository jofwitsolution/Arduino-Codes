#define HEADIOPIN 13 // Which I/O pins are we using?
#define TAILIOPIN 12
#define PAUSE 3000 // How long to delay?
#define REST 2000
int head = HEADIOPIN;
int tail = TAILIOPIN;
int tailCount = 0;
long randomNumber = 0L; // Use the "L" to tell compiler it's a long data type, not an int.
// the setup routine runs once when you press reset:
void setup() {
Serial.begin(9600);  
// initialize each of the digital pins as an output.
pinMode(head, OUTPUT);
pinMode(tail, OUTPUT);
randomSeed(analogRead(0)); // This seeds the random number generator
}
// the loop routine runs over and over again forever:
void loop() {
randomNumber = generateRandomNumber();
digitalWrite(head, LOW); // Turn both LEDs off
digitalWrite(tail, LOW);
delay(PAUSE - REST); // Let them see both are off for a time slice
if (randomNumber % 2 == 1) { // Treat odd numbers as a head
digitalWrite(head, HIGH);
} else {
digitalWrite(tail, HIGH); // Even numbers are a tail
tailCount= tailCount + 1;
}
delay(PAUSE); // Pause for 3 seconds
Serial.print("Tails = ");
Serial.print(tailCount);
//Serial.println(data);
exit(0);
}
long generateRandomNumber()
{
return random(0, 1000000); // Generate random numbers between 0 and one million
}
