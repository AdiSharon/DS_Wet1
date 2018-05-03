cmake_minimum_required(VERSION 3.7)
project(wet1)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_C_FLAGS "-std=c++0x -Wall -Werror -pedantic-errors -DNDEBUG")

set(SOURCE_FILES main.cpp Tree.h Execptions.h)
add_executable(wet1 ${SOURCE_FILES})