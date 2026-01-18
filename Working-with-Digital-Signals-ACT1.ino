int delayTime = 1000;

void setup() {
 
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // Turn ON LEDs one by one
  digitalWrite(12, HIGH);
  delay(delayTime);
  digitalWrite(11, HIGH);
  delay(delayTime);
  digitalWrite(10, HIGH);
  delay(delayTime);
  digitalWrite(9, HIGH);
  delay(delayTime);
  digitalWrite(8, HIGH);
  delay(delayTime);

  // Turn OFF LEDs one by one
  digitalWrite(12, LOW);
  delay(delayTime);
  digitalWrite(11, LOW);
  delay(delayTime);
  digitalWrite(10, LOW);
  delay(delayTime);
  digitalWrite(9, LOW);
  delay(delayTime);
  digitalWrite(8, LOW);
  delay(delayTime);
}
