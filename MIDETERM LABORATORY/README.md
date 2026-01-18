
# MIDTERM LABORATORY

## Arduino Light Intensity Indicator with Manual and Automatic Modes

## Description

This laboratory activity demonstrates how an Arduino can be used to monitor ambient light intensity and indicate it through **Red, Yellow, and Green LEDs**. The system operates in two modes: **Automatic** (LEDs change according to light thresholds) and **Manual** (thresholds can be adjusted via Serial commands).

By integrating a **photoresistor sensor** with the Arduino, this activity teaches students how to:

* Measure analog sensor values
* Map sensor readings to percentage values
* Implement threshold-based control of multiple LEDs
* Handle Serial commands for manual control and configuration
* Display real-time system status for monitoring

This project reinforces concepts of **sensor interfacing**, **actuator control**, and **Serial communication** in IoT systems.

---

## Activity Overview

The Arduino system performs the following tasks:

* Reads light intensity from a photoresistor sensor (PHOTO_PIN)
* Maps the analog reading to a 0–100% brightness scale
* Automatically activates **Green**, **Yellow**, or **Red** LEDs based on predefined thresholds
* Allows manual adjustment of thresholds via Serial commands
* Switches between **Manual** and **Automatic** modes
* Displays system status including light intensity, active LED, mode, and environment description

---

## Components Used

* Arduino Uno (or compatible board)
* Photoresistor (Light Sensor)
* Red, Yellow, and Green LEDs
* Resistors (for LEDs and voltage divider for the sensor)
* Breadboard
* Jumper wires
* Computer with Arduino IDE installed
* USB cable for Serial communication

---

## Configuration

```cpp
#define PHOTO_PIN A0       // Analog pin for photoresistor
#define RED_LED 13         // Digital pin for Red LED
#define YELLOW_LED 12      // Digital pin for Yellow LED
#define GREEN_LED 11       // Digital pin for Green LED

// Default thresholds (percent)
int greenThreshold = 40;   // Green LED active if brightness <= 40%
int redThreshold   = 70;   // Red LED active if brightness > 70%
```

**Serial Configuration:**

```cpp
Serial.begin(9600); // 9600 baud rate for Serial communication
```

**Modes:**

* **Automatic Mode:** LEDs respond to ambient light intensity using default thresholds
* **Manual Mode:** Users can send Serial commands to adjust **LOW** (green) and **HIGH** (red) thresholds

**Example Serial Commands:**

* `MODE AUTO` → Switch to Automatic Mode
* `MODE MANUAL` → Switch to Manual Mode
* `SET LOW 35` → Set Green threshold to 35% (Manual mode only)
* `SET HIGH 80` → Set Red threshold to 80% (Manual mode only)

---

