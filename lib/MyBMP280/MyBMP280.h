#ifndef myBMP280_h
#define myBMP280_h

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

class MyBMP280 : public Adafruit_BMP280
{
private:
    float _pressureOffset;

public:
    //bool begin(uint8_t addr = BMP280_ADDRESS, uint8_t chipid = BMP280_CHIPID, float pressureOffset = 0.0);
    bool begin(uint8_t addr = BMP280_ADDRESS, float pressureOffset = 0.0);
    float pressureOffset() { return _pressureOffset; }
    void pressureOffset(float pressureOffset) { _pressureOffset = pressureOffset; }
    float pressure();
    int pressureRounded();
};

extern MyBMP280 myBMP280;

#endif
