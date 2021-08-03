include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(parse_int parse_int.cpp)

add_executable(main main.cpp)
target_link_libraries(main parse_int)