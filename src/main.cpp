#include <Arduino.h>

#include "bmp280Var.h"
#include "commandManager.h"

void setup()
{
  Serial.begin(SERIAL_BAUD);
  bmp.begin();
}

void loop()
{
  commandsFromSerial();
  commandsFromBT();
  Serial.println("currentPressure : " + String(bmp.pressure()) + "hPa");
  delay(2000);
}