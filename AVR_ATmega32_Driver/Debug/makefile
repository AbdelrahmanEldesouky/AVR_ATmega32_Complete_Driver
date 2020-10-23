################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 4_LIBRARY/subdir.mk
-include 2_HAL/STPMOTOR/subdir.mk
-include 2_HAL/SSD/subdir.mk
-include 2_HAL/PSWITCH/subdir.mk
-include 2_HAL/LM35/subdir.mk
-include 2_HAL/LED/subdir.mk
-include 2_HAL/KPD/subdir.mk
-include 2_HAL/DCMOTOR/subdir.mk
-include 2_HAL/CLCD/subdir.mk
-include 2_HAL/BUZZER/subdir.mk
-include 1_MCAL/9-\ TWI/subdir.mk
-include 1_MCAL/8-\ SPI/subdir.mk
-include 1_MCAL/7-\ USART/subdir.mk
-include 1_MCAL/6-\ TIMER/subdir.mk
-include 1_MCAL/5-\ ADC/subdir.mk
-include 1_MCAL/4-\ GIE/subdir.mk
-include 1_MCAL/3-\ EXIT/subdir.mk
-include 1_MCAL/1-\ GPIO/subdir.mk
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
AVR_ATmega32_Driver.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: AVR_ATmega32_Driver.elf secondary-outputs

# Tool invocations
AVR_ATmega32_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_ATmega32_Driver.map -mmcu=atmega16 -o "AVR_ATmega32_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_ATmega32_Driver.lss: AVR_ATmega32_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_ATmega32_Driver.elf  >"AVR_ATmega32_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_ATmega32_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 AVR_ATmega32_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_ATmega32_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
