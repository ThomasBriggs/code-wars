add_library(
    ImageRotate
    ImageRotate.cpp
)

add_executable(main main.cpp)
target_link_libraries(main ImageRotate)