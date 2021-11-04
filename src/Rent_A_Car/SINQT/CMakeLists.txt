cmake_minimum_required(VERSION 3.20)
project(Rent_A_Car)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Rent_A_Car
        main.cpp
        Grafo.cpp
        Grafo.h)
