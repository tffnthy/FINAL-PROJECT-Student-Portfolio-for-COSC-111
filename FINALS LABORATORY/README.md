# **FINAL LABORATORY**

## **Description**

This laboratory activity demonstrates how a **push button** connected to an Arduino can be read reliably using **software debouncing** and how a validated button press can be transmitted through **Serial communication**.

The Arduino continuously monitors the state of a button configured with **INPUT_PULLUP**. When a stable button press is detected, the program sends a predefined **group number** to the Serial Monitor. This ensures that a single button press generates only one Serial output, even if the button is held down.

This activity highlights the importance of debouncing in digital inputs and introduces event-based Serial messaging, which is commonly used in IoT and embedded systems.

---

## **Activity Overview**

The Arduino program performs the following tasks:

* Configures a push button using `INPUT_PULLUP` mode
* Continuously reads the button state from a digital pin
* Applies a software debounce delay to filter false triggers
* Detects a valid button press transition (HIGH to LOW)
* Sends a predefined group number through Serial communication
* Prevents repeated Serial output during long button presses

---

## **Components Used**

* Arduino Uno (or compatible board)
* Push button
* Breadboard
* Jumper wires
* Computer with Arduino IDE installed
* USB cable

---

## **Serial Configuration**

```cpp
Serial.begin(9600);
```
