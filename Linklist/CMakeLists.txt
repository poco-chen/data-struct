cmake_minimum_required(VERSION 3.28)
project(Linklist C)

set(CMAKE_C_STANDARD 11)

add_library(Linklist STATIC Link_List.c)

add_executable(Link_List Link_List.c)
add_executable(list Link_List.c main.c)