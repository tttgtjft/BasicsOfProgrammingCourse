cmake_minimum_required(VERSION 3.20)
project(LB5b C)

set(CMAKE_C_STANDARD 11)

add_executable(LB5b main.c)

add_subdirectory(libs)
target_link_libraries(LB5b data_structures)
