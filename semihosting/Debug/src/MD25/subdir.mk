################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MD25/MD25.cpp 

OBJS += \
./src/MD25/MD25.o 

CPP_DEPS += \
./src/MD25/MD25.d 


# Each subdirectory must supply rules for building sources it contributes
src/MD25/%.o: ../src/MD25/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -march=armv7e-m -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized -Wall -Wpointer-arith -Wlogical-op -Wfloat-equal -Wno-write-strings -Wno-strict-prototypes  -g3 -DDEBUG -DUSE_FULL_ASSERT -DOS_USE_SEMIHOSTING -DTRACE -DOS_USE_TRACE_SEMIHOSTING_STDOUT -DSTM32F407xx -DHSE_VALUE=8000000 -I/home/jgdo/ros/arips/workspace/semihosting/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include/cmsis -I/home/jgdo/ros/arips/workspace/semihosting/src -I/home/jgdo/ros/arips/workspace/semihosting/STM32_USB_OTG_Driver/inc -I/home/jgdo/ros/arips/workspace/semihosting/STM32_USB_Device_Library/Core/inc -I/home/jgdo/ros/arips/workspace/semihosting/STM32_USB_Device_Library/Class/cdc/inc -I/home/jgdo/ros/arips/workspace/semihosting/STM32F4xx_StdPeriph_Driver/inc -I/home/jgdo/ros/arips/workspace/semihosting/ros_lib -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -Wabi -Wctor-dtor-privacy -Wnoexcept -Wnon-virtual-dtor -Wstrict-null-sentinel -Wsign-promo -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


