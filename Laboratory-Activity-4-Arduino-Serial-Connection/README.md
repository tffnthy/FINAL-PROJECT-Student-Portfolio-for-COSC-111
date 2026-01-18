# **Laboratory Activity #4**

## **Arduino Serial Connection**

### **Course**

**COSC 111 – Internet of Things**

---

## **Objective**

This laboratory activity is designed to demonstrate how a **photoresistor (LDR)** can be used to sense light intensity, convert raw analog readings into **percentage-based values**, and control an alert output through both **sensor data** and **Serial Monitor commands**.

---

## **Description**

In this activity, ambient light levels are measured using a photoresistor connected to an Arduino analog input pin. The raw sensor data is then converted into a percentage range (0–100%), making the values more intuitive and easier to understand.

When the calculated brightness level exceeds a predefined threshold, an alert LED begins blinking. In addition to automatic triggering, the alert behavior can be manually controlled through **Serial input**, allowing direct user interaction with the system.

This setup introduces basic **human–device interaction**, which is an important concept in Internet of Things (IoT) applications.

---

## **Activity Overview**

The Arduino program performs the following tasks:

* Reads light intensity values from a photoresistor
* Converts analog sensor readings into percentage values using the `map()` function
* Displays sensor data through the Serial Monitor
* Activates a blinking alert when the brightness level exceeds the threshold
* Allows the alert to be stopped via Serial Monitor input

---

## **Components Required**

* Arduino Uno (or compatible board)
* Photoresistor (LDR)
* 10kΩ resistor
* LED (alert indicator)
* Breadboard
* Jumper wires
* Arduino IDE

---

## **Pin Configuration**

| Component     | Arduino Pin |
| ------------- | ----------- |
| Photoresistor | A2          |
| Alert LED     | 8           |

---

## **Threshold Configuration**

```cpp
const int LIGHT_THRESHOLD_PERCENT = 21;
```
