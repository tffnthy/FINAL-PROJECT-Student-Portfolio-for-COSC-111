// led_control.h
#ifndef LED_CONTROL_H
#define LED_CONTROL_H

int redPin = 8;
int greenPin = 9;
int bluePin = 10;

bool redState = false;
bool greenState = false;
bool blueState = false;

void setupLEDs() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

void toggleRed() {
  redState = !redState;
  digitalWrite(redPin, redState);
}

void toggleGreen() {
  greenState = !greenState;
  digitalWrite(greenPin, greenState);
}

void toggleBlue() {
  blueState = !blueState;
  digitalWrite(bluePin, blueState);
}

void allOn() {
  redState = greenState = blueState = true;
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
}

void allOff() {
  redState = greenState = blueState = false;
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

#endif
