#include <Arduino.h>

#include "bmp280Var.h"
#include "commandManager.h"

void setup()
{
  Serial.begin(SERIAL_BAUD);

  if (!bmp->begin())
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
  Serial.println("currentPressure : " + String(bmp->pressure()) + "hPa");
  delay(2000);
}