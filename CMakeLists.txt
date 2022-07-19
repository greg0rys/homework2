cmake_minimum_required(VERSION 3.22)
project(homework2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(homework2_reset)

add_executable(homework2
        homework2_reset/assignment.cpp
        homework2_reset/assignment.h
        homework2_reset/main.cpp
        homework2_reset/main.h
        homework2_reset/student.cpp
        homework2_reset/student.h
        assignment.cpp
        assignment.h
        main.cpp
        main.h
        student.cpp
        student.h)
