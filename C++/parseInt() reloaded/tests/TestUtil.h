#pragma once

#include "parse_int.h"

inline void TEST_CASE(const char* STRING, int NUM)
{
    if (auto output = parse_int(STRING); output != NUM) {
        std::cout << "Input: " << STRING << '\n';
        std::cout << "Expected: " << NUM << '\n';
        std::cout << "Actual: " << output << '\n';
        exit(1);
    }
}

