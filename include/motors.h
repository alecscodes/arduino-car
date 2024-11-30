#pragma once

class Motors
{
public:
    static void init();
    static void moveForward(int speed);
    static void moveBackward(int speed);
    static void turnLeft(int speed);
    static void turnRight(int speed);
    static void backLeft(int speed);
    static void backRight(int speed);
    static void stop();
};