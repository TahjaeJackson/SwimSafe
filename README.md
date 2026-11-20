# SwimSafe — Automated Drowning Detection & Emergency Flotation System

** Engineering Design Project | Dartmouth College — Thayer School of Engineering**

## Overview

SwimSafe is a prototype wearable safety system designed to detect potential drowning conditions and automatically deploy an emergency flotation device.

The system integrates multiple sensors, an Arduino Nano microcontroller, and an electromechanical deployment mechanism to monitor environmental and motion-related conditions and trigger flotation when predefined thresholds are exceeded.

The project combines embedded software development, sensor integration, mechanical design, and iterative hardware testing.

## Project Documentation

SwimSafe was developed as part of the senior engineering design experience at Dartmouth College's Thayer School of Engineering.

For additional information about the project's development, engineering challenges, design decisions, and prototyping process, see the project blog:

**[SwimSafe — Engineering Project Blog](https://journeys.dartmouth.edu/tahjaemjackson25/?page_id=510)**

## System Architecture

The system consists of four primary components:

1. **Sensor Monitoring:** Collects pressure and acceleration measurements to identify potential drowning conditions.
2. **Detection Logic:** Evaluates sensor readings against predefined thresholds to determine whether deployment should be triggered.
3. **Deployment Control:** Activates a relay-controlled solenoid intended to puncture a compressed CO₂ cartridge and initiate flotation.
4. **Manual Override:** Provides a button-based mechanism for manually triggering deployment.

### Hardware Components

| Component | Function |
|---|---|
| Arduino Nano | Main microcontroller and control logic |
| Barometric Pressure Sensor (HP206C) | Environmental pressure monitoring |
| Accelerometer (MMA7660) | Motion and acceleration monitoring |
| Relay Module | Controls the deployment circuit |
| 12V Solenoid | Actuates the CO₂ puncture mechanism |
| CO₂ Cartridge | Compressed gas source for flotation |
| Push Button | Manual deployment override |
| LED | System status and deployment indication |

## Software Design

The embedded software was developed using Arduino C/C++ and organized into functional modules to separate sensor acquisition, detection logic, and deployment control.

### Sensor Integration

- Implemented I²C communication with pressure and acceleration sensors.
- Developed sensor initialization and measurement routines.
- Processed sensor readings to evaluate potential drowning conditions.
- Integrated multiple sensor inputs into a centralized detection system.

### Detection and Control Logic

- Implemented threshold-based detection using pressure and acceleration measurements.
- Developed conditional logic to trigger deployment when detection criteria are satisfied.
- Integrated manual deployment functionality through a physical push button.
- Implemented a deployment state mechanism to prevent repeated activation.

### Deployment Mechanism

- Controlled a relay-driven solenoid through the Arduino.
- Implemented timed activation of the deployment mechanism.
- Integrated status indication through an LED.
- Coordinated hardware actuation with software-generated deployment signals.

## Engineering Challenges

### 1. Hardware and Software Integration

Integrating multiple sensors and electromechanical components required debugging communication protocols, electrical connections, and control logic.

We tested individual components before integrating them into the complete system, allowing us to isolate issues and refine the design incrementally.

### 2. CO₂ Cartridge Puncture Mechanism

One of the most significant engineering challenges was developing a reliable mechanism to puncture the compressed CO₂ cartridge.

Our initial design did not consistently generate sufficient force to activate the cartridge.

To address this, we:

- Investigated the mechanical limitations of the puncture mechanism.
- Tested different hardware configurations.
- Evaluated solenoid performance and power requirements.
- Iteratively refined the mechanical design based on experimental results.

This process highlighted the importance of validating mechanical and electrical constraints alongside embedded software functionality.

### 3. Sensor Reliability and Detection Logic

Developing a detection system required balancing responsiveness with the possibility of false activations.

We explored threshold-based detection using multiple sensor measurements and adjusted the control logic during testing.

## Technologies Used

- **Languages:** C/C++, Arduino
- **Microcontroller:** Arduino Nano
- **Communication:** I²C
- **Embedded Systems:** Sensor acquisition, GPIO control, relay actuation
- **Hardware:** Accelerometer, barometric pressure sensor, solenoid, relay, CO₂ cartridge
- **Development Tools:** Arduino IDE
- **Engineering Methods:** Prototyping, hardware debugging, iterative testing, system integration

## Key Takeaways

This project strengthened my experience in:

- Developing modular embedded software for microcontroller-based systems.
- Debugging interactions between physical hardware and software.
- Integrating sensors and actuators into a coordinated control system.
- Evaluating design tradeoffs involving reliability, responsiveness, and hardware constraints.
- Collaborating on an interdisciplinary engineering project.
- Iteratively improving a prototype through experimentation and testing.

## Future Improvements

Potential improvements include:

- Implementing sensor calibration and filtering to reduce measurement noise.
- Developing more sophisticated detection algorithms to distinguish normal swimming activity from potential emergencies.
- Introducing additional hardware safety mechanisms and diagnostic checks.
- Reducing the size and power consumption of the wearable system.
- Expanding automated testing and validation under controlled conditions.

## Project Status

**Academic prototype — proof of concept.**

SwimSafe was developed as a senior engineering design project. It is not a certified drowning detection or personal flotation safety device and has not been validated for real-world emergency use.

## Author

Developed as part of a senior engineering design team at Dartmouth College, Thayer School of Engineering.
