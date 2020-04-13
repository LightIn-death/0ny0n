cmake_minimum_required(VERSION 3.15)
project(0ny0n)

set(CMAKE_CXX_STANDARD 20)
include_directories(include src)
add_executable(0ny0n main.cpp src include)