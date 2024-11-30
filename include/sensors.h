#pragma once

struct SensorData
{
    float frontDistance;
    bool leftBlocked;
    bool rightBlocked;
};

class SensorSystem
{
public:
    static void init();
    static SensorData read();

private:
    static float readUltrasonic();
};