################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Graph.cpp \
../src/NFA.cpp \
../src/Node.cpp \
../src/Parser.cpp \
../src/main.cpp 

OBJS += \
./src/Graph.o \
./src/NFA.o \
./src/Node.o \
./src/Parser.o \
./src/main.o 

CPP_DEPS += \
./src/Graph.d \
./src/NFA.d \
./src/Node.d \
./src/Parser.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


