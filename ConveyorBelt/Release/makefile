################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ConveyorBelt.lss \

FLASH_IMAGE += \
ConveyorBelt.hex \

EEPROM_IMAGE += \
ConveyorBelt.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ConveyorBelt.elf secondary-outputs

# Tool invocations
ConveyorBelt.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ConveyorBelt.map -mmcu=atmega328p -o "ConveyorBelt.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ConveyorBelt.lss: ConveyorBelt.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ConveyorBelt.elf  >"ConveyorBelt.lss"
	@echo 'Finished building: $@'
	@echo ' '

ConveyorBelt.hex: ConveyorBelt.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ConveyorBelt.elf  "ConveyorBelt.hex"
	@echo 'Finished building: $@'
	@echo ' '

ConveyorBelt.eep: ConveyorBelt.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ConveyorBelt.elf  "ConveyorBelt.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ConveyorBelt.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p ConveyorBelt.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ConveyorBelt.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
