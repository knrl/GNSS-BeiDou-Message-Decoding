cmake_minimum_required(VERSION 3.12) # version can be different

set(CMAKE_CXX_STANDARD 17)

project(my_cpp_project) #name of your project

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(run_tests test_main.cpp src/beidou_subframe.cpp src/navigation_engine.cpp) # add this executable

target_link_libraries(run_tests PRIVATE gtest) # link google test to this executable
