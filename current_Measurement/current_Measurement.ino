/*
Measuring AC Current Using ACS712
*/
const int sensorIn = A1;
int mVperAmp = 66; // use 185 for 5A Module, 100 for 20A Module and 66 for 30A Module


double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;



void setup(){ 
 Serial.begin(9600);
}

void loop(){
 
 
 VRMS = analogRead(sensorIn);
 Serial.println(VRMS);
 float Vrms = ((VRMS-510)*5)/1023;
AmpsRMS = (Vrms * 1000)/mVperAmp;
 Serial.print(AmpsRMS);
 Serial.println(" Amps RMS");
delay(500);
}


