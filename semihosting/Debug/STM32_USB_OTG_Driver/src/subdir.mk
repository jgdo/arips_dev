################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_USB_OTG_Driver/src/usb_core.c \
../STM32_USB_OTG_Driver/src/usb_dcd.c \
../STM32_USB_OTG_Driver/src/usb_dcd_int.c 

OBJS += \
./STM32_USB_OTG_Driver/src/usb_core.o \
./STM32_USB_OTG_Driver/src/usb_dcd.o \
./STM32_USB_OTG_Driver/src/usb_dcd_int.o 

C_DEPS += \
./STM32_USB_OTG_Driver/src/usb_core.d \
./STM32_USB_OTG_Driver/src/usb_dcd.d \
./STM32_USB_OTG_Driver/src/usb_dcd_int.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_USB_OTG_Driver/src/%.o: ../STM32_USB_OTG_Driver/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -march=armv7e-m -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized -Wall -Wpointer-arith -Wlogical-op -Wfloat-equal -Wno-write-strings -Wno-strict-prototypes  -g3 -DDEBUG -DUSE_FULL_ASSERT -DOS_USE_SEMIHOSTING -DTRACE -DOS_USE_TRACE_SEMIHOSTING_STDOUT -DSTM32F407xx -DHSE_VALUE=8000000 -I/home/jgdo/ros/arips/workspace/semihosting/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include/cmsis -I/home/jgdo/ros/arips/workspace/semihosting/src -I/home/jgdo/ros/arips/workspace/semihosting/STM32_USB_OTG_Driver/inc -I/home/jgdo/ros/arips/workspace/semihosting/STM32_USB_Device_Library/Core/inc -I/home/jgdo/ros/arips/workspace/semihosting/STM32_USB_Device_Library/Class/cdc/inc -I/home/jgdo/ros/arips/workspace/semihosting/STM32F4xx_StdPeriph_Driver/inc -I/home/jgdo/ros/arips/workspace/semihosting/ros_lib -std=gnu11 -Wmissing-prototypes -Wstrict-prototypes -Wbad-function-cast -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


