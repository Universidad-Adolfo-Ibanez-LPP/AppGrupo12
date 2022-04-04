cmake_minimum_required(VERSION 3.21)
project(app1)

set(CMAKE_CXX_STANDARD 14)

add_executable(app1 header.h main.c read_file.c menu.c funciones.c)
