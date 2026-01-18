const int redPin = 7;
const int greenPin = 6;
const int bluePin = 5;

const int btn1Pin = 12;
const int btn2Pin = 11;
const int btn3Pin = 10;


int btn1LastState = HIGH;
int btn2LastState = HIGH;
int btn3LastState = HIGH;


bool redState = false;
bool greenState = false;
bool blueState = false;

void setup() {
  Serial.begin(9600);
  delay(2000);  

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(btn1Pin, INPUT_PULLUP);
  pinMode(btn2Pin, INPUT_PULLUP);
  pinMode(btn3Pin, INPUT_PULLUP);
}

void loop() {
 
  int btn1State = digitalRead(btn1Pin);
  int btn2State = digitalRead(btn2Pin);
  int btn3State = digitalRead(btn3Pin);

  if (btn1LastState == HIGH && btn1State == LOW) Serial.println("R");
  if (btn2LastState == HIGH && btn2State == LOW) Serial.println("G");
  if (btn3LastState == HIGH && btn3State == LOW) Serial.println("B");

  btn1LastState = btn1State;
  btn2LastState = btn2State;
  btn3LastState = btn3State;

  
  while (Serial.available() > 0) {
    char c = Serial.read();  // Read one byte
    if (c == '1') {
      redState = !redState;
      digitalWrite(redPin, redState);
    } 
    else if (c == '2') {
      greenState = !greenState;
      digitalWrite(greenPin, greenState);
    } 
    else if (c == '3') {
      blueState = !blueState;
      digitalWrite(bluePin, blueState);
    }
   
  }
}
