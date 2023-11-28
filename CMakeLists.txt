cmake_minimum_required(VERSION 3.26)
project(ListasDobles)

set(CMAKE_CXX_STANDARD 17)

add_executable(ListasDobles main.cpp
        Node.h
        LinkedListDouble.h
        LinkedListDouble.cpp
        BackPack.cpp
        Type.h
        ListValidator.h
        ListValidator.cpp
        ListHandler.h
        ListHandler.cpp
        AddPosition.h)
