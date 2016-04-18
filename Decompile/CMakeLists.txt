cmake_minimum_required(VERSION 3.5)
project(Decompile)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(../Android .)

set(BAKSMALI_SRC_FILES baksmali/bakSmali.cpp baksmali/bakClass.cpp baksmali/bakMethod.cpp baksmali/bakField.cpp)
set(BASE_SRC_FILES  base/accessFlags.cpp)

set(SOURCE_FILES ${BAKSMALI_SRC_FILES} ${BASE_SRC_FILES})

add_library(Decompile ${SOURCE_FILES})

target_link_libraries(Decompile Android)


