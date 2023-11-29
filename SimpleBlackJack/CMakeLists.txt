cmake_minimum_required(VERSION 3.21)
project(cardv)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cardv
        card.cpp
        card.h
        main.cpp
        pile.cpp
        pile.h)
