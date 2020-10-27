################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ILI9341/ILI9341_GFX.c \
../ILI9341/ILI9341_STM32_Driver.c \
../ILI9341/ILI9341_Touchscreen.c 

OBJS += \
./ILI9341/ILI9341_GFX.o \
./ILI9341/ILI9341_STM32_Driver.o \
./ILI9341/ILI9341_Touchscreen.o 

C_DEPS += \
./ILI9341/ILI9341_GFX.d \
./ILI9341/ILI9341_STM32_Driver.d \
./ILI9341/ILI9341_Touchscreen.d 


# Each subdirectory must supply rules for building sources it contributes
ILI9341/ILI9341_GFX.o: ../ILI9341/ILI9341_GFX.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../ILI9341 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"ILI9341/ILI9341_GFX.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
ILI9341/ILI9341_STM32_Driver.o: ../ILI9341/ILI9341_STM32_Driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../ILI9341 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"ILI9341/ILI9341_STM32_Driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
ILI9341/ILI9341_Touchscreen.o: ../ILI9341/ILI9341_Touchscreen.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../ILI9341 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"ILI9341/ILI9341_Touchscreen.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

