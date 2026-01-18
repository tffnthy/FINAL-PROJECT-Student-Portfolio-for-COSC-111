#define PHOTO_PIN A2
#define ALERT_PIN 8

const int LIGHT_THRESHOLD_PERCENT = 21;

bool shouldBlink = false;
bool stopBlink = false;

void setup() {
  pinMode(ALERT_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int brightnessRaw = analogRead(PHOTO_PIN);
  int brightnessPercent = map(brightnessRaw, 0, 1023, 0, 100);

  Serial.print("Brightness: ");
  Serial.print(brightnessRaw);
  Serial.print(" (");
  Serial.print(brightnessPercent);
  Serial.println("%)");

  if (brightnessPercent >= LIGHT_THRESHOLD_PERCENT) {
    shouldBlink = true; 
  }

  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.toLowerCase();
    if (input == "stop") {
      shouldBlink = false;
      digitalWrite(ALERT_PIN, LOW);
    }
  }

  if (shouldBlink) {
    digitalWrite(ALERT_PIN, HIGH);
    delay(100);
    digitalWrite(ALERT_PIN, LOW);
    delay(100);
  } else {
    digitalWrite(ALERT_PIN, LOW);
    delay(200);
  }
}

