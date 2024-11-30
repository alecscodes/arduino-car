#pragma once
#include <stdint.h>
#include "interfaces/ISensor.h"

class SensorSystem : public ISensor
{
public:
    SensorSystem(uint8_t echoPin, uint8_t trigPin, uint8_t leftIR, uint8_t rightIR);
    void init() override;
    SensorData read() override;

private:
    float readUltrasonic();
    const uint8_t m_echoPin;
    const uint8_t m_trigPin;
    const uint8_t m_leftIR;
    const uint8_t m_rightIR;
};