################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP1.c \
../src/operaciones.c \
../src/validaciones.c 

C_DEPS += \
./src/TP1.d \
./src/operaciones.d \
./src/validaciones.d 

OBJS += \
./src/TP1.o \
./src/operaciones.o \
./src/validaciones.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/TP1.d ./src/TP1.o ./src/operaciones.d ./src/operaciones.o ./src/validaciones.d ./src/validaciones.o

.PHONY: clean-src

