cmake_minimum_required(VERSION 3.26)
project(ListasDobles)

set(CMAKE_CXX_STANDARD 17)

add_executable(ListasDobles main.cpp
        Node.h
        Node.cpp
        LinkedDouble.h
        LinkedDouble.cpp)
