/*
 * configAbstraction.h
 *
 *  Created on: 01-Jun-2018
 *      Author: karpenet
 */

#ifndef WIFICONFIG_H_
#define WIFICONFIG_H_

#define RAWGYRO_MODE		0
#define RAWACCEL_MODE	1
#define EULER_MODE		2
#define QUATERNION_MODE	3

namespace wifiConfig {

extern const char* wifiSSID;
extern const char* wifiPasskey;
extern const char* wifiHost;

} /* namespace configAbstraction */

#endif /* WIFICONFIG_H_ */
