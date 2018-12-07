cmake_minimum_required(VERSION 3.13)
project(cfg C)

set(CMAKE_C_STANDARD 11)

add_executable(cfg main.c cfg_linked_list.c cfg_linked_list.h)