/*
 * wirelessInterfaceESP8266.h
 *
 *  Created on: 01-Jun-2018
 *      Author: karpenet
 */

#ifndef WIRELESSINTERFACEESP8266_H_
#define WIRELESSINTERFACEESP8266_H_

#include <ESP8266WiFi.h>
#include <WiFiUDP.h>
#include "Arduino.h"

#include "../iMov_configAbstraction/wifiConfig.h"

#define OFF 	0
#define ON 		1
#define BLINKY 	3


class WirelessInterfaceESP8266 {
public:
	WirelessInterfaceESP8266();
	~WirelessInterfaceESP8266();

public:
	void initialiaze();
	bool isConnected();

	void sendMessage(String data);
	void sendUDPPacket(String msg);
	void wifiLED(uint8_t mode);



private:
	uint16_t _portOutgoing;
	uint8_t _wifiLEDpin;




};

#endif /* WIRELESSINTERFACEESP8266_H_ */
