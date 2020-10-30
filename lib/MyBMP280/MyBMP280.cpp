#include "MyBMP280.h"

float MyBMP280::_pressureFromEvent()
{
  sensors_event_t event;
  Adafruit_BMP280::getPressureSensor()->getEvent(&event);
  float h = event.pressure;
  if (isnan(h))
  {
    throw "Erreur lecture pression";
  }
  return h;
}

float MyBMP280::pressure()
{
  return _pressureFromEvent() + _pressureOffset;
}

int MyBMP280::pressureRounded()
{
  return (int)round(pressure());
}

void MyBMP280::writeCommand(int sensorId, char *readData)
{
  switch (readData[0])
  {
  case 'O':
    char subbuff[6];
    memcpy(subbuff, &readData[1], 6);
    pressureOffset(atof(subbuff));
    cout << ">" << sensorId << "O:" << pressureOffset() << "hPa" << endl;
    break;
  default:
    throw "Commande inexistante";
    break;
  }
}

void MyBMP280::readCommand(int sensorId, char *readData)
{
  switch (readData[0])
  {
  case 'C':
    cout << "------------------------------------" << endl
         << "Liste des commandes" << endl
         << "'>" << sensorId << "C' : Liste des commandes" << endl
         << "'>" << sensorId << "P' : Lit la pression" << endl
         << "'>" << sensorId << "R' : Lit la pression arrondie" << endl
         << "'>" << sensorId << "O' : Lit l'offset de pression" << endl
         << "'>" << sensorId << "I' : Lit les infos du capteur de pression" << endl
         << "'<" << sensorId << "OXX.XX' : modifie l'offset de pression" << endl
         << "------------------------------------" << endl;
    break;
  case 'P':
    cout << ">" << sensorId << "P:" << pressure() << "hPa" << endl;
    break;
  case 'R':
    cout << ">" << sensorId << "H:" << pressureRounded() << "hPa" << endl;
    break;
  case 'O':
    cout << ">" << sensorId << "OT:" << pressureOffset() << "hPa" << endl;
    break;
  case 'I':
    sensor_t sensor;
    Adafruit_BMP280::getPressureSensor()->getSensor(&sensor);
    cout << "------------------------------------" << endl
         << "Humidity Sensor" << endl
         << "Nom: " << sensor.name << endl
         << "Version:  " << sensor.version << endl
         << "Identifiant:   " << sensor.sensor_id << endl
         << "Delay minimun:   " << sensor.min_delay / 1000 << "Ms" << endl
         << "Valeur Max:   " << sensor.max_value << "hPa" << endl
         << "Valeur Min:   " << sensor.min_value << "hPa" << endl
         << "Resolution:  " << sensor.resolution << "hPa" << endl
         << "------------------------------------" << endl;
    break;
  default:
    throw "Commande inexistante";
    break;
  }
}