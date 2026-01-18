# **Laboratory Activity #6**

## **Bidirectional Control Using Arduino and Python**

### **Course**

**COSC 111 – Internet of Things**

---

## **Objective**

This laboratory activity aims to demonstrate **bidirectional serial communication** between an Arduino microcontroller and a Python application. It highlights how **hardware-based inputs** (push buttons) and **software-based inputs** (keyboard commands) can both be used to control physical outputs such as LEDs.

---

## **Description**

In this activity, an Arduino board is connected to the following components:

* Three LEDs (Red, Green, Blue)
* Three push buttons

Communication between the Arduino and a Python program is achieved through **Serial communication**, allowing data to flow in **both directions**.

* **Arduino → Python:**
  When a button is pressed, the Arduino transmits a corresponding character (`R`, `G`, or `B`) to the Python application.

* **Python → Arduino:**
  Upon receiving the signal, Python sends a command (`1`, `2`, or `3`) back to the Arduino to toggle the associated LED.

In addition to automatic responses, the user can also manually control the LEDs by entering commands through the Python console.

This setup demonstrates practical IoT principles such as **event-driven processing**, **human–computer interaction**, and **combined hardware–software control systems**.

---

## **Activity Overview**

The system is composed of two primary components:

### **Arduino Side**

* Reads push button states using digital input pins
* Sends button press events through Serial communication
* Listens for incoming commands from the Python program
* Toggles LEDs based on received Serial commands

### **Python Side**

* Continuously monitors Arduino messages using a background thread
* Automatically responds to button-triggered events
* Accepts user keyboard input
* Sends control commands to the Arduino via Serial communication

---

## **Components Required**

* Arduino Uno (or compatible board)
* Three (3) LEDs: Red, Green, and Blue
* Three (3) 220Ω resistors
* Three (3) push buttons
* Breadboard
* Jumper wires
* Computer with Python installed
* USB cable

---

## **Pin Configuration**

### **LEDs**

| LED Color | Arduino Pin |
| --------- | ----------- |
| Red       | 7           |
| Green     | 6           |
| Blue      | 5           |

### **Buttons**

| Button   | Arduino Pin |
| -------- | ----------- |
| Button 1 | 12          |
| Button 2 | 11          |
| Button 3 | 10          |

The buttons use **INPUT_PULLUP** configuration, where:

* **HIGH** indicates the button is not pressed
* **LOW** indicates the button is pressed

---
