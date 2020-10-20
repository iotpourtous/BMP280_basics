#include "MyBMP280.h"

MyBMP280::MyBMP280()
{
  adafruit_BMP280 = new Adafruit_BMP280();
}

bool MyBMP280::begin(uint8_t addr, uint8_t chipid)
{
  return adafruit_BMP280->begin(addr, chipid);
}

float MyBMP280::getPressureFromSensor()
{
  adafruit_BMP280->getPressureSensor()->getEvent(&event);
  return event.pressure;
}

float MyBMP280::getPressure()
{
  return getPressureFromSensor();
}

int MyBMP280::getPressureRounded()
{
  return (int)round(getPressure());
}