cmake_minimum_required(VERSION 3.22) 
add_library(HAL 
    Button.cpp 
    LED.cpp 
    Parking.cpp)
target_include_directories(HAL PUBLIC ${CMAKE_SOURCE_DIR}/includes/)
