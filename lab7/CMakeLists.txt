cmake_minimum_required(VERSION 3.10)
project(lab7)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab7
        lab_templ_except.cpp
        Counter.cpp Counter.h
        myString.cpp myString.h
        MyStack.h
        MyLinkedStack.h
        WrongIndexException.h
        RoundQueue.h)
