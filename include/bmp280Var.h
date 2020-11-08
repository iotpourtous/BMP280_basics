#ifndef bmp280Var_h
#define bmp280Var_h

#include "bmp280Def.h"
#include "BluetoothSerial.h"
#include <MyBMP280.h>

int pressureOffset = 0;

MyBMP280 bmp;

BluetoothSerial SerialBT;

#endif