#include "MyBMP280.h"

//bool MyBMP280::begin(uint8_t addr, uint8_t chipid, float pressureOffset)
//{
//  _pressureOffset = pressureOffset;
//  return Adafruit_BMP280::begin(addr, chipid);
//}

bool MyBMP280::begin(uint8_t addr, float pressureOffset)
{
  _pressureOffset = pressureOffset;
  return Adafruit_BMP280::begin(addr);
}

float MyBMP280::pressure()
{
  sensors_event_t event;
  Adafruit_BMP280::getPressureSensor()->getEvent(&event);
  return event.pressure + _pressureOffset;
}

int MyBMP280::pressureRounded()
{
  return (int)round(pressure());
}