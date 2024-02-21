cmake_minimum_required(VERSION 3.10)


SET(CMAKE_C_COMPILER "gcc")

SET(CMAKE_CXX_COMPILER "g++")

project(raytracing)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(src SRC_LIST)

include_directories(include)

add_executable(raytracing ${SRC_LIST})

