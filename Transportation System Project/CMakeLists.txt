cmake_minimum_required(VERSION 3.20)
project(CLion_Projects C)

set(CMAKE_C_STANDARD 99)

add_executable(CLion_Projects main.c bus_transport.c bus_transport.h)
