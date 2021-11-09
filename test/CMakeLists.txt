cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)

project(test)
add_subdirectory(lib)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB_RECURSE SOURCES
        ../src/*.h
        ../src/*.cpp
        )


add_executable(test Primaries/RPointTest.cpp Primaries/ColorTest.cpp Primaries/RVectorTest.cpp Graphics/CanvasTest.cpp Graphics/PPMTest.cpp ${SOURCES})

target_link_libraries(test gtest gtest_main)
