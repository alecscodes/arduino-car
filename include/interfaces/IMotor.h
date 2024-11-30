#pragma once

#include <stdint.h>

class IMotor
{
public:
    virtual ~IMotor() = default;
    virtual void init() = 0;
    virtual void moveForward(int speed) = 0;
    virtual void moveBackward(int speed) = 0;
    virtual void turnLeft(int speed) = 0;
    virtual void turnRight(int speed) = 0;
    virtual void stop() = 0;
};