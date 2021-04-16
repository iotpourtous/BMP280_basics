#ifndef commandManager_h
#define commandManager_h

#include "bmp280Def.h"


String commands(String command)
{
  if(command.substring(0,2).equals("<" + String(BMP280_SENSOR_ID))){
    return bmp->writeCommand(command.substring(2));
  } else if(command.substring(0,2).equals(">" + String(BMP280_SENSOR_ID))){
    return bmp->readCommand(command.substring(2), BMP280_SENSOR_ID);
  }
  return "Commande inexistante";
}

void commandsFromSerial()
{
    if(Serial.available()){
      String command = Serial.readStringUntil('\n');
      Serial.println(commands(command));
    }
}
void commandsFromBT()
{
  if (SerialBT.available() > 0)
  {
      String command = SerialBT.readStringUntil('\n');
      SerialBT.println(commands(command));
  }
}

#endif