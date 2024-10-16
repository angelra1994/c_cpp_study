cmake_minimum_required(VERSION 3.28)
project(c_cpp_study)

add_definitions(-DPROJECT_NAME="c_cpp_study")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

add_executable(c_cpp_study_main                  src/main.cpp)
add_executable(float_explain                     src/float_explain.c)

add_subdirectory(cpp17_stl_cookbook/chapter_01)

add_subdirectory(dsa_c)
add_subdirectory(c_pointer)