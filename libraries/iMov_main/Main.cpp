/*
 * Main.cpp
 *
 *  Created on: 01-Jun-2018
 *      Author: karpenet
 */

#include "Main.h"
#include "Arduino.h"

/*Hardware Abstraction*/
#define wifiLED 12
#define LED 13

#define RST_IMU	14
#define INT_IMU	16

Main::Main(WirelessInterfaceESP8266* radio,
		inertialSensor* sensor){
	_radio = radio;
	_sensor = sensor;

}

Main::~Main() {
}

void Main::initialize(){

	_lastMessage = millis();

	pinMode(LED,OUTPUT);
	pinMode(wifiLED,OUTPUT);

	pinMode(RST_IMU,OUTPUT);
	pinMode(INT_IMU,INPUT);

	_radio  -> initialiaze();
	_sensor -> initialize();


}

imu::Vector<3> Main::fetchData(uint8_t mode){
	switch(mode){
		case 0: return _sensor ->getGyroRaw();
				break;

		case 1: return _sensor ->getAccelRaw();
				break;

		case 2: return _sensor ->getEuler();
				break;
		}
}

imu::Quaternion Main::fetchQuat(uint8_t mode){
	switch(mode){
		case 3: return _sensor ->getQuaternion();
				break;
		}
}

imu::Vector<3> 	Main::sendData(imu::Vector<3> message){

}

imu::Quaternion Main::sendQuat(imu::Quaternion message){

}


void Main::transmitWireless(uint8_t mode, uint8_t gyroResolution, uint8_t gyroBandwidth, uint8_t accelResolution, uint8_t accelBandwidth){
	_sensor ->setConfig(Adafruit_BNO055::GYRO_CONFIG_ADDR ,gyroResolution);
	_sensor ->setConfig(Adafruit_BNO055::GYRO_CONFIG_ADDR,gyroBandwidth);
	_sensor ->setConfig(Adafruit_BNO055::ACCEL_CONFIG_ADDR,accelResolution);
	_sensor ->setConfig(Adafruit_BNO055::ACCEL_CONFIG_ADDR,accelBandwidth);
	if(mode == QUATERNION_MODE){
		_quaternion = fetchQuat(mode);
		yield();
		sendQuat(_quaternion);
	}
	else if(mode == RAWGYRO_MODE || mode == RAWACCEL_MODE || EULER_MODE == 2){
		_vector = fetchData(mode);
		yield();
		sendData(_vector);
	}

}
