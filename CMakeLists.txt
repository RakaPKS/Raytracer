cmake_minimum_required(VERSION 3.20)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Raytracer src/main.cpp src/Primaries/RTuple.h src/Projectile/Projectile.h src/Projectile/Environment.h src/Primaries/Color.h)
add_subdirectory(test)