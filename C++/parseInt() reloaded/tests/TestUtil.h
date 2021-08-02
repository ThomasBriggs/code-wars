#pragma once

inline void TEST_CASE(const char* STRING, int NUM)
{
    if (auto output = parse_int(STRING); output != NUM) {
        std::cout << "Expected: " << NUM << '\n';
        std::cout << "Actual: " << output << '\n';
        exit(1);
    }
}

