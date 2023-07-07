################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Util/math_util.c 

OBJS += \
./Core/Src/Util/math_util.o 

C_DEPS += \
./Core/Src/Util/math_util.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Util/%.o Core/Src/Util/%.su Core/Src/Util/%.cyclo: ../Core/Src/Util/%.c Core/Src/Util/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F334x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Util

clean-Core-2f-Src-2f-Util:
	-$(RM) ./Core/Src/Util/math_util.cyclo ./Core/Src/Util/math_util.d ./Core/Src/Util/math_util.o ./Core/Src/Util/math_util.su

.PHONY: clean-Core-2f-Src-2f-Util

