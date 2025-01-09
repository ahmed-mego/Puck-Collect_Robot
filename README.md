# Puck-Collect Robot 🚀

![Robot Image](https://github.com/ahmed-mego/Puck-Collect_Robot/blob/main/img.jpg)

Welcome to the **Puck-Collect Robot** repository! This project was developed for the **International Robot Challenge**, where our team, **Assiut Team**, won **first place**! 🏆

This repository contains the code, design, and documentation for an autonomous robot designed to navigate an arena, identify and collect pucks, and score points efficiently. The robot combines hardware design, sensor integration, and intelligent algorithms to achieve its goals.

---

## Table of Contents
1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Technologies Used](#technologies-used)
4. [Hardware Design](#hardware-design)
5. [Software Architecture](#software-architecture)
6. [Team](#team)
7. [License](#license)

---

## Project Overview
The **Puck-Collect Robot** is an autonomous robot designed for puck-collecting challenges. It uses a combination of sensors, microcontrollers, and custom algorithms to:
- Navigate the arena using **mapping and localization**.
- Detect and identify pucks using **computer vision**.
- Collect pucks and deposit them in the target zone.
- Avoid obstacles and optimize its path for maximum efficiency.

This project was developed for the **International Robot Challenge**, where it demonstrated exceptional performance, leading our team to **first place**!

---

## Features
- **Autonomous Navigation:** Uses **ROS2 Jazzy** for mapping and localization, with data from **encoders** and sensors.
- **Puck Detection:** Leverages **computer vision** (OpenCV) to detect and identify pucks.
- **Efficient Collection:** Implements mechanisms to collect and store pucks.
- **Obstacle Avoidance:** Dynamically avoids obstacles while navigating.
- **Real-Time Decision Making:** Executes algorithms for optimal performance.
- **UART Communication:** Enables seamless communication between the **Raspberry Pi** and **STM32 microcontroller**.

---

## Technologies Used
### Hardware
- **Raspberry Pi:** Handles high-level processing, computer vision, and ROS2.
- **STM32 Microcontroller:** Manages low-level control of motors, sensors, and actuators.
- **Sensors:** Ultrasonic, IR, IMU, and encoders for localization and navigation.
- **Actuators:** DC Motors, Servo Motors.
- **Power Supply:** LiPo Battery.
- **Chassis:** Custom-designed for stability and maneuverability.

### Software
- **Programming Languages:** Python (Raspberry Pi), C/C++ (STM32).
- **ROS2 Jazzy:** For mapping, localization, and high-level decision-making.
- **Computer Vision:** OpenCV for puck detection and identification.
- **Communication Protocol:** UART for data exchange between Raspberry Pi and STM32.
- **Algorithms:** PID Control, Path Planning, Object Detection.

---

## Hardware Design
The robot's hardware includes:
- A robust chassis for stability and maneuverability.
- **Raspberry Pi** for high-level processing and ROS2.
- **STM32 Microcontroller** for low-level motor and sensor control.
- Sensor arrays for puck detection and obstacle avoidance.
- Actuators for movement and puck collection.
- **Encoders** for precise localization and odometry.

![Hardware Design](https://github.com/ahmed-mego/Puck-Collect_Robot/blob/main/img2.JPG)

---

## Software Architecture
The software is divided into modules:
1. **Raspberry Pi (High-Level Control):**
   - Runs **ROS2 Jazzy** for mapping, localization, and navigation.
   - Uses **OpenCV** for computer vision-based puck detection.
   - Communicates with the STM32 via **UART protocol**.

2. **STM32 (Low-Level Control):**
   - Controls motors, sensors, and actuators.
   - Implements PID control for smooth movement.
   - Sends sensor data (e.g., encoder readings) to the Raspberry Pi.

3. **Communication:**
   - **UART Protocol:** Facilitates real-time data exchange between Raspberry Pi and STM32.
   - Data includes motor commands, sensor readings, and status updates.

4. **Mapping and Localization:**
   - Uses **ROS2 Jazzy** with encoder and sensor data to create a map of the arena and localize the robot.

5. **Puck Detection and Collection:**
   - **Computer Vision:** Identifies pucks using OpenCV.
   - **Control Algorithms:** Executes actions to collect and deposit pucks.

---

## Team
This project was developed by **Assiut Team** for the **International Robot Challenge**. Our team members are:
- **Ahmed Mego** - Embedded Systems & Control Algorithms
- **[Team Member 2]** - Hardware Design & Mechanical Assembly
- **[Team Member 3]** - Sensor Integration & Testing
- **[Team Member 4]** - Path Planning & Navigation

---

## License
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments
- Special thanks to our mentors and the organizers of the **International Robot Challenge** for their support and guidance.
- Inspired by the challenges of autonomous robotics and the desire to innovate.

---

Feel free to explore the repository, contribute, or use the code for your own projects! If you have any questions, please open an issue or contact us.
