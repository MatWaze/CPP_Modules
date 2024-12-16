#include <stdexcept>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "Fixed.hpp"

TEST_CASE("Testing Fixed class methods and operators")
{
    Fixed a = Fixed();
    Fixed b = Fixed(1);
    Fixed c = Fixed(12.5001f);
    Fixed d = Fixed(-123);
    Fixed e = Fixed(1234.4321f );
    Fixed f = Fixed(3.0f);
    Fixed g = Fixed(2.0f);
    Fixed sum = b + f;
    Fixed sum2 = b + c;
    Fixed diff = f - g;
    Fixed prod = Fixed(4) * g;
    Fixed div = f / g;
    Fixed almostEqual1 = Fixed(2.45555f);
    Fixed almostEqual2 = Fixed(2.46555f);
    Fixed equal1 = Fixed(2334.45f);
    Fixed equal2 = Fixed(2334.45f);
    Fixed mixed = (b + f) * g;
    Fixed large = Fixed(1e6f);
    Fixed small = Fixed(-12122.0f);
    Fixed bigger = Fixed(12334);
    Fixed smaller = Fixed(12333);

    const Fixed biggerConst = Fixed(-838859);
    const Fixed smallerConst = Fixed(-838861);

    CHECK(sum.toInt() == 4);
    CHECK_EQ(sum2, 13.5f);
    CHECK(diff.toFloat() == 1.0f);
    CHECK(prod.toInt() == 8);
    CHECK(div.toFloat() == 1.5f);
    CHECK_EQ(mixed.toFloat(), 8.0f);

    CHECK_EQ(almostEqual1 != almostEqual2, true);
    CHECK_EQ(equal1 == equal2, true);
    CHECK(b < f);
    CHECK(f > g);
    CHECK(c < e);
    CHECK(d >= Fixed(-123));
    CHECK(b == Fixed(1));
    CHECK(b != g);

    CHECK_EQ(
        Fixed::max(bigger,smaller),
        bigger
    );
    CHECK_EQ(
        Fixed::min(bigger, smaller),
        smaller
    );
    CHECK_EQ(
        Fixed::max(biggerConst, smallerConst),
        biggerConst
    );
    CHECK_EQ(
        Fixed::min(biggerConst, smallerConst),
        smallerConst
    );

    ++a;
    CHECK_EQ(a++.toFloat(), 0.00390625f);
    CHECK_EQ(a.toFloat(), 0.0078125f);
    --a;
    CHECK_EQ(a--.toFloat(), 0.00390625f);
    CHECK_EQ(a.toFloat(), 0.0f);

    CHECK_THROWS_AS(Fixed(5) / Fixed(0), std::runtime_error);
}
