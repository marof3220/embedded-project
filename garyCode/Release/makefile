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
garyCode.lss \

FLASH_IMAGE += \
garyCode.hex \

EEPROM_IMAGE += \
garyCode.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: garyCode.elf secondary-outputs

# Tool invocations
garyCode.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,garyCode.map -mmcu=atmega328p -o "garyCode.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

garyCode.lss: garyCode.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S garyCode.elf  >"garyCode.lss"
	@echo 'Finished building: $@'
	@echo ' '

garyCode.hex: garyCode.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex garyCode.elf  "garyCode.hex"
	@echo 'Finished building: $@'
	@echo ' '

garyCode.eep: garyCode.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex garyCode.elf  "garyCode.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: garyCode.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p garyCode.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) garyCode.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
