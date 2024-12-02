#pragma once
#include "config.h"
#include "motors.h"
#include "sensors.h"
#include "navigation.h"

class Robot
{
public:
    Robot();
    void init();
    void update();

private:
    Motors m_motors;
    SensorSystem m_sensors;
    RobotConfig m_config;
    Navigation m_navigation;
    bool m_isRunning;
    unsigned long m_lastButtonCheck;
    static constexpr unsigned long DEBOUNCE_DELAY = 200;

    void handleButton();
};