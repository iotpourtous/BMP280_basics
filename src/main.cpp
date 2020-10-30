#include <Arduino.h>
#include <MyBMP280.h>

#include "bmp280Var.h"
#include "commandManager.h"

void setup()
{
  Serial.begin(115200);

  if (!bmp.begin(BMP280_ADDR))
  {
    cerr << "Le capteur BMP280 est introuvable. Vérifier votre câblage" << endl;
    while (1)
      ;
  }
}

void loop()
{
  try
  {
    commands();
    cout << "currentPressure : " << bmp.pressure() << "hPa" << endl;
    cout << "currentPressureRounded : " << bmp.pressureRounded() << "hPa" << endl;
  }
  catch (const char *msg)
  {
    cerr << "Une erreur est survenue : " << msg << endl;
  }
  delay(2000);
}