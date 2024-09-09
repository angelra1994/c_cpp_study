cmake_minimum_required(VERSION 3.28)
project(cpp17_stl_cookbook)

add_definitions(-DPROJECT_NAME="cpp17_stl_cookbook")

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp17_stl_cookbook                src/main.cpp)

add_executable(structured_bindings               chapter_01/01_structured_bindings.cpp)
add_executable(if_switch_initializer             chapter_01/02_if_switch_initializer.cpp)
add_executable(new_bracket_initializer           chapter_01/03_new_bracket_initializer.cpp)
add_executable(template_class_type_deduction     chapter_01/04_template_class_type_deduction.cpp)
add_executable(if_constexpr                      chapter_01/05_if_constexpr.cpp)
add_executable(inline_variable                   chapter_01/06_inline_variable.cpp)
add_executable(float_explain                     src/float_explain.c)

add_executable(01_get_sum                        dsa_c/01_get_sum.c)
add_executable(02_search                         dsa_c/02_search.c)
add_executable(03_sequence_table                 dsa_c/03_sequence_table.c)
add_executable(04_linked_table                   dsa_c/04_linked_table.c)