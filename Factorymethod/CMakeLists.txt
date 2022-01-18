cmake_minimum_required(VERSION 3.22) 
##################################################################
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER avr-g++ CACHE STRING "C++ compiler" FORCE)
set(CMAKE_C_COMPILER avr-gcc CACHE STRING "C compiler" FORCE)
set(CMAKE_OBJCOPY      avr-objcopy CACHE STRING "avr-objcopy" FORCE)
set(CMAKE_CXX_FLAGS "-mmcu=atmega32 -O1 -DF_CPU=1000000UL ")
##################################################################
project(CarCounter CXX)
##################################################################
add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_executable(${PROJECT_NAME}.elf main.cpp)
target_link_libraries(${PROJECT_NAME}.elf PUBLIC HAL)
target_include_directories(${PROJECT_NAME}.elf PUBLIC includes/)

##################################################################
#formating
add_custom_target(flash ALL
    DEPENDS ${PROJECT_NAME}.elf
    COMMAND avr-objcopy -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    ) 
##################################################################
add_custom_target(burn 
DEPENDS flash
COMMAND avrdude.exe -c usbasp -p m32 -B 0.5 -U flash:w:"${PROJECT_NAME}.hex":a
) 