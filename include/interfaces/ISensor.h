#pragma once

#include <stdint.h>

struct SensorData
{
    float frontDistance;
    bool leftBlocked;
    bool rightBlocked;
};

class ISensor
{
public:
    virtual ~ISensor() = default;
    virtual void init() = 0;
    virtual SensorData read() = 0;
};