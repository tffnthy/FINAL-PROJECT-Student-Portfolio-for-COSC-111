#define PHOTO_PIN A0
#define RED_LED 13
#define YELLOW_LED 12
#define GREEN_LED 11

String inputString = "";
bool manualMode = true; // Default: MANUAL mode
String activeLED = "NONE"; // Tracks which LED is active
int brightness = 0; // Current light intensity (0-100%)

// Adjustable thresholds
int greenThreshold = 40; // upper limit for GREEN (%)
int redThreshold   = 70; // lower limit for RED (%)
// YELLOW automatically fills the range between GREEN and RED

// Default thresholds
const int DEFAULT_GREEN = 40;
const int DEFAULT_RED = 70;

void setup() {
  Serial.begin(9600);
  pinMode(PHOTO_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  // Read photo value in both modes
  int photoValue = analogRead(PHOTO_PIN);
  brightness = map(photoValue, 0, 1023, 0, 100); // 0–100%

  // Update LEDs according to thresholds
  updateLEDs();

  // Display status
  displayStatus();

  delay(500);

  // Check Serial input
  if (Serial.available()) {
    inputString = Serial.readStringUntil('\n');
    inputString.trim();
    inputString.toUpperCase();
    handleCommand(inputString);
  }
}

// Update LEDs based on brightness and thresholds
void updateLEDs() {
  if (brightness <= greenThreshold) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    activeLED = "GREEN";
  } 
  else if (brightness <= redThreshold) { // YELLOW is in between
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    activeLED = "YELLOW";
  } 
  else {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    activeLED = "RED";
  }
}

// Handle Serial commands in manual mode
void handleCommand(String command) {
  if (command.startsWith("MODE")) {
    String modeType = command.substring(5);
    modeType.trim();

    if (modeType == "MANUAL") {
      manualMode = true;
      Serial.println("Switched to MANUAL mode.");
    } 
    else if (modeType == "AUTO") {
      manualMode = false;
      // Reset thresholds to default when switching to automatic
      greenThreshold = DEFAULT_GREEN;
      redThreshold = DEFAULT_RED;
      Serial.println("Switched to AUTOMATIC mode. Thresholds reset to default.");
    } 
    else {
      Serial.println("Wrong command!");
    }
  }
  else if (manualMode) {
    if (command.startsWith("SET")) {
      String parts = command.substring(4);
      parts.trim();
      int spaceIndex = parts.indexOf(' ');
      if (spaceIndex == -1) {
        Serial.println("Wrong command!");
        return;
      }

      String action = parts.substring(0, spaceIndex);
      String valueStr = parts.substring(spaceIndex + 1);
      action.trim();
      valueStr.trim();

      int value = valueStr.toInt();
      if (value < 0) value = 0;
      if (value > 100) value = 100;

      // Directly update thresholds
      if (action == "LOW") {
        greenThreshold = value;
        Serial.print("GREEN threshold updated to: ");
        Serial.print(greenThreshold);
        Serial.println("%");
      } 
      else if (action == "HIGH") {
        redThreshold = value;
        Serial.print("RED threshold updated to: ");
        Serial.print(redThreshold);
        Serial.println("%");
      } 
      else {
        Serial.println("Wrong command! Use LOW or HIGH.");
      }
    }
    else {
      Serial.println("Wrong command!");
    }
  }
  else {
    Serial.println("Wrong command!");
  }
}

// Display the current status
void displayStatus() {
  Serial.print("Light Intensity: ");
  Serial.print(brightness);
  Serial.print("% | Active LED: ");
  Serial.print(activeLED);
  Serial.print(" | Mode: ");
  Serial.print(manualMode ? "MANUAL" : "AUTOMATIC");

  // Only show environment in AUTOMATIC mode
  if (!manualMode) {
    String environment = "";
    if (brightness <= 40) environment = "Cloudy";
    else if (brightness <= 70) environment = "Normal";
    else environment = "Bright Sunlight";
    
    Serial.print(" | Environment: ");
    Serial.print(environment);
  }

  Serial.println();
}
