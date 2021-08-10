find_package(GTest)
include(GoogleTest)

include_directories(${CMAKE_SOURCE_DIR}/src)

link_libraries(GTest::gtest_main)
add_executable(TestUtilTests TestUtilTests.cpp)
add_executable(TestSuit test.cpp)


gtest_discover_tests(TestSuit)
gtest_discover_tests(TestUtilTests)

