int buttonInput = 6;
int segment_a = 7;
int segment_b = 8;
int segment_c = 9;
int segment_d = 10;
int segment_e = 11;
int segment_f = 12;
int segment_g = 13;

int count = 0;
//common Anode is used here
void setup() {
  pinMode(buttonInput, INPUT);
  digitalWrite(buttonInput, HIGH);
  for (int x = 7; x < 14; x++) {
    pinMode(x, OUTPUT);
  }
}

void loop() {
  if (digitalRead(buttonInput) == LOW) {
    delay(300);
    if (count == 2){ 
    count = 0;
    }
    count++;
  }
  if (count == 1) {
    for (int x = 7; x < 14; x++) {
      digitalWrite(x, LOW);
      digitalWrite(segment_b, HIGH);
      digitalWrite(segment_c, HIGH);
  }
  }
  if (count == 2) {
    for (int x = 7; x < 14; x++) {
      digitalWrite(x, LOW);
      digitalWrite(segment_a, HIGH);
      digitalWrite(segment_b, HIGH);
      digitalWrite(segment_d, HIGH);
      digitalWrite(segment_e, HIGH);
      digitalWrite(segment_g, HIGH);
      
   }
  }
  if (count == 0) {
       for (int x = 7; x < 14; x++) {
      digitalWrite(x, LOW);
      digitalWrite(segment_a, HIGH);
      digitalWrite(segment_b, HIGH);
      digitalWrite(segment_d, HIGH);
      digitalWrite(segment_e, HIGH);
      digitalWrite(segment_c, HIGH);
      digitalWrite(segment_f, HIGH);
    }
  }
    if (count == 3) {
      for (int x = 7; x < 14; x++) {
      digitalWrite(x, LOW);
      digitalWrite(segment_a, HIGH);
      digitalWrite(segment_b, HIGH);
      digitalWrite(segment_c, HIGH);
      digitalWrite(segment_d, HIGH);
      digitalWrite(segment_g, HIGH);
    }
}
}
