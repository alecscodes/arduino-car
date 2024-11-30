#pragma once
#include "sensors.h"

enum RobotState
{
    MOVING_FORWARD,
    AVOIDING_FRONT,
    AVOIDING_SIDES
};

class Navigation
{
public:
    static void navigate(const SensorData &sensors);

private:
    static void performAvoidanceManeuver(const SensorData &sensors);
    static RobotState currentState;
};