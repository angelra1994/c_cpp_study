cmake_minimum_required(VERSION 3.28)
project(c_cpp_study)

add_definitions(-DPROJECT_NAME="c_cpp_study")

set(CMAKE_CXX_STANDARD 17)

add_executable(c_cpp_study_main                src/main.cpp)

add_executable(structured_bindings               cpp17_stl_cookbook/chapter_01/01_structured_bindings.cpp)
add_executable(if_switch_initializer             cpp17_stl_cookbook/chapter_01/02_if_switch_initializer.cpp)
add_executable(new_bracket_initializer           cpp17_stl_cookbook/chapter_01/03_new_bracket_initializer.cpp)
add_executable(template_class_type_deduction     cpp17_stl_cookbook/chapter_01/04_template_class_type_deduction.cpp)
add_executable(if_constexpr                      cpp17_stl_cookbook/chapter_01/05_if_constexpr.cpp)
add_executable(inline_variable                   cpp17_stl_cookbook/chapter_01/06_inline_variable.cpp)
add_executable(float_explain                     src/float_explain.c)

add_executable(01_get_sum                        dsa_c/01_get_sum.c)
add_executable(02_search                         dsa_c/02_search.c)
add_executable(03_sequence_table                 dsa_c/03_sequence_table.c)
add_executable(04_linked_table                   dsa_c/04_linked_table.c)

add_executable(01_pointer_base                   c_pointer/01_pointer_base.c)
add_executable(02_pointer_as_parameter           c_pointer/02_pointer_as_parameter.c)
add_executable(03_pointer_calculation            c_pointer/03_pointer_calculation.c)
add_executable(04_pointer_wild                   c_pointer/04_pointer_wild_null.c)
add_executable(05_pointer_use                    c_pointer/05_pointer_use.c)
add_executable(06_pointer_vs_array               c_pointer/06_pointer_vs_array.c)