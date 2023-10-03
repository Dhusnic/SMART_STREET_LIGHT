# Smart Street Light Project with ESP32, Arduino, and Advanced Sensors

![Smart Street Light](images/street_light.jpg)

Welcome to the Smart Street Light project, designed to address Problem ID 1300 in the Smart Automation and Hardware vertical of the Smart Indian Hackathon. This ambitious endeavor combines the power of ESP32 and Arduino with state-of-the-art sensors, including LDR, PIR, and ultrasonic sensors, to revolutionize public lighting by dynamically adjusting light intensity based on environmental factors and human presence.

## Table of Contents
- [Introduction](#introduction)
- [Project Overview](#project-overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Monitoring and Control](#monitoring-and-control)
- [Contributing](#contributing)
- [License](#license)

## Introduction

India's urban landscapes are continuously evolving, and with that comes the need for smarter, more energy-efficient public lighting systems. Our Smart Street Light project tackles this challenge head-on, offering an innovative solution that significantly reduces energy consumption while enhancing safety and convenience.

## Project Overview

### The ESP32 and Arduino Duo
The project's core is built upon the ESP32 microcontroller, known for its versatility and connectivity options, and the Arduino Uno, providing a stable and familiar programming environment. This combination ensures seamless integration with our sensors and facilitates real-time data processing.

### Sensing Brightness and Darkness
We employ Light Dependent Resistor (LDR) sensors to gauge ambient light levels continually. When daylight diminishes, the system automatically activates the street light, ensuring the road is well-lit during the night. As dawn approaches, the system gently dims the light or turns it off, conserving energy during daylight hours.

### Motion Detection for Enhanced Safety
To make public spaces safer, our system incorporates Passive Infrared (PIR) sensors. When motion is detected within the vicinity, the street light illuminates at full intensity. This feature not only enhances safety but also aids in reducing unnecessary energy expenditure during idle times.

### Precise Distance Measurement
Ultrasonic sensors are employed to measure the distance of approaching objects or vehicles. Based on this data, the system adjusts the light intensity accordingly. As an object or vehicle gets closer, the street light brightens up, ensuring optimal illumination when needed.

### Energy-Efficiency and Sustainability
Our Smart Street Light system prioritizes energy efficiency. By intelligently adjusting light intensity based on ambient light, motion, and distance, it significantly reduces energy consumption. This not only saves costs but also contributes to environmental sustainability.

## Features

- **Automatic Light Control:** The system seamlessly switches the street light on and off based on the ambient light level, ensuring efficient energy use.

- **Motion-Activated Lighting:** PIR sensors detect motion, instantly brightening the street light when needed, thus improving safety.

- **Distance-Dependent Illumination:** Ultrasonic sensors ensure the street light adapts its brightness according to the proximity of objects or vehicles.

- **Energy Conservation:** Our project significantly reduces energy consumption, making it an eco-friendly and cost-effective solution.

- **Remote Monitoring and Control:** You can remotely monitor and control the street lights through a user-friendly web interface, providing real-time insights and control.

## Hardware Requirements

To replicate this project, you will need the following hardware components:

- ESP32 Development Board
- Arduino Uno
- LDR Sensor
- PIR Sensor
- Ultrasonic Sensor
- Relay Module
- LED Bulbs
- Jumper Wires
- Power Supply
- Internet Connectivity (Wi-Fi or Ethernet)

## Circuit Diagram

![Circuit Diagram](images/circuit_diagram.png)

For detailed wiring instructions and connections, please refer to our [Circuit Diagram](docs/circuit_diagram.md) document.

## Installation

Setting up the Smart Street Light project is straightforward. We provide detailed instructions in our [Installation Guide](docs/installation.md), which will walk you through the process step by step.

## Usage

Once the project is installed and configured, you can start using it immediately. The user-friendly web interface allows you to monitor and control the street lights remotely. For instructions on usage, please refer to our [User Guide](docs/user_guide.md).

## Monitoring and Control

With our system, you have the power to monitor and control street lights from anywhere with an internet connection. The web interface provides real-time data and control options, allowing you to make immediate adjustments for optimal performance and energy savings.

## Contributing

We invite contributions from the open-source community to help enhance and expand the capabilities of the Smart Street Light project. Please read our [Contribution Guidelines](CONTRIBUTING.md) to get started.

## License

This project is open-source and licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute this project to create smarter, more efficient public lighting solutions.

Thank you for your interest in our Smart Street Light project. We hope it serves as a beacon of inspiration for more sustainable and intelligent urban development in India and beyond. If you have any questions or feedback, please don't hesitate to reach out. Together, we can illuminate the path to a brighter future.
