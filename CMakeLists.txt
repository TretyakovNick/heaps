cmake_minimum_required(VERSION 3.13)

project(Heaps)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(heaps)

add_executable(Heaps
        heaps/array.cpp
        heaps/array.h
        heaps/heap.cpp
        heaps/heap.h
        array.cpp
        array.h
        binomial_heap.cpp
        binomial_heap.h
        heap2.cpp
        heap2.h
        main.cpp)
