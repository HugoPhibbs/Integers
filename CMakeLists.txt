cmake_minimum_required(VERSION 3.21)
project(Integers)

set(CMAKE_CXX_STANDARD 14)

add_executable(Integers main.cpp src/Integer.cpp src/Integer.h src/Rational.cpp src/Rational.h)
