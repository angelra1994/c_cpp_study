cmake_minimum_required(VERSION 3.28)
project(cpp17_stl_cookbook)

add_definitions(-DPROJECT_NAME="cpp17_stl_cookbook")

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp17_stl_cookbook src/main.cpp)
add_executable(structured_bindings chapter_01/01_structured_bindings.cpp)
add_executable(if_switch_initializer chapter_01/02_if_switch_initializer.cpp)
add_executable(new_bracket_initializer chapter_01/03_new_bracket_initializer.cpp)