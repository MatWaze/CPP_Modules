#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/Users/mamazari/Desktop/42-cursus/CPP_Modules/doctest.h"
#include "Fixed.hpp"

TEST_CASE("Testing Fixed class methods and operators")
{
    Fixed a = Fixed();
    Fixed b = Fixed(1);
    Fixed c = Fixed(12.4999f);
    Fixed d = Fixed(-123);
    Fixed e = Fixed(12.50001f);
    Fixed f = Fixed(3.0f);
    Fixed g = Fixed(2.0f);

    // Output stream test
    std::streambuf* oldBuf = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());
    std::cout << d;
    std::string out = oss.str();
    CHECK(out == "-123");
    std::cout.rdbuf(oldBuf);

    // Test getRawBits and conversion methods
    CHECK(a.getRawBits() == 0);
    CHECK(b.toInt() == 1);
    CHECK(c.toInt() == 12);
    CHECK(d.toFloat() == -123.0f);
    CHECK(e.toInt() == 13);

    // Test addition operator
    Fixed sum = b + f; // 1 + 3
    CHECK(sum.toInt() == 4);

    // Test subtraction operator
    Fixed diff = f - g; // 3 - 2
    CHECK(diff.toFloat() == 1.0f);

    // Test multiplication operator
    CHECK(f.toFloat() == 3.0f);
    
    Fixed prod = Fixed(4) * g; // 3 * 2
    CHECK(prod.toInt() == 8);

    // Test division operator
    Fixed div = f / g; // 3 / 2
    CHECK(div.toFloat() == 1.5f);

    // Test comparison operators
    CHECK(b < f);    // 1 < 3
    CHECK(f > g);    // 3 > 2
    CHECK(c <= e);   // 12.4999 <= 12.50001
    CHECK(d >= Fixed(-123)); // -123 >= -123
    CHECK(b == Fixed(1)); // 1 == 1
    CHECK(b != g); // 1 != 2

    // Test mixed operations
    Fixed mixed = (b + f) * g; // (1 + 3) * 2
    CHECK(mixed.toFloat() == 8.0f);

    Fixed large = Fixed(1e6f);
    Fixed small = Fixed(1e-6f);
    
    // Test large number conversion
    CHECK(large.toInt() == 1000000);
    CHECK(large.toFloat() == 1e6f);
    
    // Test small number conversion
    CHECK(small.toInt() == 0);
    CHECK(small.toFloat() == 1e-6f);
    
    // Test zero division case
    CHECK_THROWS_AS(f / Fixed(0), std::runtime_error);
}
