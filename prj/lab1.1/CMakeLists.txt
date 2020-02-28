cmake_minimum_required(VERSION 3.0)

project(lab1.1)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(lab1.1 source.cpp)
target_link_libraries(lab1.1 ${OpenCV_LIBS})