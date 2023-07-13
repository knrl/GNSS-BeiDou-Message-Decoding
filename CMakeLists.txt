cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
project(bds_msg_decoder)

set(BUILD_TEST 0)
set(BUILD_FOR_PROFILING 0)

add_subdirectory(decoder)

if (BUILD_TEST)
    add_subdirectory(test)
else()
    add_subdirectory(app)
endif()

if (BUILD_FOR_PROFILING)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -pg")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
    message("Profiling Options: Enabled")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()