#include "motors.h"
#include "config.h"
#include <Arduino.h>

Motors::Motors(uint8_t a1b, uint8_t a1a, uint8_t b1b, uint8_t b1a)
    : m_a1b(a1b), m_a1a(a1a), m_b1b(b1b), m_b1a(b1a) {}

void Motors::init()
{
    pinMode(m_a1b, OUTPUT);
    pinMode(m_a1a, OUTPUT);
    pinMode(m_b1b, OUTPUT);
    pinMode(m_b1a, OUTPUT);
}

void Motors::moveForward(int speed)
{
    analogWrite(m_a1b, 0);
    analogWrite(m_a1a, speed);
    analogWrite(m_b1b, speed);
    analogWrite(m_b1a, 0);
}

void Motors::moveBackward(int speed)
{
    analogWrite(m_a1b, speed);
    analogWrite(m_a1a, 0);
    analogWrite(m_b1b, 0);
    analogWrite(m_b1a, speed);
}

void Motors::turnLeft(int speed)
{
    analogWrite(m_a1b, 0);
    analogWrite(m_a1a, 0);
    analogWrite(m_b1b, speed);
    analogWrite(m_b1a, 0);
}

void Motors::turnRight(int speed)
{
    analogWrite(m_a1b, 0);
    analogWrite(m_a1a, speed);
    analogWrite(m_b1b, 0);
    analogWrite(m_b1a, 0);
}

void Motors::stop()
{
    analogWrite(m_a1b, 0);
    analogWrite(m_a1a, 0);
    analogWrite(m_b1b, 0);
    analogWrite(m_b1a, 0);
}