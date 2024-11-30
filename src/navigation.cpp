#include "navigation.h"
#include "motors.h"
#include "config.h"
#include <Arduino.h>

RobotState Navigation::currentState = MOVING_FORWARD;

void Navigation::navigate(const SensorData &sensors)
{
    switch (currentState)
    {
    case MOVING_FORWARD:
        if (sensors.frontDistance < SAFE_DISTANCE)
        {
            currentState = AVOIDING_FRONT;
        }
        else if (sensors.leftBlocked || sensors.rightBlocked)
        {
            currentState = AVOIDING_SIDES;
        }
        else
        {
            Motors::moveForward(NORMAL_SPEED);
        }
        break;

    case AVOIDING_FRONT:
    case AVOIDING_SIDES:
        performAvoidanceManeuver(sensors);
        currentState = MOVING_FORWARD;
        break;
    }
}

void Navigation::performAvoidanceManeuver(const SensorData &sensors)
{
    Motors::moveBackward(NORMAL_SPEED);
    delay(BACKUP_TIME);

    if (sensors.leftBlocked && sensors.rightBlocked)
    {
        Motors::moveBackward(NORMAL_SPEED);
        delay(TURN_TIME);
    }
    else if (sensors.leftBlocked)
    {
        Motors::turnRight(TURN_SPEED);
        delay(TURN_TIME);
    }
    else if (sensors.rightBlocked)
    {
        Motors::turnLeft(TURN_SPEED);
        delay(TURN_TIME);
    }
}
