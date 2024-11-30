#pragma once

// Pin configurations
const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;
const int ECHO_PIN = 4;
const int TRIG_PIN = 3;
const int RIGHT_IR = 7;
const int LEFT_IR = 8;

// Robot behavior configuration
const int SAFE_DISTANCE = 12; // cm
const int NORMAL_SPEED = 200; // PWM value
const int TURN_SPEED = 150;   // PWM value
const int BACKUP_TIME = 1000; // ms
const int TURN_TIME = 700;    // ms
const int ADJUST_TIME = 200;  // ms
const int SENSOR_DELAY = 50;  // ms