#include <Arduino.h>
#include "config.h"
#include "sensors.h"
#include "motors.h"
#include "navigation.h"

Motors motors(PinConfig::A_1B, PinConfig::A_1A, PinConfig::B_1B, PinConfig::B_1A);
SensorSystem sensors(PinConfig::ECHO_PIN, PinConfig::TRIG_PIN,
                     PinConfig::LEFT_IR, PinConfig::RIGHT_IR);
RobotConfig robotConfig;
Navigation navigation(motors, robotConfig);

void setup()
{
  Serial.begin(9600);
  motors.init();
  sensors.init();
}

void loop()
{
  SensorData sensorData = sensors.read();
  navigation.navigate(sensorData);
  delay(RobotConfig::SENSOR_DELAY);
}
