#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "Fixed.hpp"

TEST_CASE("Testing Fixed class")
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    Fixed d = b;

    SUBCASE("Checking raw bits value")
    {
        CHECK_EQ(a.getRawBits(), 0);
        CHECK_EQ(b.getRawBits(), 0);
        CHECK_EQ(c.getRawBits(), 0);
        CHECK_EQ(d.getRawBits(), 0);
    }

    SUBCASE("Checking setRawBits method")
    {
        a.setRawBits(5);
        b.setRawBits(1);
        c.setRawBits(4);
        d.setRawBits(5);

        CHECK_EQ(a.getRawBits(), 5);
        CHECK_EQ(b.getRawBits(), 1);
        CHECK_EQ(c.getRawBits(), 4);
        CHECK_EQ(d.getRawBits(), 5);

        Fixed   e;
        e.setRawBits(8);
        Fixed   f = e;
        Fixed   g;
        g = e;
        CHECK_EQ(g.getRawBits(), f.getRawBits());
        CHECK_EQ(g.getRawBits(), 8);
        CHECK_EQ(f.getRawBits(), 8);
        CHECK_EQ(e.getRawBits(), 8);
    }
}
