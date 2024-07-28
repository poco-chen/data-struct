cmake_minimum_required(VERSION 3.28)
project(CLASS_LINKLIST_WITH_HEAD C)

set(CMAKE_C_STANDARD 11)

add_library(CLASS_LINKLIST_WITH_HEAD SHARED main.c)
add_executable(HEAD_LIST main.c head_list.c)