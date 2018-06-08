/*
 * Main.h
 *
 *  Created on: 01-Jun-2018
 *      Author: karpenet
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "wifiConfig.h"
#include "WirelessInterfaceESP8266.h"
#include "utility/imumaths.h"
#include "inertialSensor.h"

/*Gyroscope Range*/
#define G_2000DPS	0x00
#define G_1000DPS	0x01
#define G_500DPS	0x02
#define G_250DPS	0x03
#define G_125DPS	0x04

/*Gyroscope Bandwidth*/
#define G_523HZ 	0x00
#define G_230HZ 	0x08
#define G_116HZ 	0x10
#define G_47HZ	 	0x18
#define G_23HZ	 	0x20
#define G_12HZ	 	0x28
#define G_64HZ	 	0x30
#define G_32HZ	 	0x38

/*Accelerometer Range*/
#define A_2G		0x00
#define A_4G		0x01
#define A_8G		0x02
#define A_16G		0x03

/*Accelerometer Bandwidth*/
#define	A_7_81HZ	0x00
#define	A_15_63HZ	0x08
#define	A_31_25HZ	0x10
#define	A_62_5HZ	0x18
#define	A_125HZ		0x20
#define	A_250HZ		0x28
#define	A_500HZ		0x30
#define	A_1000HZ	0x38

class Main {
public:
	Main(WirelessInterfaceESP8266* radio,
			inertialSensor* sensor);
	~Main();

public:
	void initialize();

	imu::Vector<3> fetchData(uint8_t mode);
	imu::Quaternion fetchQuat(uint8_t mode);

	imu::Vector<3> 	sendData(imu::Vector<3> message);
	imu::Quaternion sendQuat(imu::Quaternion message);


	void transmitWireless(uint8_t mode = EULER_MODE, uint8_t gyroResolution = G_2000DPS, uint8_t gyroBandwidth = G_2000DPS, uint8_t accelResolution = A_2G, uint8_t accelBandwidth = A_62_5HZ);



private:
	char* 						dummyData;
	imu::Vector<3> 				_vector;
	imu::Quaternion 			_quaternion;

	WirelessInterfaceESP8266* 	_radio;
	inertialSensor* 			_sensor;
	uint32_t 					_lastMessage;
};

#endif /* MAIN_H_ */
