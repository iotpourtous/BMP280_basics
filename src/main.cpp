#include <Arduino.h>
#include <MyBMP280.h>

#include "bmp280Var.h"
#include "format.h"
#include "commandManager.h"

void setup()
{
  Serial.begin(SERIAL_BAUD);

  if (!bmp.begin(BMP280_ADDR))
  {
    Serial.println("Le capteur BMP280 est introuvable. Vérifier votre câblage");
    while (1)
      ; 
  }
}

void loop()
{
  commandsFromSerial();
  commandsFromBT();
  Serial.println("currentPressure : " + formatFloat(bmp.pressure()) + "hPa");
  Serial.println("currentPressure : " + String(roundedFloat(bmp.pressure())) + "hPa");
  delay(2000);
}