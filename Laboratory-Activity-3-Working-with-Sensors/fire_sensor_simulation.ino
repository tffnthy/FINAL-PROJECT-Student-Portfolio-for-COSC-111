  // Define PINS
  #define thermistor_Pin A0
  #define photo_Pin A2
  #define alert_Pin 12

  // Thresholds
  const float temp_Threshold = 50.0; // Celsius
  const int light_Threshold = 220;   // Brightness

  const int beta = 3950;
  const int resistance = 10; // 10k ohm fixed resistor

  void setup() {
  pinMode(alert_Pin, OUTPUT);
  Serial.begin(9600);
  }

  void loop() {
  float temperature = readTemperature();
  int brightness = readBrightness();

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C | Brightness: ");
  Serial.println(brightness);

  if (temperature >= temp_Threshold && brightness >= light_Threshold) {
  digitalWrite(alert_Pin, HIGH);
  delay(100);
  digitalWrite(alert_Pin, LOW);
  delay(100);
  } else {
  digitalWrite(alert_Pin, LOW);
  }

  delay(500);
  }

  float readTemperature() {
  int analogValue = analogRead(thermistor_Pin);
  float tempC = beta / (log(1023.0 * resistance / analogValue - resistance) + beta / 298.0) - 273.0;
  return tempC;
  }

  int readBrightness() {
  return analogRead(photo_Pin);
  }
