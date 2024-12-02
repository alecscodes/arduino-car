#include "robot.h"
#include <Arduino.h>

Robot::Robot()
    : m_motors(PinConfig::A_1B, PinConfig::A_1A, PinConfig::B_1B, PinConfig::B_1A),
      m_sensors(PinConfig::ECHO_PIN, PinConfig::TRIG_PIN, PinConfig::LEFT_IR, PinConfig::RIGHT_IR),
      m_navigation(m_motors, m_config),
      m_isRunning(false),
      m_lastButtonCheck(0)
{
}

void Robot::init()
{
    Serial.begin(9600);
    m_motors.init();
    m_sensors.init();
    pinMode(PinConfig::BUTTON, INPUT);
}

void Robot::handleButton()
{
    unsigned long currentTime = millis();
    if (currentTime - m_lastButtonCheck >= DEBOUNCE_DELAY && digitalRead(PinConfig::BUTTON))
    {
        m_isRunning = !m_isRunning;
        m_lastButtonCheck = currentTime;
    }
}

void Robot::update()
{
    handleButton();

    if (!m_isRunning)
    {
        m_motors.stop();
    }
    else
    {
        m_navigation.navigate(m_sensors.read());
    }

    delay(RobotConfig::SENSOR_DELAY);
}