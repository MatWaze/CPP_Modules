#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/Users/matevos/CPP_Modules/doctest.h"
#include <cmath>
#include "Fixed.hpp"

TEST_CASE("Testing Fixed class methods")
{
    Fixed a = Fixed();
    Fixed b = Fixed(1);
    Fixed c = Fixed(12.4999f);
    Fixed d = Fixed(-123);
    Fixed e = Fixed(12.50001f);

    std::streambuf* oldBuf = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());
    std::cout << d;
    std::string out = oss.str();

    CHECK(out == "-123");
    std::cout.rdbuf(oldBuf);

    int aFix = a.getRawBits();
    int bInt = b.toInt();
    int cInt = c.toInt();
    float dFloat = d.toFloat();
    int eInt = e.toInt();

    CHECK(aFix == 0);
    CHECK(bInt == 1);
    CHECK(cInt == 12);
    CHECK(dFloat == -123.0);
    CHECK(eInt == 13);
}
