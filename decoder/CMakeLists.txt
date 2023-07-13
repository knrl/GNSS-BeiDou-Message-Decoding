cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
project(decoder)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_library(libs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(Boost COMPONENTS system filesystem REQUIRED)

if (Boost_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${Boost_FILESYSTEM_LIBRARY})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${Boost_FILESYSTEM_LIBRARY})
endif()
