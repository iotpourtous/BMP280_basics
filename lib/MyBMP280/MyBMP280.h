#ifndef myBMP280_h
#define myBMP280_h

#include <iostream>
#include <exception>

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

using namespace std;

class MyBMP280 : public Adafruit_BMP280
{
private:
    float _pressureOffset;
    float _pressureFromEvent();

public:
    MyBMP280(float pressureOffset = 0.0) : Adafruit_BMP280(&Wire),
                                           _pressureOffset(pressureOffset) {}
    float pressureOffset() { return _pressureOffset; }
    void pressureOffset(float pressureOffset) { _pressureOffset = pressureOffset; }
    float pressure();

    String readCommand(char *readData, int8_t sensorId);
    String writeCommand(char *readData);
};

extern MyBMP280 bmp;

#endif
