# 🚦 Automatic Traffic Detection System

A smart traffic light controller using Arduino and ultrasonic sensors — designed to improve traffic flow by reacting in real-time to vehicle presence.

---

## 📸 Project Snapshots

<table>
  <tr>
    <td><img src="https://media.licdn.com/dms/image/v2/D4D22AQFOr5BwSDtgow/feedshare-shrink_2048_1536/B4DZYxSDuaHIAo-/0/1744583543516?e=1756339200&v=beta&t=WUm22zqG59NdhK0iCurHVN1yx-sRE-CqczHZhy0iT7w" width="100%"/></td>
    <td><img src="https://media.licdn.com/dms/image/v2/D4D22AQHydzE1dfYjsA/feedshare-shrink_2048_1536/B4DZYxSDueGwAs-/0/1744583545451?e=1756339200&v=beta&t=N55O1U5ZbXInoY_rOpayY-sMfkw68c0TfnJno4DLE0Y" width="100%"/></td>
  </tr>
  <tr>
    <td><img src="https://media.licdn.com/dms/image/v2/D4D22AQEEE1gXdC4K_A/feedshare-shrink_2048_1536/B4DZYxSDukHIAo-/0/1744583545417?e=1756339200&v=beta&t=zDrprw6GUsQuIVmVA1HhHy8o2IhsTO_Z2BV-UmRk7eY" width="100%"/></td>
    <td><img src="https://media.licdn.com/dms/image/v2/D4D22AQFNAvjJAFv_zg/feedshare-shrink_2048_1536/B4DZYxSDuHGwAo-/0/1744583544051?e=1756339200&v=beta&t=VV0SOfrb2fQjhowo4zo4pswj3kaWFuJUuhynvM5SkaY" width="100%"/></td>
  </tr>
</table>

---

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

> This project serves as a foundation for building smarter traffic systems that respond to real-world conditions in real-time.
