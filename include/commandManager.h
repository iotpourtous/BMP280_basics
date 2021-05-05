#ifndef commandManager_h
#define commandManager_h

#include "bmp280Def.h"

String commands(String command)
{
  if (command.startsWith((String)BMP280_SENSOR_ID))
  {
    return bmp.executeCommand(command.substring(1));
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