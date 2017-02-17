cmake_minimum_required(VERSION 3.6)
project(FdF)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c FdF.c FdF.h)
add_executable(FdF ${SOURCE_FILES} main.c FdF.c FdF.h)