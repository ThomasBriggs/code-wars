enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include)
link_libraries(parse_int)

macro(create_test test_name)
    add_executable(${test_name} ${test_name})
    add_test(${test_name} ${test_name})
endmacro(create_test)

file(GLOB test_list RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
foreach(X ${test_list})
    create_test(${X})
endforeach()

