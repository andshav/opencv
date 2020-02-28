cmake_minimum_required(VERSION 3.0)

project(lab1.2)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(lab1.2 source.cpp)
target_link_libraries(lab1.2 ${OpenCV_LIBS})