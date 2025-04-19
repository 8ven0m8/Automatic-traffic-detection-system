# 🚦 Automatic Traffic Detection System

A smart traffic light controller using Arduino and ultrasonic sensors — designed to improve traffic flow by reacting in real-time to vehicle presence.

## 📌 Project Overview

This system manages two-lane traffic using HC-SR04 ultrasonic sensors connected to Arduino boards. It detects the distance of approaching vehicles and dynamically adjusts signal timing to prioritize the busier lane. The goal is to reduce idle wait times and optimize intersection efficiency without relying on fixed timers.

## 🔧 Key Features

- **Proximity-Based Signal Control**  
  Each lane is equipped with an ultrasonic sensor. The system determines which lane has a vehicle closer and grants it the green light.

- **Adaptive Green Light Duration**  
  - Vehicle ≤ 5 cm: green for **15 seconds**  
  - Vehicle ≤ 12 cm: green for **5 seconds**  
  - No nearby vehicles (> 100 cm): no green light is triggered

- **Smooth Signal Transitions**  
  Includes a 2-second yellow phase before switching signals, ensuring safe transitions.

- **Energy Efficiency**  
  Lights remain off if no vehicles are detected, minimizing unnecessary operation.

- **Modular & Scalable Code**  
  Easily extendable for more lanes, sensors, or future enhancements like wireless control or cloud-based data.

## 🛠️ Hardware Requirements

- 2 × Arduino Uno (or compatible boards)  
- 4 × HC-SR04 Ultrasonic Sensors  
- 4 × LEDs (Red, Yellow, Green per lane)  
- Breadboard, jumper wires, 220Ω resistors  
- Optional: Power supply, casing for deployment

## 🧪 Applications

- Traffic simulation and demos  
- Educational projects (IoT, Embedded Systems, Automation)  
- Prototyping for smart city infrastructure  
- Foundation for data-driven or AI-integrated traffic control systems

---

This project provides a simple yet effective starting point for building intelligent, sensor-based traffic systems with room for future development and innovation.
