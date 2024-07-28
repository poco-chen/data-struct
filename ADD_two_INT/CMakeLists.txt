cmake_minimum_required(VERSION 3.28)
project(ADD_two_INT C)

set(CMAKE_C_STANDARD 11)

#add_executable(ADD_two_INT main.c)
add_executable(ADD main.c LINKLIST.c)