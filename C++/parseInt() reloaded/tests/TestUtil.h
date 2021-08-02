#pragma once

#define TEST_CASE(STRING, NUM) \
if (auto output = parse_int(STRING); output != NUM) { \
    std::cout << "Expected: " << NUM << '\n'; \
    std::cout << "Actual: " << output << '\n'; \
    return 1; \
}