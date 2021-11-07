cmake_minimum_required(VERSION 3.20)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Raytracer src/main.cpp src/RTuple.h src/Projectile.h src/Environment.h)
add_subdirectory(test)