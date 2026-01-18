# **Laboratory Activity #7**

## **Arduino Serial Connection Using FastAPI**

### **Course**

**COSC 111 – Internet of Things**

---

## **Description**

This laboratory activity explores **Serial communication** between an Arduino microcontroller and a FastAPI-based web application. It demonstrates how digital outputs can be remotely controlled through web-based API requests.

By integrating Arduino hardware with a Python FastAPI server, the system enables LEDs to be turned **ON**, **OFF**, or **toggled** using Serial commands. This setup emphasizes the interaction between hardware and software components, reinforcing essential concepts in Internet of Things (IoT) systems.

---

## **Activity Overview**

The combined Arduino and FastAPI system performs the following operations:

* Establishes Serial communication between the Arduino and the computer
* Implements web-based control endpoints using FastAPI
* Sends single-character command instructions to the Arduino
* Controls multiple LEDs (Red, Green, and Blue)
* Demonstrates remote device control through a web API interface

---

## **Components Used**

* Arduino Uno (or compatible board)
* Red, Green, and Blue LEDs
* Resistors
* Breadboard
* Jumper wires
* Computer with Python installed
* Arduino IDE
* FastAPI framework

---

## **Serial Configuration**

```python
SERIAL_PORT = "COM3"
BAUD_RATE = 9600
```
