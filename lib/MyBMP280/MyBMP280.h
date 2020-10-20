#ifndef myBMP280_h
#define myBMP280_h

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

class MyBMP280
{
private:
    Adafruit_BMP280 *adafruit_BMP280;

    sensor_t sensor;
    sensors_event_t event;

    float getPressureFromSensor();

public:
    MyBMP280();
    bool begin(uint8_t addr = BMP280_ADDRESS, uint8_t chipid = BMP280_CHIPID);
    float getPressure();
    int getPressureRounded();
};

extern MyBMP280 myBMP280;

#endif
