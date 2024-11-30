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
  - `sensors.h`: Sensor system class
  - `navigation.h`: Navigation class

## Building and Uploading

This project uses PlatformIO for development. To build and upload:

1. Install PlatformIO IDE extension in VSCode
2. Open the project in VSCode
3. Connect your Arduino Uno
4. Click the "Upload" button or use `pio run -t upload`

## Configuration

You can adjust the robot's behavior by modifying the constants in `include/config.h`:

- `SAFE_DISTANCE`: Minimum distance before obstacle avoidance (cm)
- `NORMAL_SPEED`: Default movement speed
- `TURN_SPEED`: Speed during turns
- `BACKUP_TIME`: Duration of backup maneuver
- `TURN_TIME`: Duration of turn maneuver
- `SENSOR_DELAY`: Delay between sensor readings

## License

This project is open source and available under the MIT License.
