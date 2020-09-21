################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
hw2.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
hw2.list \

OBJCOPY_BIN += \
hw2.bin \


# All Target
all: hw2.elf secondary-outputs

# Tool invocations
hw2.elf: $(OBJS) $(USER_OBJS) /home/tantatorn/STM32CubeIDE/workspace_1.3.0/microcontroller_labs/hw2/STM32F767ZITX_FLASH.ld
	arm-none-eabi-gcc -o "hw2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"/home/tantatorn/STM32CubeIDE/workspace_1.3.0/microcontroller_labs/hw2/STM32F767ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="hw2.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

hw2.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "hw2.list"
	@echo 'Finished building: $@'
	@echo ' '

hw2.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "hw2.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
