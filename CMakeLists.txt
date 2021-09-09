cmake_minimum_required(VERSION 3.15)

project(wasm_calculator VERSION 1.0.0 LANGUAGES CXX)

#set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(calculator)
add_subdirectory(test)
