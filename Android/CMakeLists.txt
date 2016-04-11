cmake_minimum_required(VERSION 3.5)
project(Android)

include_directories(external)


set(SRC_LIBDEX libdex/Leb128.cpp libdex/DexFile.cpp libdex/SysUtil.cpp
        libdex/DexCatch.cpp libdex/DexOptData.cpp libdex/DexProto.cpp
        libdex/sha1.cpp libdex/ZipArchive.cpp libdex/DexClass.cpp
        libdex/DexOpcodes.cpp libdex/DexSwapVerify.cpp
        libdex/DexDataMap.cpp libdex/DexUtf.cpp
        libdex/CmdUtils.cpp libdex/DexDebugInfo.cpp
        libdex/InstrUtils.cpp)
set(SRC_VM vm/oo/Object.cpp vm/oo/Resolve.cpp vm/oo/Class.cpp
        vm/DvmDex.cpp vm/Dalvik.h)
set(SRC_DexDump dexdump/DexDump.cpp)

set(SOURCE_FILES ${SRC_LIBDEX} ${SRC_VM} ${SRC_DexDump}  Extra.h Extra.cpp)
add_library(Android ${SOURCE_FILES})
target_link_libraries(Android z)
