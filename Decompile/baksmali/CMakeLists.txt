cmake_minimum_required(VERSION 3.5)
project(baksmali)

include_directories(../../Android ../)

set(SOURCE_FILES main.cpp)

add_executable(baksmali ${SOURCE_FILES})

target_link_libraries(baksmali Android Decompile)


