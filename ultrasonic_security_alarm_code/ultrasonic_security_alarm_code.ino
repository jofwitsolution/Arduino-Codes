1.  /*
2.  * Arduino Security and Alarm System
3.  *
4.  * by Dejan Nedelkovski,
5.  * www.HowToMechatronics.com
6.  *
7.  */
8.  
9.  #include <LiquidCrystal.h> // includes the LiquidCrystal Library 
10. #include <Keypad.h>
11. 
12. #define buzzer 8
13. #define trigPin 9
14. #define echoPin 10
15. 
16. long duration;
17. int distance, initialDistance, currentDistance, i;
18. int screenOffMsg =0;
19. String password="1234";
20. String tempPassword;
21. boolean activated = false; // State of the alarm
22. boolean isActivated;
23. boolean activateAlarm = false;
24. boolean alarmActivated = false;
25. boolean enteredPassword; // State of the entered password to stop the alarm
26. boolean passChangeMode = false;
27. boolean passChanged = false;
28. 
29. const byte ROWS = 4; //four rows
30. const byte COLS = 4; //four columns
31. char keypressed;
32. //define the cymbols on the buttons of the keypads
33. char keyMap[ROWS][COLS] = {
34. {'1','2','3','A'},
35. {'4','5','6','B'},
36. {'7','8','9','C'},
37. {'*','0','#','D'}
38. };
39. byte rowPins[ROWS] = {14, 15, 16, 17}; //Row pinouts of the keypad
40. byte colPins[COLS] = {18, 19, 20, 21}; //Column pinouts of the keypad
41. 
42. Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, ROWS, COLS); 
43. LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
44. 
45. void setup() { 
46. lcd.begin(16,2); 
47. pinMode(buzzer, OUTPUT); // Set buzzer as an output
48. pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
49. pinMode(echoPin, INPUT); // Sets the echoPin as an Input
50. }
51. 
52. void loop() {
53. if (activateAlarm) {
54. lcd.clear();
55. lcd.setCursor(0,0);
56. lcd.print("Alarm will be");
57. lcd.setCursor(0,1);
58. lcd.print("activated in");
59. 
60. int countdown = 9; // 9 seconds count down before activating the alarm
61. while (countdown != 0) {
62. lcd.setCursor(13,1);
63. lcd.print(countdown);
64. countdown--;
65. tone(buzzer, 700, 100);
66. delay(1000);
67. }
68. lcd.clear();
69. lcd.setCursor(0,0);
70. lcd.print("Alarm Activated!");
71. initialDistance = getDistance();
72. activateAlarm = false;
73. alarmActivated = true;
74. }
75. 
76. if (alarmActivated == true){
77. currentDistance = getDistance() + 10;
78. if ( currentDistance < initialDistance) {
79. tone(buzzer, 1000); // Send 1KHz sound signal 
80. lcd.clear();
81. enterPassword();
82. }
83. }
84. 
85. if (!alarmActivated) {
86. if (screenOffMsg == 0 ){
87. lcd.clear();
88. lcd.setCursor(0,0);
89. lcd.print("A - Activate");
90. lcd.setCursor(0,1);
91. lcd.print("B - Change Pass");
92. screenOffMsg = 1;
93. }
94. keypressed = myKeypad.getKey();
95. if (keypressed =='A'){ //If A is pressed, activate the alarm
96. tone(buzzer, 1000, 200);
97. activateAlarm = true; 
98. }
99. else if (keypressed =='B') {
100.  lcd.clear();
101.  int i=1;
102.  tone(buzzer, 2000, 100);
103.  tempPassword = "";
104.  lcd.setCursor(0,0);
105.  lcd.print("Current Password");
106.  lcd.setCursor(0,1);
107.  lcd.print(">");
108.  passChangeMode = true;
109.  passChanged = true; 
110.  while(passChanged) { 
111.  keypressed = myKeypad.getKey();
112.  if (keypressed != NO_KEY){
113.  if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
114.  keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
115.  keypressed == '8' || keypressed == '9' ) {
116.  tempPassword += keypressed;
117.  lcd.setCursor(i,1);
118.  lcd.print("*");
119.  i++;
120.  tone(buzzer, 2000, 100);
121.  }
122.  }
123.  if (i > 5 || keypressed == '#') {
124.  tempPassword = "";
125.  i=1;
126.  lcd.clear();
127.  lcd.setCursor(0,0);
128.  lcd.print("Current Password");
129.  lcd.setCursor(0,1);
130.  lcd.print(">"); 
131.  }
132.  if ( keypressed == '*') {
133.  i=1;
134.  tone(buzzer, 2000, 100);
135.  if (password == tempPassword) {
136.  tempPassword="";
137.  lcd.clear();
138.  lcd.setCursor(0,0);
139.  lcd.print("Set New Password");
140.  lcd.setCursor(0,1);
141.  lcd.print(">");
142.  while(passChangeMode) {
143.  keypressed = myKeypad.getKey();
144.  if (keypressed != NO_KEY){
145.  if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
146.  keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
147.  keypressed == '8' || keypressed == '9' ) {
148.  tempPassword += keypressed;
149.  lcd.setCursor(i,1);
150.  lcd.print("*");
151.  i++;
152.  tone(buzzer, 2000, 100);
153.  }
154.  }
155.  if (i > 5 || keypressed == '#') {
156.  tempPassword = "";
157.  i=1;
158.  tone(buzzer, 2000, 100);
159.  lcd.clear();
160.  lcd.setCursor(0,0);
161.  lcd.print("Set New Password");
162.  lcd.setCursor(0,1);
163.  lcd.print(">");
164.  }
165.  if ( keypressed == '*') {
166.  i=1;
167.  tone(buzzer, 2000, 100);
168.  password = tempPassword;
169.  passChangeMode = false;
170.  passChanged = false;
171.  screenOffMsg = 0;
172.  } 
173.  }
174.  }
175.  }
176.  }
177.  }
178.  }
179.  }
180.  
181.  void enterPassword() {
182.  int k=5;
183.  tempPassword = "";
184.  activated = true;
185.  lcd.clear();
186.  lcd.setCursor(0,0);
187.  lcd.print(" *** ALARM *** ");
188.  lcd.setCursor(0,1);
189.  lcd.print("Pass>");
190.  while(activated) {
191.  keypressed = myKeypad.getKey();
192.  if (keypressed != NO_KEY){
193.  if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
194.  keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
195.  keypressed == '8' || keypressed == '9' ) {
196.  tempPassword += keypressed;
197.  lcd.setCursor(k,1);
198.  lcd.print("*");
199.  k++;
200.  }
201.  }
202.  if (k > 9 || keypressed == '#') {
203.  tempPassword = "";
204.  k=5;
205.  lcd.clear();
206.  lcd.setCursor(0,0);
207.  lcd.print(" *** ALARM *** ");
208.  lcd.setCursor(0,1);
209.  lcd.print("Pass>");
210.  }
211.  if ( keypressed == '*') {
212.  if ( tempPassword == password ) {
213.  activated = false;
214.  alarmActivated = false;
215.  noTone(buzzer);
216.  screenOffMsg = 0; 
217.  }
218.  else if (tempPassword != password) {
219.  lcd.setCursor(0,1);
220.  lcd.print("Wrong! Try Again");
221.  delay(2000);
222.  lcd.clear();
223.  lcd.setCursor(0,0);
224.  lcd.print(" *** ALARM *** ");
225.  lcd.setCursor(0,1);
226.  lcd.print("Pass>");
227.  }
228.  } 
229.  }
230.  }
231.  // Custom function for the Ultrasonic sensor
232.  long getDistance(){
233.  //int i=10;
234.  
235.  //while( i<=10 ) {
236.  // Clears the trigPin
237.  digitalWrite(trigPin, LOW);
238.  delayMicroseconds(2);
239.  
240.  // Sets the trigPin on HIGH state for 10 micro seconds
241.  digitalWrite(trigPin, HIGH);
242.  delayMicroseconds(10);
243.  digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance = duration*0.034/2;
//sumDistance += distance;
//}
//int averageDistance= sumDistance/10;
return distance;
}

