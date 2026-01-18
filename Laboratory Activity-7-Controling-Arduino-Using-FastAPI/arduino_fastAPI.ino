// Pin definitions
const int RED = 7;
const int GREEN = 6;
const int BLUE = 5;

// Button pins
const int BTN1 = 12;
const int BTN2 = 11;
const int BTN3 = 10;

// LED states
bool r = false, g = false, b = false;

void setup() {
  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
}

void loop() {
  // ----- BUTTON CONTROL (TOGGLE) -----
  if (digitalRead(BTN1) == LOW) { r = !r; digitalWrite(RED, r); delay(300); }
  if (digitalRead(BTN2) == LOW) { g = !g; digitalWrite(GREEN, g); delay(300); }
  if (digitalRead(BTN3) == LOW) { b = !b; digitalWrite(BLUE, b); delay(300); }

  // ----- SERIAL CONTROL (LINE-BY-LINE) -----
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim(); // remove whitespace

    // Reject multi-character input
    if (input.length() != 1) {
      Serial.println("Invalid input: Only 1 character allowed");
      return;
    }

    char c = input.charAt(0);

    // ----- Toggle LEDs for Serial Monitor -----
    if (c == '1') { r = !r; digitalWrite(RED, r); Serial.println("Red toggled"); }
    else if (c == '2') { g = !g; digitalWrite(GREEN, g); Serial.println("Green toggled"); }
    else if (c == '3') { b = !b; digitalWrite(BLUE, b); Serial.println("Blue toggled"); }

    // ----- FastAPI LED ON -----
    else if (c == 'R') { r = true; digitalWrite(RED, HIGH); }
    else if (c == 'G') { g = true; digitalWrite(GREEN, HIGH); }
    else if (c == 'B') { b = true; digitalWrite(BLUE, HIGH); }

    // ----- FastAPI LED OFF -----
    else if (c == 'r') { r = false; digitalWrite(RED, LOW); }
    else if (c == 'g') { g = false; digitalWrite(GREEN, LOW); }
    else if (c == 'b') { b = false; digitalWrite(BLUE, LOW); }

    else { Serial.print("Invalid input: "); Serial.println(c); }
  }
}
