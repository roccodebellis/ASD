################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bintree_array.cpp \
../src/bintree_list.cpp \
../src/hash_table.cpp \
../src/list_vector.cpp \
../src/priority_queue_array.cpp \
../src/queue_array.cpp \
../src/queue_pointer.cpp \
../src/set_array.cpp \
../src/stack_array.cpp \
../src/stack_pointer.cpp \
../src/tree_link.cpp \
../src/tree_list.cpp \
../src/tree_pointer.cpp 

OBJS += \
./src/bintree_array.o \
./src/bintree_list.o \
./src/hash_table.o \
./src/list_vector.o \
./src/priority_queue_array.o \
./src/queue_array.o \
./src/queue_pointer.o \
./src/set_array.o \
./src/stack_array.o \
./src/stack_pointer.o \
./src/tree_link.o \
./src/tree_list.o \
./src/tree_pointer.o 

CPP_DEPS += \
./src/bintree_array.d \
./src/bintree_list.d \
./src/hash_table.d \
./src/list_vector.d \
./src/priority_queue_array.d \
./src/queue_array.d \
./src/queue_pointer.d \
./src/set_array.d \
./src/stack_array.d \
./src/stack_pointer.d \
./src/tree_link.d \
./src/tree_list.d \
./src/tree_pointer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


