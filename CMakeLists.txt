cmake_minimum_required(VERSION 3.10)
project(Radix2DIT)

add_library(Radix2DIT STATIC fft.cpp)
target_include_directories(Radix2DIT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
