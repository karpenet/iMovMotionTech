#include "Arduino.h"

#include "Main.h"
#include "inertialSensor.h"
#include "wifiConfig.h"
#include "WirelessInterfaceESP8266.h"


WirelessInterfaceESP8266 wifi;
inertialSensor inertialUnit;

Main node(&wifi, &inertialUnit);


void setup()
{
	Serial.begin(9600);
	Serial.println("iMov Motiontech");
	node.initialize();
}


void loop()
{
	yield();


	/*Available Modes*/

	/*
	 RAWGYRO_MODE 	- Gyroscope Raw Data
	 RAWACCEL_MODE 	- Accelerometer Raw Data
	 EULER_MODE		- Euler Angles
	 QUATERNION_MODE- Quaternions
	*/

	node.transmitWireless(EULER_MODE);
}

