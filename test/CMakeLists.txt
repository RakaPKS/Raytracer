project(test)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(test_run Primaries/RPointTest.cpp Primaries/ColorTest.cpp Primaries/RVectorTest.cpp Graphics/CanvasTest.cpp Graphics/PPMTest.cpp)

target_link_libraries(test_run gtest gtest_main)