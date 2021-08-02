enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include)
link_libraries(parse_int)

macro(create_test test_name)
    add_executable(${test_name} ${test_name}.cpp)
    add_test(${test_name} ${test_name})
endmacro(create_test)

create_test(FixedNums)