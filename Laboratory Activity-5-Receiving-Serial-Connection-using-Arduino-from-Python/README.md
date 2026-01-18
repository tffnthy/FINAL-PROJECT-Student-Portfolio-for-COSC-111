# **Laboratory Activity #5**

## **Receiving Serial Connection Using Arduino from Python**

### **Course**

**COSC 111 – Internet of Things**

---

## **Objective**

This laboratory activity aims to demonstrate **serial communication between a Python application and an Arduino microcontroller** for controlling multiple LEDs. It introduces key IoT concepts such as computer-to-device interaction, command-driven control, and modular programming design.

---

## **Description**

In this activity, a Python-based console application transmits commands to an Arduino through **Serial communication**. The Arduino processes these commands to control three LEDs: Red, Green, and Blue.

The Arduino implementation is organized into:

* A primary `.ino` file responsible for handling serial commands
* A separate `.h` header file dedicated to LED control logic

This modular structure enhances code readability, reusability, and long-term maintainability, which are essential practices in real-world IoT development.

---

## **Activity Overview**

The system is composed of two main components:

### **Python Program**

* Presents a menu-driven interface to the user
* Sends single-character command inputs to the Arduino
* Receives and displays feedback messages from the Arduino
* Enables interactive LED control through keyboard input

### **Arduino Program**

* Reads incoming serial commands from the Python application
* Controls individual LEDs or all LEDs simultaneously
* Sends response messages back to the Python program
* Implements modular functions for LED control

---

## **Components Required**

* Arduino Uno (or compatible board)
* Three (3) LEDs: Red, Green, and Blue
* Three (3) 220Ω resistors
* Breadboard
* Jumper wires
* Computer with Python installed
* USB cable

---

## **Pin Configuration**

| LED Color | Arduino Pin |
| --------- | ----------- |
| Red       | 8           |
| Green     | 9           |
| Blue      | 10          |

---
