################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/ADC.c 

OBJS += \
./Driver/ADC.o 

C_DEPS += \
./Driver/ADC.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/%.o Driver/%.su: ../Driver/%.c Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VETx -c -I../Inc -I"D:/Files/STM32F407_Workspace/ADC_Driver/DMA" -I"D:/Files/STM32F407_Workspace/ADC_Driver/Console" -I"D:/Files/STM32F407_Workspace/ADC_Driver/GPIO" -I"D:/Files/STM32F407_Workspace/ADC_Driver/Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Driver

clean-Driver:
	-$(RM) ./Driver/ADC.d ./Driver/ADC.o ./Driver/ADC.su

.PHONY: clean-Driver

