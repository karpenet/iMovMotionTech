/*
 * inertialSensor.cpp
 *
 *  Created on: 01-Jun-2018
 *      Author: karpenet
 */

#include "inertialSensor.h"

inertialSensor::inertialSensor() {
	// TODO Auto-generated constructor stub

}

inertialSensor::~inertialSensor() {
	// TODO Auto-generated destructor stub
}

void inertialSensor::initialize(){

	if(!_imu.begin())
	  {
	    Serial.println("IMU not detected. Check I2C address.");
	    while(1);
	  }

	delay(1000);

	_imu.setExtCrystalUse(true);
}

void inertialSensor::setSampleRate(uint16_t sRate){
	_sampleRate = sRate;
}


void inertialSensor::setConfig(uint8_t configAddr, uint8_t configVal){
	/*Flag current mode*/
	Adafruit_BNO055::adafruit_bno055_opmode_t modeback;

	/*Change to Config mode*/
	_imu.setMode(_imu.OPERATION_MODE_CONFIG);
	delay(25);

	/*Change to Page 1 of register map*/
	_imu.write8(_imu.BNO055_PAGE_ID_ADDR, 1);

	/*Write new resolution value*/
	uint8_t configReg = _imu.read8(Adafruit_BNO055::GYRO_CONFIG_ADDR);
	configReg |= configVal;
	_imu.write8(Adafruit_BNO055::GYRO_CONFIG_ADDR, configReg);

	/*Change back to Page 0 of register map*/
	_imu.write8(_imu.BNO055_PAGE_ID_ADDR, 0);

	/*Change back to previous mode*/
	_imu.setMode(modeback);
	delay(25);
}

imu::Vector<3> inertialSensor::getGyroRaw(){
	_imu.setMode(_imu.OPERATION_MODE_GYRONLY);
	delay(50);

	return _imu.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
}

imu::Vector<3> inertialSensor::getAccelRaw(){
	_imu.setMode(_imu.OPERATION_MODE_ACCONLY);
	delay(50);

	return _imu.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
}

imu::Vector<3> inertialSensor::getEuler(){
	_imu.setMode(_imu.OPERATION_MODE_NDOF);
	delay(50);

	return _imu.getVector(Adafruit_BNO055::VECTOR_EULER);
}

imu::Quaternion inertialSensor::getQuaternion(){
	_imu.setMode(_imu.OPERATION_MODE_NDOF);
	delay(50);

	return _imu.getQuat();
}
