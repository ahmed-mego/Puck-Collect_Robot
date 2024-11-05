Puck Collecting Robot - International Robot Challenge

This repository contains the code and design details for our Puck Collecting Robot, which we entered in the International Robot Challenge. The goal of this robot is to autonomously navigate the competition field, locate pucks, collect them, and deposit them in designated areas as quickly and accurately as possible.
Overview

Our puck-collecting robot is designed to autonomously gather pucks scattered across a playing field. This project combines robust mechanical design, efficient path-planning algorithms, and precise sensor-based navigation to optimize the robot's performance in the competition.
Features

    Autonomous Navigation: Uses a combination of SLAM (Simultaneous Localization and Mapping) and obstacle detection to navigate the field without human intervention.
    Puck Detection and Collection: Employs computer vision to identify pucks and a custom-designed mechanism to securely pick them up.
    Efficient Path Planning: Uses algorithms to find the shortest path to pucks and avoid obstacles, minimizing time on the field.
    Strategic Puck Placement: Deposits collected pucks in specific zones to score points while avoiding interference with other robots.

Technical Specifications

    Hardware:
        Chassis: Lightweight and compact, optimized for speed and maneuverability.
        Motors: Precision-controlled motors to allow for smooth, accurate movements.
        Collection Mechanism: A gripping system that securely holds pucks during transport.
        Sensors:
            LIDAR for mapping and obstacle avoidance.
            Camera for puck detection and positioning.
            IMU (Inertial Measurement Unit) for stability and orientation.

    Software:
        Programming Language: Python (OpenCV for image processing, ROS2 for communication and control).
        Navigation: SLAM for mapping and localization, path-planning algorithms for efficient movement.
        Computer Vision: OpenCV for real-time puck detection and classification.
        Controller: Custom ROS2 nodes for sensor fusion, motor control, and task management.

Getting Started

To run the code, follow these steps:

    Install ROS2: Ensure that ROS2 is installed on your system. Our robot is compatible with ROS2 Foxy Fitzroy.
    Install Dependencies:

    bash

sudo apt update
sudo apt install python3-opencv ros-foxy-cv-bridge

Clone the Repository:

bash

git clone https://github.com/yourusername/puck-collect-robot.git
cd puck-collect-robot

Build the Package:

bash

colcon build
source install/setup.bash

Run the Robot: Start the main launch file to initiate all systems:

bash

    ros2 launch puck_collect_robot main_launch.py

Competition Strategy

Our robot is designed to maximize points through an optimized sequence of puck collection and deposit locations. It prioritizes pucks closest to its starting position and avoids heavily contested areas to reduce the risk of collisions with other robots.
Future Enhancements

Post-competition, we plan to:

    Refine Path Planning: Enhance algorithms for quicker puck retrieval.
    Improve Vision System: Increase accuracy in puck detection, even in variable lighting.
    Optimize Collection Mechanism: Develop an even faster, more reliable puck grip and release system.

Acknowledgments

Thank you to the International Robot Challenge organizers for hosting an exciting and challenging competition. Special thanks to our team and supporters who helped bring this project to life!
