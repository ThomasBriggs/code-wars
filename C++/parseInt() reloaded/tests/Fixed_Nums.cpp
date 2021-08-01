#include "parse_int.h"

#define TEST_CASE(STRING, NUM) \
if (auto output = parse_int(STRING); output != NUM) { \
    std::cout << "Expected: " << NUM << '\n'; \
    std::cout << "Got: " << output << '\n'; \
    return 1; \
}

int main(int argc, char const *argv[])
{
    TEST_CASE("one", 1);
    TEST_CASE("two hundred", 200);
    TEST_CASE("two hundred and 2", 202);
    TEST_CASE("three thousand two hundred", 3200);
}
