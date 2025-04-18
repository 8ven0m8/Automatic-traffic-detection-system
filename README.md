# Automatic-traffic-detection-system
Smart Traffic Light Controller using Ultrasonic Sensors (Arduino)
This project implements an intelligent traffic light system using an Arduino and ultrasonic sensors. The system manages two traffic signals based on the proximity of vehicles detected in two lanes. It is designed to optimize traffic flow by dynamically adjusting the signal timing according to real-time conditions.

Key Features
Proximity-Based Signal Control:
Each lane is equipped with an HC-SR04 ultrasonic sensor. The system compares the distance readings to determine which lane has the closer vehicle.

Adaptive Green Light Duration:
If a vehicle is very close (≤5 cm), the corresponding signal stays green for 15 seconds. If moderately close (≤12 cm), the green light lasts for 5 seconds. If both lanes are clear (distance >100 cm), no signal turns green.

Smooth Signal Transitions:
After the green period, the signal transitions to yellow for 2 seconds before switching to red. If the opposite lane still detects a vehicle, the green signal is then assigned to that side.

Prevention of Unnecessary Switching:
The system avoids activating lights when there are no vehicles nearby, reducing unnecessary signal changes and conserving energy.

Hardware Requirements
2 x Arduino Uno (or compatible board)

4 x HC-SR04 Ultrasonic Sensors

4 x LEDs traffic lights

Resistors (220Ω recommended)

Breadboard and jumper wires

Optional: Power supply and casing for deployment

Applications
This setup is suitable for basic traffic simulation, educational demonstrations, or as a prototype for smart traffic control systems. It can be extended with real-time data logging, wireless communication, or machine learning for predictive traffic management.

The code is modular and easy to adapt for intersections with more lanes or other types of sensors. It offers a practical foundation for developing more advanced traffic automation projects.
