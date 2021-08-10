find_package(GTest)
include(GoogleTest)

include_directories(${CMAKE_SOURCE_DIR}/src)
link_libraries(GTest::gtest_main ImageRotate)

add_executable(TestUtilTests TestUtilTests.cpp)
add_executable(RotateImageTests RotateImageTests.cpp)
add_executable(RandomRotateImageTests RandomRotateImageTests.cpp)

gtest_discover_tests(RotateImageTests)
gtest_discover_tests(TestUtilTests)
gtest_discover_tests(RandomRotateImageTests)

