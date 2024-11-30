#pragma once
#include "config.h"
#include "interfaces/IMotor.h"
#include "interfaces/ISensor.h"

enum class RobotState
{
    MOVING_FORWARD,
    AVOIDING_FRONT,
    AVOIDING_SIDES
};

class Navigation
{
public:
    Navigation(IMotor &motor, const RobotConfig &config);
    void navigate(const SensorData &sensors);

private:
    void performAvoidanceManeuver(const SensorData &sensors);
    IMotor &m_motor;
    const RobotConfig &m_config;
    RobotState m_currentState;
};