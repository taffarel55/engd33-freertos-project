################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/AHRS/ahrs.c 

OBJS += \
./Core/Src/AHRS/ahrs.o 

C_DEPS += \
./Core/Src/AHRS/ahrs.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/AHRS/%.o Core/Src/AHRS/%.su Core/Src/AHRS/%.cyclo: ../Core/Src/AHRS/%.c Core/Src/AHRS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F334x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-AHRS

clean-Core-2f-Src-2f-AHRS:
	-$(RM) ./Core/Src/AHRS/ahrs.cyclo ./Core/Src/AHRS/ahrs.d ./Core/Src/AHRS/ahrs.o ./Core/Src/AHRS/ahrs.su

.PHONY: clean-Core-2f-Src-2f-AHRS

