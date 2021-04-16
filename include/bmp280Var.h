#ifndef bmp280Var_h
#define bmp280Var_h
 
#include <MyBMP280.h>
#include "bmp280Def.h"
#include "BluetoothSerial.h"

int pressureOffset = 0;

MyBMP280 *bmp = new MyBMP280(BMP280_ADDR);

BluetoothSerial SerialBT;

#endif