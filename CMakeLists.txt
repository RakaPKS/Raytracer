cmake_minimum_required(VERSION 3.20)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Raytracer src/main.cpp src/Primaries/RTuple.h src/Primaries/Color.h src/Graphics/Canvas.h src/Graphics/PPM.h src/Projectile/Projectile.cpp src/Projectile/Projectile.h src/Projectile/Environment.h src/Projectile/Environment.cpp src/Graphics/PPM.cpp src/Graphics/Canvas.cpp)
add_subdirectory(test)