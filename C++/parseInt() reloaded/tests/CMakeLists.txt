include(CTest)
enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include)
link_libraries(parse_int)

add_executable(FixedNums Fixed_Nums.cpp)
add_test(FixedNums FixedNums)