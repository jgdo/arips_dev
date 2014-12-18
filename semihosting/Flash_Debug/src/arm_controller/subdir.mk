################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/arm_controller/ArmHandler.cpp \
../src/arm_controller/ArmPositionReader.cpp \
../src/arm_controller/Controller.cpp \
../src/arm_controller/InverseDynamicsController.cpp \
../src/arm_controller/L298d.cpp \
../src/arm_controller/PDController.cpp \
../src/arm_controller/TrajectoryHandler.cpp 

OBJS += \
./src/arm_controller/ArmHandler.o \
./src/arm_controller/ArmPositionReader.o \
./src/arm_controller/Controller.o \
./src/arm_controller/InverseDynamicsController.o \
./src/arm_controller/L298d.o \
./src/arm_controller/PDController.o \
./src/arm_controller/TrajectoryHandler.o 

CPP_DEPS += \
./src/arm_controller/ArmHandler.d \
./src/arm_controller/ArmPositionReader.d \
./src/arm_controller/Controller.d \
./src/arm_controller/InverseDynamicsController.d \
./src/arm_controller/L298d.d \
./src/arm_controller/PDController.d \
./src/arm_controller/TrajectoryHandler.d 


# Each subdirectory must supply rules for building sources it contributes
src/arm_controller/%.o: ../src/arm_controller/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -march=armv7e-m -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized -Wall -Wpointer-arith -Wlogical-op -Wfloat-equal -Wno-write-strings -Wno-strict-prototypes  -g3 -DSTM32F407xx -DHSE_VALUE=8000000 -I/home/jgdo/ros/arips/workspace/semihosting/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include/cmsis -I../ros_lib -I../STM32F4xx_StdPeriph_Driver/inc -I../STM32_USB_OTG_Driver/inc -I../STM32_USB_Device_Library/Class/cdc/inc -I../STM32_USB_Device_Library/Core/inc -I../src -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -Wabi -Wctor-dtor-privacy -Wnoexcept -Wnon-virtual-dtor -Wstrict-null-sentinel -Wsign-promo -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


