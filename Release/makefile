################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries/iMov_wirelessInterface/subdir.mk
-include libraries/iMov_main/subdir.mk
-include libraries/iMov_inertialSensor/subdir.mk
-include libraries/iMov_configAbstraction/subdir.mk
-include libraries/Wire/subdir.mk
-include libraries/ESP8266WiFi/src/subdir.mk
-include libraries/Adafruit_BNO055/subdir.mk
-include core/core/umm_malloc/subdir.mk
-include core/core/spiffs/subdir.mk
-include core/core/libb64/subdir.mk
-include core/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/Users/karpenet/Documents/workspace/iMov/Release/arduino.ar \

ELF += \
iMov.elf \

HEX += \
iMov.hex \


# All Target
all: iMov

# Tool invocations
iMov: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-size" -A "/Users/karpenet/Documents/workspace/iMov/Release/iMov.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/Users/karpenet/Documents/workspace/iMov/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru "/Users/karpenet/Documents/workspace/iMov/Release/arduino.ar"    /Users/karpenet/Documents/workspace/iMov/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

iMov.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -g -Wall -Wextra -Os -nostdlib -Wl,--no-check-sections -u call_user_start -Wl,-static "-L/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/lib" "-L/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/ld" "-Teagle.flash.4m1m.ld" -Wl,--gc-sections -Wl,-wrap,system_restart_local -Wl,-wrap,register_chipv6_phy -o "/Users/karpenet/Documents/workspace/iMov/Release/iMov.elf" -Wl,--start-group   $(LINK_OBJ)  "/Users/karpenet/Documents/workspace/iMov/Release/arduino.ar" -lm -lgcc -lhal -lphy -lpp -lnet80211 -lwpa -lcrypto -lmain -lwps -laxtls -lsmartconfig -lmesh -lwpa2 -llwip -Wl,--end-group "-L/Users/karpenet/Documents/workspace/iMov/Release" /Users/karpenet/Documents/workspace/iMov/Release/arduino.ar
	@echo 'Finished building: $@'
	@echo ' '

iMov.hex: $(ELF)
	@echo 'Create eeprom image'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/esp8266/tools/esptool/0.4.9/esptool" -eo "/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/bootloaders/eboot/eboot.elf" -bo "/Users/karpenet/Documents/workspace/iMov/Release/iMov.bin" -bm dio -bf 40 -bz 4M -bs .text -bp 4096 -ec -eo "/Users/karpenet/Documents/workspace/iMov/Release/iMov.elf" -bs .irom0.text -bs .text -bs .data -bs .rodata -bc -ec
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
