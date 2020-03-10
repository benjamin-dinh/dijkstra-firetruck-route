cmake_minimum_required(VERSION 3.15)
project(p5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(p5
        Testing/City-1000-150000-4.txt
        Testing/City-1000-150000-5.txt
        Testing/City-1000-150000-6.txt
        CPUTimer.h
        FindMax.cpp
        FindMax.h
        RunFind.cpp
        RunFind.h)
