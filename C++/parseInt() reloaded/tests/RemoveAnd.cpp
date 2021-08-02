#include "parse_int.h"
#include "TestUtil.h"

int main()
{
    TEST_CASE("two hundred and four", 204);
    TEST_CASE("one and and and", 1);
    TEST_CASE("and and two and and", 2);
    TEST_CASE("two and and and hundred", 200);
}
