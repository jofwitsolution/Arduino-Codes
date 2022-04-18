void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
 int BrightnessLevel= analogRead(0);
 
  Serial.print(" BrightnessLevel = ");
  Serial.println(BrightnessLevel);
  if (BrightnessLevel >=600 ) {digitalWrite(13, HIGH);
    delay(1000);}
   
    else{ digitalWrite(13, LOW);
    delay(1000);}
  
 
  
}
