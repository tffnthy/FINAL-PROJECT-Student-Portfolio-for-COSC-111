#### **Laboratory Activity #2**
**Working with Analog Signal**

**Course**
COSC 111 – Internet of Things

---

### **Description**

This laboratory activity demonstrates the control of multiple LEDs using arrays and loops to gradually adjust their brightness. The Arduino program utilizes the `analogWrite()` function to simulate analog output through PWM-capable pins.

Through this process, each LED performs the following actions:

* Gradually increases brightness (fade in)
* Gradually decreases brightness (fade out)
* Continuously repeats the fading sequence

The activity highlights how Arduino can manage output intensity, a key concept in real-world IoT applications such as light dimming, motor speed control, and power output regulation.

---

### **Activity Overview**

The Arduino sketch accomplishes the following:

* Stores LED pin numbers within an array
* Uses loops to efficiently configure and control multiple LEDs
* Applies PWM values ranging from 0 to 255
* Produces a smooth fading effect for each LED

---

### **Components Required**

* Arduino Uno (or compatible board)
* Five (5) LEDs
* Five (5) 220Ω resistors
* Breadboard
* Jumper wires
* Arduino IDE

---

### **🔌 Pin Configuration**

| LED   | Arduino Pin |
| ----- | ----------- |
| LED 1 | 12          |
| LED 2 | 11          |
| LED 3 | 10          |
| LED 4 | 9           |
| LED 5 | 8           |
