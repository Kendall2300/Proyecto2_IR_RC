
Cmake_minimum_required(VERSION 3.10)
project(TestGenetico)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/home/dlurena24/Programs/Qt/6.0.4/gcc_64/lib/cmake/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Qt6Widgets REQUIRED)
find_package( OpenCV REQUIRED )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(TestGenetico TestGenetico.cpp TestGenetico.cpp TestGenetico.h)


target_link_libraries(TestGenetico Qt6::Widgets)
target_link_libraries(TestGenetico ${OpenCV_LIBS} )
