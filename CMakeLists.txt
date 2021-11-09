cmake_minimum_required(VERSION 3.20)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES
        src/*.h
        src/*.cpp
        )

add_executable(Raytracer ${SOURCES})

add_subdirectory(test)