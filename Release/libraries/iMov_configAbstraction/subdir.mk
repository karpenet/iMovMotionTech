################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../libraries/iMov_configAbstraction/wifiConfig.cpp 

LINK_OBJ += \
./libraries/iMov_configAbstraction/wifiConfig.cpp.o 

CPP_DEPS += \
./libraries/iMov_configAbstraction/wifiConfig.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/iMov_configAbstraction/wifiConfig.cpp.o: /Users/karpenet/Documents/workspace/iMov/libraries/iMov_configAbstraction/wifiConfig.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/include" "-I/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/lwip/include" -c -Wall -Wextra -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -ffunction-sections -fdata-sections -DF_CPU=80000000L  -DARDUINO=10802 -DARDUINO_ESP8266_ESP12 -DARDUINO_ARCH_ESP8266 -DESP8266  -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/cores/esp8266" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/variants/espino" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/Wire" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_Unified_Sensor/1.0.2" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BNO055/1.1.3" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/libraries/Adafruit_BNO055/1.1.3/utility" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/ESP8266WiFi" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/ESP8266WiFi/src" -I"/Users/karpenet/Documents/workspace/iMov/libraries/iMov_configAbstraction" -I"/Users/karpenet/Documents/workspace/iMov/libraries/iMov_inertialSensor" -I"/Users/karpenet/Documents/workspace/iMov/libraries/iMov_main" -I"/Users/karpenet/Documents/workspace/iMov/libraries/iMov_wirelessInterface" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


