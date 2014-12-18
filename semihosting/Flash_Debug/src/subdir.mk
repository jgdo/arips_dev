################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp 

C_SRCS += \
../src/_initialize_hardware.c \
../src/stm32f4_discovery.c \
../src/stm32f4xx_it.c \
../src/usb_bsp.c \
../src/usbd_cdc_vcp.c \
../src/usbd_desc.c \
../src/usbd_usr.c 

OBJS += \
./src/_initialize_hardware.o \
./src/main.o \
./src/stm32f4_discovery.o \
./src/stm32f4xx_it.o \
./src/usb_bsp.o \
./src/usbd_cdc_vcp.o \
./src/usbd_desc.o \
./src/usbd_usr.o 

C_DEPS += \
./src/_initialize_hardware.d \
./src/stm32f4_discovery.d \
./src/stm32f4xx_it.d \
./src/usb_bsp.d \
./src/usbd_cdc_vcp.d \
./src/usbd_desc.d \
./src/usbd_usr.d 

CPP_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -march=armv7e-m -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized -Wall -Wpointer-arith -Wlogical-op -Wfloat-equal -Wno-write-strings -Wno-strict-prototypes  -g3 -DSTM32F407xx -DHSE_VALUE=8000000 -I/home/jgdo/ros/arips/workspace/semihosting/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include/cmsis -I../src -I../STM32_USB_OTG_Driver/inc -I../STM32_USB_Device_Library/Core/inc -I../STM32_USB_Device_Library/Class/cdc/inc -I../STM32F4xx_StdPeriph_Driver/inc -I../ros_lib -std=gnu11 -Wmissing-prototypes -Wstrict-prototypes -Wbad-function-cast -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -march=armv7e-m -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized -Wall -Wpointer-arith -Wlogical-op -Wfloat-equal -Wno-write-strings -Wno-strict-prototypes  -g3 -DSTM32F407xx -DHSE_VALUE=8000000 -I/home/jgdo/ros/arips/workspace/semihosting/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include/cmsis -I../ros_lib -I../STM32F4xx_StdPeriph_Driver/inc -I../STM32_USB_OTG_Driver/inc -I../STM32_USB_Device_Library/Class/cdc/inc -I../STM32_USB_Device_Library/Core/inc -I../src -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -Wabi -Wctor-dtor-privacy -Wnoexcept -Wnon-virtual-dtor -Wstrict-null-sentinel -Wsign-promo -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


