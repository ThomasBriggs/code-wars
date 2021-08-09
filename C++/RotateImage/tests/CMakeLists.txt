find_package(GTest)
include(GoogleTest)

include_directories(${CMAKE_SOURCE_DIR}/src)


add_executable(TestSuit test.cpp)
target_link_libraries(TestSuit GTest::gtest_main)

gtest_discover_tests(TestSuit)

