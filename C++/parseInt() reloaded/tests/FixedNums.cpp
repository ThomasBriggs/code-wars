#include "parse_int.h"
#include "TestUtil.h"

int main()
{
    TEST_CASE("zero", 0);
    TEST_CASE("one", 1);
    TEST_CASE("thirteen", 13);
    TEST_CASE("thirty", 30);
    TEST_CASE("twenty", 20);
    TEST_CASE("twenty-five", 25);
    TEST_CASE("two hundred", 200);
    TEST_CASE("two hundred and five", 205);
    TEST_CASE("four hundred two", 402);
    TEST_CASE("four hundred and fifty-three", 453);
    TEST_CASE("three thousand two hundred", 3200);
    TEST_CASE("three thousand two hundred and ten", 3210);
    TEST_CASE("seven hundred thousand", 700000);
    TEST_CASE("forty-three thousand one hundred twenty-five", 43125);
    TEST_CASE("two hundred million five hundred thousand two hundred and fifty-six", 200500256);
    TEST_CASE("six hundred and sixty-six million six hundred and sixty-six thousand six hundred and sixty-six", 666666666);
    TEST_CASE("nine hundred and ninety-nine million nine hundred and ninety-nine thousand nine hundred and ninety-nine", 999999999);
}