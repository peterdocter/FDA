cmake_minimum_required(VERSION 3.5)
project(FDA)

set(CMAKE_PREFIX_PATH D:/ProgrameSoft/QT56/5.6/mingw49_32)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#查找Qt的库
find_package(Qt5Quick)
find_package(Qt5Gui)
find_package(Qt5Qml)
find_package(Qt5Network)
find_package(Qt5Core)

include_directories(../Android ../Decompile .)

set(SOURCE_FILES main.cpp uiforms.cpp)
add_executable(FDA ${SOURCE_FILES})

target_link_libraries(FDA Qt5::Quick Qt5::Gui Qt5::Qml Qt5::Network Qt5::Core Android Decompile)
