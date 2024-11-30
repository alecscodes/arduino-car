#include "navigation.h"
#include "motors.h"
#include "config.h"
#include <Arduino.h>

Navigation::Navigation(IMotor &motor, const RobotConfig &config)
    : m_motor(motor), m_config(config), m_currentState(RobotState::MOVING_FORWARD) {}

void Navigation::navigate(const SensorData &sensors)
{
    switch (m_currentState)
    {
    case RobotState::MOVING_FORWARD:
        if (sensors.frontDistance < m_config.SAFE_DISTANCE)
        {
            m_currentState = RobotState::AVOIDING_FRONT;
        }
        else if (sensors.leftBlocked || sensors.rightBlocked)
        {
            m_currentState = RobotState::AVOIDING_SIDES;
        }
        else
        {
            m_motor.moveForward(m_config.NORMAL_SPEED);
        }
        break;

    case RobotState::AVOIDING_FRONT:
    case RobotState::AVOIDING_SIDES:
        performAvoidanceManeuver(sensors);
        m_currentState = RobotState::MOVING_FORWARD;
        break;
    }
}

void Navigation::performAvoidanceManeuver(const SensorData &sensors)
{
    m_motor.moveBackward(m_config.NORMAL_SPEED);
    delay(m_config.BACKUP_TIME);

    if (sensors.leftBlocked && sensors.rightBlocked)
    {
        m_motor.moveBackward(m_config.NORMAL_SPEED);
        delay(m_config.TURN_TIME);
    }
    else if (sensors.leftBlocked)
    {
        m_motor.turnLeft(m_config.TURN_SPEED);
        delay(m_config.TURN_TIME);
    }
    else if (sensors.rightBlocked)
    {
        m_motor.turnRight(m_config.TURN_SPEED);
        delay(m_config.TURN_TIME);
    }
}
