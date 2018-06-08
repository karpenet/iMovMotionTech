/*
 * wirelessInterfaceESP8266.cpp
 *
 *  Created on: 01-Jun-2018
 *      Author: karpenet
 */

#include "WirelessInterfaceESP8266.h"

WirelessInterfaceESP8266::WirelessInterfaceESP8266() {
	_portOutgoing = 5000;

}

WirelessInterfaceESP8266::~WirelessInterfaceESP8266() {

}

void WirelessInterfaceESP8266::initialiaze(){

	wifiLED(OFF);

	WiFi.mode(WIFI_STA);

	Serial.print("Connecting to WiFi SSID: "); Serial.println(wifiConfig::wifiSSID);
	Serial.print("Connecting using PW: "); Serial.println(wifiConfig::wifiPasskey);

	WiFi.begin(wifiConfig::wifiSSID,wifiConfig::wifiPasskey);

	while(WiFi.status() != WL_CONNECTED){
		delay(1000);
		wifiLED(BLINKY);
		Serial.println("Connecting..");
	}

	wifiLED(ON);

	WiFi.setAutoConnect(true);
	WiFi.setAutoReconnect(true);

}
bool WirelessInterfaceESP8266::isConnected(){
	if(WiFi.status() == WL_CONNECTED) 	return true;
	else 								return false;
}

void WirelessInterfaceESP8266::sendMessage(String data){
	sendUDPPacket(data);
}

void WirelessInterfaceESP8266::sendUDPPacket(String msg){
	// TODO
	/*Write packet structure here*/
}

void WirelessInterfaceESP8266::wifiLED(uint8_t mode){
	if(mode == 0)		digitalWrite(_wifiLEDpin,LOW);
	else if(mode == 1) 	digitalWrite(_wifiLEDpin,HIGH);
	else if(mode == 2){
		digitalWrite(_wifiLEDpin,HIGH);
		delay(50);
		digitalWrite(_wifiLEDpin,LOW);
		delay(100);
	}

}
