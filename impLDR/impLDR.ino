int LDROutput = A0;
int lED1 = 13;
int lED2 = 12;
int LED3 = 11;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  }

void loop() {
  int value = analogRead(LDROutput);
  Serial.println(value);

  if(value>=300)
  { digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
  }
  else{ digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
}
}
