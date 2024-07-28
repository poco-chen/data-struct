cmake_minimum_required(VERSION 3.28)
project(CLASS_LINK_LIST C)

set(CMAKE_C_STANDARD 11)

add_library(STATIC main.c)

add_executable(List main.c link_list.c)

