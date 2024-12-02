#pragma once
#include <stdint.h>

struct PinConfig
{
    static constexpr uint8_t A_1B = 5;
    static constexpr uint8_t A_1A = 6;
    static constexpr uint8_t B_1B = 9;
    static constexpr uint8_t B_1A = 10;
    static constexpr uint8_t ECHO_PIN = 4;
    static constexpr uint8_t TRIG_PIN = 3;
    static constexpr uint8_t RIGHT_IR = 7;
    static constexpr uint8_t LEFT_IR = 8;
    static constexpr uint8_t BUTTON = 2;
};

struct RobotConfig
{
    static constexpr int SAFE_DISTANCE = 10;
    static constexpr int NORMAL_SPEED = 200;
    static constexpr int TURN_SPEED = 150;
    static constexpr int BACKUP_TIME = 500;
    static constexpr int TURN_TIME = 700;
    static constexpr int ADJUST_TIME = 200;
    static constexpr int SENSOR_DELAY = 50;
};