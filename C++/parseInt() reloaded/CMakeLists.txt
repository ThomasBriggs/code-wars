#CMake Version
cmake_minimum_required(VERSION 3.20.0)

#Project name and version
project("parseInt() reloaded" VERSION 1.0.0)

#C++ standard for the project
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

#Enable compiler warnings
if(ON)
    if (MSVC)
        #warning level 4
        add_compile_options(/W4)
    else()
        #lots of warnings
        add_compile_options(-Wall -Wextra)
    endif()
endif()

include(CTest)

add_subdirectory(src)
add_subdirectory(tests)
