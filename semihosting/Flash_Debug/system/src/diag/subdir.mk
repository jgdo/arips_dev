################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/diag/Trace.c \
../system/src/diag/trace_impl.c 

OBJS += \
./system/src/diag/Trace.o \
./system/src/diag/trace_impl.o 

C_DEPS += \
./system/src/diag/Trace.d \
./system/src/diag/trace_impl.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/diag/%.o: ../system/src/diag/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -march=armv7e-m -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fsingle-precision-constant -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized -Wall -Wpointer-arith -Wlogical-op -Wfloat-equal -Wno-write-strings -Wno-strict-prototypes  -g3 -DSTM32F407xx -DHSE_VALUE=8000000 -I/home/jgdo/ros/arips/workspace/semihosting/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include -I/home/jgdo/ros/arips/workspace/semihosting/system/include/cmsis -I../src -I../STM32_USB_OTG_Driver/inc -I../STM32_USB_Device_Library/Core/inc -I../STM32_USB_Device_Library/Class/cdc/inc -I../STM32F4xx_StdPeriph_Driver/inc -I../ros_lib -std=gnu11 -Wmissing-prototypes -Wstrict-prototypes -Wbad-function-cast -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


