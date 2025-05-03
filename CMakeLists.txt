cmake_minimum_required(VERSION 3.30)

project(BachelorDataStructure)

set(CMAKE_CXX_STANDARD 20)

#设置include文件夹,
#PROJECT_BINARY_DIR是BachelorDataStructure\cmake-build-debug\...或BachelorDataStructure\build\...
include_directories(${CMAKE_SOURCE_DIR}/Source)

#设置可执行文件输出路径,CMAKE_CURRENT_SOURCE_DIR是...\BachelorDataStructure\...
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Output)

add_executable(BachelorDataStructure main.cpp)
