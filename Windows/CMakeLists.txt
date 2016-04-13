cmake_minimum_required(VERSION 3.5)
project(FDA)

set(CMAKE_PREFIX_PATH D:/ProgrameSoft/QT56/5.6/mingw49_32)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#查找Qt的库
find_package(Qt5Widgets)

include_directories(../Android ../Decompile .)

set(SOURCE_FILES main.cpp
        Main/Main.cpp)
add_executable(FDA ${SOURCE_FILES})

target_link_libraries(FDA Qt5::Widgets Android Decompile)
