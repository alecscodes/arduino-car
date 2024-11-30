#include "sensors.h"
#include <Arduino.h>

SensorSystem::SensorSystem(uint8_t echoPin, uint8_t trigPin, uint8_t leftIR, uint8_t rightIR)
    : m_echoPin(echoPin), m_trigPin(trigPin), m_leftIR(leftIR), m_rightIR(rightIR) {}

void SensorSystem::init()
{
    pinMode(m_echoPin, INPUT);
    pinMode(m_trigPin, OUTPUT);
    pinMode(m_leftIR, INPUT);
    pinMode(m_rightIR, INPUT);
}

float SensorSystem::readUltrasonic()
{
    digitalWrite(m_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(m_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_trigPin, LOW);
    return pulseIn(m_echoPin, HIGH) / 58.00;
}

SensorData SensorSystem::read()
{
    SensorData data;
    data.frontDistance = readUltrasonic();
    data.leftBlocked = !digitalRead(m_leftIR);
    data.rightBlocked = !digitalRead(m_rightIR);
    return data;
}