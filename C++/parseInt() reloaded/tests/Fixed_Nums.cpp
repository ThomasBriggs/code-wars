#include "parse_int.h"
#include "TestUtil.h"

int main(int argc, char const *argv[])
{
    TEST_CASE("one", 1);
    TEST_CASE("two hundred", 200);
    TEST_CASE("two hundred and two", 202);
    TEST_CASE("three thousand two hundred", 3200);
    TEST_CASE("seven hundred thousand", 700000);
}