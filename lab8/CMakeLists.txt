cmake_minimum_required(VERSION 3.10)
project(lab8)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab8
        lab_vector_list_deque.cpp
        myString.cpp myString.h
        Counter.cpp Counter.h
        Point.h Point.cpp
        Functions.h)
