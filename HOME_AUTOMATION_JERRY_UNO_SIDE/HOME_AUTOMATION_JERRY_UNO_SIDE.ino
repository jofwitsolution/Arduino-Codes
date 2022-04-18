int relay1 = 12;
int relay2 = 11;
int relay3 = 10;
int relay4 = 9;
int relay5 = 8;

String value;
String control = "0";
String relay1On = "11";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  digitalWrite(relay5, LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    value = Serial.readString();
    int val = value.toInt();
    control = String(val);
    Serial.println(value);
    Serial.println("Received");

    if (control == "11") {
      digitalWrite(relay1, HIGH);
      Serial.println("Appliance 1 is on");  
    }
    if (control == "10") {
      digitalWrite(relay1, LOW);
      Serial.println("Appliance 1 is off");
    }

    if (control == "21") {
      digitalWrite(relay2, HIGH);
      Serial.println("Appliance 2 is on");
    }
    if (control == "20") {
      digitalWrite(relay2, LOW);
      Serial.println("Appliance 2 is off");
    }
    
    if (control == "31") {
      digitalWrite(relay3, HIGH);
      Serial.println("Appliance 3 is on");
    }
    if (control == "30") {
      digitalWrite(relay3, LOW);
      Serial.println("Appliance 3 is off");
    }

    if (control == "41") {
      digitalWrite(relay4, HIGH);
      Serial.println("Appliance 4 is on");
    }
    if (control == "40") {
      digitalWrite(relay4, LOW);
      Serial.println("Appliance 4 is off");
    }

    if (control == "51") {
      digitalWrite(relay5, HIGH);
      Serial.println("Appliance 5 is on");
    }
    if (control == "50") {
      digitalWrite(relay5, LOW);
      Serial.println("Appliance 5 is off");
    }
  }

}
