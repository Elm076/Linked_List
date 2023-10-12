cmake_minimum_required(VERSION 3.26)
project(pr1_CD)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(pr1_CD
        Dynamic_container.h
        main.cpp
        Airport.cpp
        Airport.h
        UTM.cpp
        UTM.h
        Linked_list.cpp
        Linked_list.h
        Iterator.cpp
        Iterator.h
        Node.cpp
        Node.h)
