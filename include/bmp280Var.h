#ifndef bmp280Var_h
#define bmp280Var_h
 
#include <MyBMP280.h>
#include "bmp280Def.h"
#include "BluetoothSerial.h"

MyBMP280 bmp(BMP280_ADDR, BMP280_SENSOR_ID);

BluetoothSerial SerialBT;

#endif