cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
project(controller)

file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp")

add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_library(libs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC libs::decoder)
target_include_directories(${PROJECT_NAME} PUBLIC .)