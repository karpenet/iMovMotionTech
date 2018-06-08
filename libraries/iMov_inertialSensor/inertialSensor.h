/*
 * inertialSensor.h
 *
 *  Created on: 01-Jun-2018
 *      Author: karpenet
 */

#ifndef INERTIALSENSOR_H_
#define INERTIALSENSOR_H_

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>


class inertialSensor {
public:
	inertialSensor();
	~inertialSensor();

public:
	/*Initiliazation for IMU*/
	void initialize();

	/*Setter functions*/
	void setConfig(uint8_t configAddr, uint8_t configVal );

	void setSampleRate(uint16_t sRate);	/*Sample rate in milliseconds*/



	/*Getter functions*/
	imu::Vector<3> 	getGyroRaw();
	imu::Vector<3> 	getAccelRaw();
	imu::Vector<3> 	getEuler();
	imu::Quaternion getQuaternion();

private:
	Adafruit_BNO055 _imu;
	uint16_t 		_sampleRate;

};

#endif /* INERTIALSENSOR_H_ */
