Cmake_minimum_required(VERSION 3.10)
project(prove)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/home/gabriel/Qt/6.2.0/gcc_64/lib/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Qt6Widgets REQUIRED)
find_package( OpenCV REQUIRED )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(prove main.cpp mainwindow.cpp mainwindow.h)


target_link_libraries(prove Qt6::Widgets)
target_link_libraries( prove ${OpenCV_LIBS} )