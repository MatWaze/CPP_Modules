#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "Fixed.hpp"

TEST_CASE("Testing Fixed class methods")
{
    Fixed a = Fixed();
    Fixed b = Fixed(1);
    Fixed c = Fixed(12.4899f);
    Fixed c2 = Fixed(12.49999f);
    Fixed d = Fixed(1234.4321f);
    Fixed e = Fixed(12.50001f);
    Fixed f = Fixed(8388607);
    Fixed g = Fixed(99.99f);
    Fixed h = Fixed(-12545);
    Fixed i = Fixed(-843.344f);
    Fixed large = Fixed(1e6f);
    Fixed small = Fixed(-12122.0f);

    std::streambuf* oldBuf = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());
    std::cout << d;
    std::string out = oss.str();

    CHECK(out == "1234.43");
    std::cout.rdbuf(oldBuf);

    CHECK_EQ(a.getRawBits(), 0);
    CHECK_EQ(a.toFloat(), 0.0f);
    CHECK_EQ(a.toInt(), 0);

    CHECK_EQ(b.getRawBits(), b.toInt() * 256);
    CHECK_EQ(b.toInt(), 1);
    CHECK_EQ(b.toFloat(), 1.0f);

    CHECK_EQ(c.getRawBits(), c.toFloat() * 256);
    CHECK_EQ(c.toInt(), 12);
    CHECK_EQ(c.toFloat(), doctest::Approx(12.4882f));
    CHECK_EQ(c2.toFloat(), 12.5f);

    CHECK_EQ(d.toInt(), 1234);
    CHECK_EQ(d.toFloat(), doctest::Approx(1234.43f));

    CHECK_EQ(e.toInt(), 12);
    CHECK_EQ(e.toFloat(), 12.5f);

    CHECK_EQ(g.toInt(), 99);
    CHECK_EQ(g.toFloat(), doctest::Approx(99.988f));

    CHECK_EQ(f.toFloat(), 8388607.0f);
    CHECK_EQ(f.toInt(), 8388607);

    CHECK_EQ(h.toInt(), -12545);
    CHECK_EQ(h.toFloat(), -12545.0);

    CHECK_EQ(i.toInt(), -843);
    CHECK_EQ(i.toFloat(), doctest::Approx(-843.34f));

    CHECK_EQ(large.toInt(), 1000000);
    CHECK(large.toFloat() == 1e6f);

    CHECK(small.toInt() == -12122);
    CHECK_EQ(small.toFloat(), -12122.0f);
}
