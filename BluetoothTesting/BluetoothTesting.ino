char c = '0';
 
void setup() 
{
    // communication with the host computer
    Serial.begin(9600);  
 
    Serial.println("Do not power the BT module");
 
    // communication with the BT module on serial1
    Serial1.begin(9600);
 
 
 
    Serial.println(" ");
    Serial.println("HC-05 started at 9600");
    Serial.println("Remember to to set Both NL & CR in the serial monitor.");
    Serial.println("Do not enter AT mode");
    Serial.println(""); 
}
 
 
void loop() 
{
    // listen for communication from the BT module and then write it to the serial monitor
    if ( Serial1.available() )   
    {  
         c = Serial1.read();
         Serial.write( c ); 
    }
 
 
    // listen for user input and send it to the HC-05
   if ( Serial.available() )   
   { 
         c = Serial.read();
         Serial1.write( c ); 
   }
 
 
}
