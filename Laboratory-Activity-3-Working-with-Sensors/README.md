# **Laboratory Activity #3**

## **Working with Sensors**

### **Course**

**COSC 111 – Internet of Things**

---

## **Objective**

This laboratory activity aims to demonstrate how **analog sensors**, specifically temperature and light sensors, can be read and processed using an Arduino microcontroller. It also focuses on applying **conditional logic** to activate an **alert system** when sensor readings exceed predefined threshold values.

---

## **Description**

In this activity, a **thermistor** and a **photoresistor (LDR)** are used to observe environmental conditions. The Arduino continuously acquires temperature and light intensity data and outputs these readings to the Serial Monitor.

An alert device, such as an LED or buzzer connected to a digital pin, is activated when **both** the temperature and light intensity values exceed their corresponding thresholds. This setup demonstrates how multiple sensor inputs can be evaluated together to make logical decisions, a fundamental concept in Internet of Things (IoT) systems.

---

## **Activity Overview**

The Arduino program performs the following functions:

* Reads temperature data from a thermistor through an analog input pin
* Reads light intensity data from a photoresistor using an analog input pin
* Converts raw analog sensor readings into meaningful values
* Compares sensor outputs with preset threshold values
* Activates an alert output when the defined conditions are satisfied
* Displays sensor data using the Serial Monitor

---

## **Components Required**

* Arduino Uno (or compatible board)
* Thermistor (NTC, 10kΩ)
* Photoresistor (LDR)
* 10kΩ fixed resistor
* LED or buzzer (alert indicator)
* Breadboard
* Jumper wires
* Arduino IDE

---

## **Pin Configuration**

| Component          | Arduino Pin |
| ------------------ | ----------- |
| Thermistor         | A0          |
| Photoresistor      | A2          |
| Alert (LED/Buzzer) | 12          |

---

## **⚙️ Threshold Values**

```cpp
const float temp_Threshold = 50.0; // Celsius
const int light_Threshold = 220;   // Brightness
```
