cmake_minimum_required(VERSION 3.0)

project(lab3)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(lab3 source.cpp)
target_link_libraries(lab3 ${OpenCV_LIBS})