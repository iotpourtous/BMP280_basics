#include "MyBMP280.h"

float MyBMP280::_pressureFromEvent()
{
  sensors_event_t event;
  Adafruit_BMP280::getPressureSensor()->getEvent(&event);
  return event.pressure;
}

float MyBMP280::pressure()
{
  return _pressureFromEvent() + _pressureOffset;
}

String MyBMP280::writeCommand(char *readData)
{
  String retour = "Commande inexistante";
  switch (readData[0])
  {
  case 'O':
    char subbuff[6];
    memcpy(subbuff, &readData[1], 6);
    pressureOffset(atof(subbuff));
    return retour = "O:" + String(pressureOffset()) + "hPa";
    break;
  }
  return retour;
}

String MyBMP280::readCommand(char *readData, int8_t sensorId)
{
  String retour = "Commande inexistante";
  switch (readData[0])
  {
  case 'C':
    retour = "------------------------------------\n";
    retour += "Liste des commandes\n";
    retour += "'>" + String(sensorId) + "C' : Liste des commandes\n";
    retour += "'>" + String(sensorId) + "P' : Lit la pression\n";
    retour += "'>" + String(sensorId) + "O' : Lit l'offset de pression\n";
    retour += "'>" + String(sensorId) + "I' : Lit les infos du capteur de pression\n";
    retour += "'<" + String(sensorId) + "OXX.XX' : modifie l'offset de pression\n";
    retour += "------------------------------------";
    break;
  case 'P':
    if (isnan(pressure()))
    {
      retour = "P:lecture de la pression impossible";
    }
    else
    {
      retour = "P:" + String((int)round(pressure())) + "hPa";
    }
    break;
  case 'O':
    retour = "O:" + String(pressureOffset()) + "hPa";
    break;
  case 'I':
    sensor_t sensor;
    Adafruit_BMP280::getPressureSensor()->getSensor(&sensor);
    retour += "------------------------------------\n";
    retour + "capteur de pression Sensor\n";
    retour += "Nom: " + String(sensor.name) + "\n";
    retour += "Version:  " + String(sensor.version) + "\n";
    retour += "Identifiant:   " + String(sensor.sensor_id) + "\n";
    retour += "Delay minimun:   " + String(sensor.min_delay / 1000) + "Ms\n";
    retour += "Valeur Max:   " + String(sensor.max_value) + "hPa\n";
    retour += "Valeur Min:   " + String(sensor.min_value) + "hPa\n";
    retour += "Resolution:  " + String(sensor.resolution) + "hPa\n";
    retour += "------------------------------------";
    break;
  }
  return retour;
}