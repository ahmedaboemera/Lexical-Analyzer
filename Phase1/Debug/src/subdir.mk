################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DFA.cpp \
../src/NFA.cpp \
<<<<<<< HEAD
../src/NFABuilder.cpp \
=======
<<<<<<< HEAD
<<<<<<< HEAD
../src/NFABuilder.cpp \
=======
>>>>>>> 15c4dc3cd8abcd9291b34f9b75d841c62308267e
>>>>>>> c52159a70d9a1726a1191f5192aa1fee3ae2a5c0
=======
>>>>>>> 15c4dc3cd8abcd9291b34f9b75d841c62308267e
>>>>>>> c52159a70d9a1726a1191f5192aa1fee3ae2a5c0
../src/Parser.cpp \
../src/main.cpp 

OBJS += \
./src/DFA.o \
./src/NFA.o \
<<<<<<< HEAD
./src/NFABuilder.o \
=======
<<<<<<< HEAD
<<<<<<< HEAD
./src/NFABuilder.o \
=======
>>>>>>> 15c4dc3cd8abcd9291b34f9b75d841c62308267e
>>>>>>> c52159a70d9a1726a1191f5192aa1fee3ae2a5c0
=======
>>>>>>> 15c4dc3cd8abcd9291b34f9b75d841c62308267e
>>>>>>> c52159a70d9a1726a1191f5192aa1fee3ae2a5c0
./src/Parser.o \
./src/main.o 

CPP_DEPS += \
./src/DFA.d \
./src/NFA.d \
<<<<<<< HEAD
./src/NFABuilder.d \
=======
<<<<<<< HEAD
<<<<<<< HEAD
./src/NFABuilder.d \
=======
>>>>>>> 15c4dc3cd8abcd9291b34f9b75d841c62308267e
>>>>>>> c52159a70d9a1726a1191f5192aa1fee3ae2a5c0
=======
>>>>>>> 15c4dc3cd8abcd9291b34f9b75d841c62308267e
>>>>>>> c52159a70d9a1726a1191f5192aa1fee3ae2a5c0
./src/Parser.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


