################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/TI/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/TI/OLED_Software_IIC" -I"D:/TI/OLED_Software_IIC/MPU6050" -I"D:/TI/OLED_Software_IIC/OLED" -I"D:/TI/OLED_Software_IIC/Debug" -I"D:/TI/mspm0_sdk_2_01_00_03/source/third_party/CMSIS/Core/Include" -I"D:/TI/mspm0_sdk_2_01_00_03/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-2098127233: ../oled.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/TI/sysconfig_cli.bat" --script "D:/TI/OLED_Software_IIC/oled.syscfg" -o "." -s "D:/TI/mspm0_sdk_2_01_00_03/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-2098127233 ../oled.syscfg
device.opt: build-2098127233
device.cmd.genlibs: build-2098127233
ti_msp_dl_config.c: build-2098127233
ti_msp_dl_config.h: build-2098127233
Event.dot: build-2098127233

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/TI/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/TI/OLED_Software_IIC" -I"D:/TI/OLED_Software_IIC/MPU6050" -I"D:/TI/OLED_Software_IIC/OLED" -I"D:/TI/OLED_Software_IIC/Debug" -I"D:/TI/mspm0_sdk_2_01_00_03/source/third_party/CMSIS/Core/Include" -I"D:/TI/mspm0_sdk_2_01_00_03/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: D:/TI/mspm0_sdk_2_01_00_03/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/TI/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/TI/OLED_Software_IIC" -I"D:/TI/OLED_Software_IIC/MPU6050" -I"D:/TI/OLED_Software_IIC/OLED" -I"D:/TI/OLED_Software_IIC/Debug" -I"D:/TI/mspm0_sdk_2_01_00_03/source/third_party/CMSIS/Core/Include" -I"D:/TI/mspm0_sdk_2_01_00_03/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


