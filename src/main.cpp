#include <Arduino.h>
#include <MyBMP280.h>

#include "stationMeteoDef.h"

MyBMP280 myBMP280;

void setup()
{
  Serial.begin(115200);
  Serial.println(F("BMP280 test"));

  if (!myBMP280.begin(BMP280_ADDR))
  {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1)
      ;
  }
}

void loop()
{

  int currentPressure2 = myBMP280.pressureRounded();
  if (isnan(currentPressure2))
  {
    Serial.println(F("Error reading Pressure!"));
  }
  else
  {
    Serial.print("Pressure = ");
    Serial.print(currentPressure2);
    Serial.println(" hPa");
  }



  float currentPressure4 = myBMP280.pressure();
  if (isnan(currentPressure4))
  {
    Serial.println(F("Error reading Pressure!"));
  }
  else
  {
    Serial.print("Pressure = ");
    Serial.print(currentPressure4);
    Serial.println(" hPa");
  }

  delay(2000);
}