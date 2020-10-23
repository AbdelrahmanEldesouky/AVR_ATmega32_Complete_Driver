################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../4_LIBRARY/MAPPING.c \
../4_LIBRARY/STRINGFUNC.c 

OBJS += \
./4_LIBRARY/MAPPING.o \
./4_LIBRARY/STRINGFUNC.o 

C_DEPS += \
./4_LIBRARY/MAPPING.d \
./4_LIBRARY/STRINGFUNC.d 


# Each subdirectory must supply rules for building sources it contributes
4_LIBRARY/%.o: ../4_LIBRARY/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


