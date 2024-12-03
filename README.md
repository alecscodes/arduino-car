# Arduino Self-Driving Car

A simple autonomous car project built with Arduino that can navigate and avoid obstacles using ultrasonic and IR sensors.

## Features

- Autonomous navigation
- Obstacle detection and avoidance
- Multiple sensor integration (Ultrasonic + IR sensors)
- State-based navigation system

## Hardware Requirements

- Arduino Uno
- DC Motors (x2)
- L298N Motor Driver
- Ultrasonic Sensor (HC-SR04)
- IR Sensors (x2)
- Chassis and wheels
- Power supply

## Pin Configuration

- Motor A: Pins 5 (1B), 6 (1A)
- Motor B: Pins 9 (1B), 10 (1A)
- Ultrasonic Sensor: Pins 4 (Echo), 3 (Trigger)
- IR Sensors: Pins 7 (Right), 8 (Left)

## Project Structure

- `src/`: Source files
  - `main.cpp`: Main program entry point
  - `motors.cpp`: Motor control implementation
  - `sensors.cpp`: Sensor system implementation
  - `navigation.cpp`: Navigation logic
- `include/`: Header files
  - `interfaces/`: Abstract interfaces
  - `config.h`: Pin and robot configurations
  - `motors.h`: Motor control class

## Tutorial Reference

This project is based on the tutorial from SunFounder. For detailed assembly instructions and additional information, please visit:

[SunFounder Smart Car Kit V2.0 - Assembly Guide](https://docs.sunfounder.com/projects/3in1-kit-v2/en/latest/car_project/car_assemble.html)
