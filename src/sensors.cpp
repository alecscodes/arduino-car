
#include "sensors.h"
#include "config.h"
#include <Arduino.h>

void SensorSystem::init()
{
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(LEFT_IR, INPUT);
    pinMode(RIGHT_IR, INPUT);
}

float SensorSystem::readUltrasonic()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    return pulseIn(ECHO_PIN, HIGH) / 58.00;
}

SensorData SensorSystem::read()
{
    SensorData data;
    data.frontDistance = readUltrasonic();
    data.leftBlocked = !digitalRead(LEFT_IR);
    data.rightBlocked = !digitalRead(RIGHT_IR);
    return data;
}