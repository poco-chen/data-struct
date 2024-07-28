cmake_minimum_required(VERSION 3.28)
project(CLASS_DOUBLY_LIST C)

set(CMAKE_C_STANDARD 11)

add_executable(CLASS_DOUBLY_LIST main.c)
add_executable(D_LIST main.c doubly_list.c)
