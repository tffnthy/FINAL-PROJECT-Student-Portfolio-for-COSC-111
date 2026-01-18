#include "led_control.h"

void setup() {
  Serial.begin(9600);
  setupLEDs();
  Serial.println("Serial LED Controller Ready.");
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    command = tolower(command);

    switch (command) {
      case 'r': toggleRed(); Serial.println("Toggled RED"); break;
      case 'g': toggleGreen(); Serial.println("Toggled GREEN"); break;
      case 'b': toggleBlue(); Serial.println("Toggled BLUE"); break;
      case 'a': allOn(); Serial.println("All LEDs ON"); break;
      case 'o': allOff(); Serial.println("All LEDs OFF"); break;
      case 'x': allOff(); Serial.println("All LEDs OFF"); break;
      
      

      default: Serial.println("Invalid Input!"); break;
    }
  }
}
