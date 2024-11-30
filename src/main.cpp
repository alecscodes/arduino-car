#include <Arduino.h>
#include "config.h"
#include "sensors.h"
#include "motors.h"
#include "navigation.h"

void setup()
{
  Serial.begin(9600);
  Motors::init();
  SensorSystem::init();
}

void loop()
{
  SensorData sensors = SensorSystem::read();
  Navigation::navigate(sensors);
  delay(SENSOR_DELAY);
}
