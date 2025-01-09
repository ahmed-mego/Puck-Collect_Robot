# Puck-Collect Robot 🚀

![Robot Image](https://via.placeholder.com/800x400.png?text=Robot+Image)

Welcome to the **Puck-Collect Robot** repository! This project was developed as part of the **International Robot Challenge**, where our team, **Assiut Team**, won **first place**! 🏆

This repository contains the code, design, and documentation for our autonomous puck-collecting robot. The robot is designed to navigate an arena, identify and collect pucks, and score points efficiently. It combines hardware design, sensor integration, and intelligent algorithms to achieve its goals.

---

## Table of Contents
1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Technologies Used](#technologies-used)
4. [Hardware Design](#hardware-design)
5. [Software Architecture](#software-architecture)
6. [Installation](#installation)
7. [Usage](#usage)
8. [Team](#team)
9. [License](#license)

---

## Project Overview
The **Puck-Collect Robot** is an autonomous robot designed to compete in puck-collecting challenges. The robot uses a combination of sensors, microcontrollers, and custom algorithms to:
- Navigate the arena using **mapping and localization**.
- Detect and identify pucks using **computer vision**.
- Collect pucks and deposit them in the target zone.
- Avoid obstacles and optimize its path for maximum efficiency.

This project was developed as part of the **International Robot Challenge**, where it demonstrated exceptional performance, leading our team to **first place**!

---

## Features
- **Autonomous Navigation:** The robot uses **ROS2 Jazzy** for mapping and localization, with data from **encoders** and sensors.
- **Puck Detection:** Utilizes **computer vision** (e.g., OpenCV) to detect and identify pucks.
- **Efficient Collection:** Implements mechanisms to collect and store pucks.
- **Obstacle Avoidance:** Avoids obstacles dynamically while navigating.
- **Real-Time Decision Making:** Uses algorithms to make decisions in real-time for optimal performance.
- **UART Communication:** Enables seamless communication between the **Raspberry Pi** and **STM32 microcontroller**.

---

## Technologies Used
### Hardware
- **Raspberry Pi:** For high-level processing, computer vision, and running ROS2.
- **STM32 Microcontroller:** For low-level control of motors, sensors, and actuators.
- **Sensors:** Ultrasonic, IR, IMU, and encoders for localization and navigation.
- **Actuators:** DC Motors, Servo Motors.
- **Power Supply:** LiPo Battery.
- **Chassis:** Custom-designed for stability and maneuverability.

### Software
- **Programming Languages:** Python (for Raspberry Pi), C/C++ (for STM32).
- **ROS2 Jazzy:** For mapping, localization, and high-level decision-making.
- **Computer Vision:** OpenCV for puck detection and identification.
- **Communication Protocol:** UART for data exchange between Raspberry Pi and STM32.
- **Algorithms:** PID Control, Path Planning, Object Detection.

---

## Hardware Design
The robot's hardware consists of:
- A robust chassis designed for stability and maneuverability.
- **Raspberry Pi** for high-level processing and running ROS2.
- **STM32 Microcontroller** for low-level control of motors and sensors.
- Sensor arrays for puck detection and obstacle avoidance.
- Actuators for movement and puck collection.
- **Encoders** for precise localization and odometry.

![Hardware Design](https://via.placeholder.com/800x400.png?text=Hardware+Design+Image)

---

## Software Architecture
The software is structured into modules:
1. **Raspberry Pi (High-Level Control):**
   - Runs **ROS2 Jazzy** for mapping, localization, and navigation.
   - Uses **OpenCV** for computer vision-based puck detection.
   - Communicates with the STM32 via **UART protocol**.

2. **STM32 (Low-Level Control):**
   - Controls motors, sensors, and actuators.
   - Implements PID control for smooth movement.
   - Sends sensor data (e.g., encoder readings) to the Raspberry Pi.

3. **Communication:**
   - **UART Protocol:** Enables real-time data exchange between the Raspberry Pi and STM32.
   - Data includes motor commands, sensor readings, and status updates.

4. **Mapping and Localization:**
   - Uses **ROS2 Jazzy** with data from encoders and sensors to create a map of the arena and localize the robot.

5. **Puck Detection and Collection:**
   - **Computer Vision:** Identifies pucks using OpenCV.
   - **Control Algorithms:** Executes actions to collect and deposit pucks.
   - 
---
