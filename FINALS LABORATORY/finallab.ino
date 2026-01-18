const int BUTTONPIN = 11;
const int GROUP_NUMBER = 2;
const unsigned long debounceDelay = 50;

int lastButtonState = HIGH;
int buttonState = HIGH;
unsigned long lastDebounceTime = 0;


void setup() {
  pinMode(BUTTONPIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int reading =  digitalRead(BUTTONPIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    static int confirmedButtonState = HIGH;

    if (reading == LOW && confirmedButtonState == HIGH) {
      Serial.println(GROUP_NUMBER);
    }
    confirmedButtonState = reading;
  }
  lastButtonState = reading;
}
