#pragma once
#include <stdint.h>
#include "interfaces/IMotor.h"

class Motors : public IMotor
{
public:
    Motors(uint8_t a1b, uint8_t a1a, uint8_t b1b, uint8_t b1a);
    void init() override;
    void moveForward(int speed) override;
    void moveBackward(int speed) override;
    void turnLeft(int speed) override;
    void turnRight(int speed) override;
    void stop() override;

private:
    const uint8_t m_a1b;
    const uint8_t m_a1a;
    const uint8_t m_b1b;
    const uint8_t m_b1a;
};