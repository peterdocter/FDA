cmake_minimum_required(VERSION 3.5)
project(Decompile)

include_directories(../Android)

set(BAKSMALI_SRC_FILES baksmali/bakSmali.cpp baksmali/bakClass.cpp baksmali/bakMethod.cpp baksmali/bakField.cpp)
set(BASE_SRC_FILES  base/accessFlags.cpp)

if (DEBUGTEST)
#    set(EXE_SOURCE_FILES bakSmali/bakSmali.cpp base/accessFlags.cpp main.cpp)
    set(EXE_SOURCE_FILES ${BAKSMALI_SRC_FILES} ${BASE_SRC_FILES} main.cpp)
    add_executable(Decompile ${EXE_SOURCE_FILES})
    set_target_properties(Decompile PROPERTIES ENABLE_EXPORTS ON)
else()
    add_library(Decompile ${SOURCE_FILES})
endif ()

target_link_libraries(Decompile Android)

#add_dependencies(Decompile Android)

