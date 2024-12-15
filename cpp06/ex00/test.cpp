#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <string>

bool  CHECK_OUTPUT_INVALID(
    std::string str
)
{
    std::streambuf* oldBuf = std::cout.rdbuf();
    
    std::ostringstream os;
    std::cout.rdbuf(os.rdbuf());

    ScalarConverter::convert(str);

    std::cout.rdbuf(oldBuf);

    std::string ans = "str is invalid\n";

    return os.str() == ans;
}

bool  CHECK_OUTPUT(
    std::string str,
    std::string ch,
    std::string in,
    std::string fl,
    std::string db
)
{
    std::streambuf* oldBuf = std::cout.rdbuf();
    std::ostringstream os;
    std::cout.rdbuf(os.rdbuf());

    ScalarConverter::convert(str);

    std::cout.rdbuf(oldBuf);

    std::string ans = "char: " + ch + "\n" \
    + "int: " + in + "\n" \
    + "float: " + fl + "\n" \
    + "double: " + db + "\n";
    
    std::cout << os.str() << std::endl;

    return os.str() == ans;
}

TEST_CASE("Testing char convert")
{
    CHECK(CHECK_OUTPUT("c", "c", "99", "99.0f", "99.0"));
    
    CHECK(CHECK_OUTPUT("A", "A", "65", "65.0f", "65.0"));
    
    CHECK(CHECK_OUTPUT("C", "C", "67", "67.0f", "67.0"));
    
    CHECK(CHECK_OUTPUT("~", "~", "126", "126.0f", "126.0"));
    
    CHECK(CHECK_OUTPUT("!", "!", "33", "33.0f", "33.0"));
    
    CHECK(CHECK_OUTPUT("Z", "Z", "90", "90.0f", "90.0"));
    
    CHECK(CHECK_OUTPUT("/", "/", "47", "47.0f", "47.0"));
    
    CHECK(CHECK_OUTPUT("\n", "Non displayable", "10", "10.0f", "10.0"));

    CHECK(CHECK_OUTPUT_INVALID("Î"));

    CHECK(CHECK_OUTPUT_INVALID("FDJFDJFDJDF"));

    CHECK(CHECK_OUTPUT_INVALID("\\\\"));
}

TEST_CASE("Testing int convert")
{
    CHECK(CHECK_OUTPUT("1", "Non displayable", "1", "1.0f", "1.0"));
    
    CHECK(CHECK_OUTPUT("65", "A", "65", "65.0f", "65.0"));
    
    CHECK(CHECK_OUTPUT("126", "~", "126", "126.0f", "126.0"));

    CHECK(CHECK_OUTPUT("2147483647", "impossible", "2147483647", "2.14748e+09f", "2.14748e+09"));
    
    CHECK(CHECK_OUTPUT("-2147483647", "impossible", "-2147483647", "-2.14748e+09f", "-2.14748e+09"));
    
    CHECK(CHECK_OUTPUT("-2147483648", "impossible", "-2147483648", "-2.14748e+09f", "-2.14748e+09"));
    
    CHECK(CHECK_OUTPUT("127", "impossible", "127", "127.0f", "127.0"));
    
    CHECK(CHECK_OUTPUT("0", "Non displayable", "0", "0.0f", "0.0"));
    
    CHECK(CHECK_OUTPUT("+0", "Non displayable", "0", "0.0f", "0.0"));
    
    CHECK(CHECK_OUTPUT("-0", "Non displayable", "0", "0.0f", "0.0"));
    
    CHECK(CHECK_OUTPUT("-14343", "impossible", "-14343", "-14343.0f", "-14343.0"));
    
    CHECK(CHECK_OUTPUT("+5433", "impossible", "5433", "5433.0f", "5433.0"));
    
    CHECK(CHECK_OUTPUT("10000", "impossible", "10000", "10000.0f", "10000.0"));
    
    CHECK(CHECK_OUTPUT("97", "a", "97", "97.0f", "97.0"));
    
    CHECK(CHECK_OUTPUT("32", "Non displayable", "32", "32.0f", "32.0"));
    
    CHECK(CHECK_OUTPUT("33", "!", "33", "33.0f", "33.0"));
    
    CHECK(CHECK_OUTPUT_INVALID("2147483648"));

    CHECK(CHECK_OUTPUT_INVALID("-2147483649"));

    CHECK(CHECK_OUTPUT_INVALID("-+0"));

    CHECK(CHECK_OUTPUT_INVALID("45548458548596599569659569655954954545434040304304305454585485858854"));
    
    CHECK(CHECK_OUTPUT_INVALID("-45548458548596599569659569655954954545434040304304305454585485858854"));
    
    CHECK(CHECK_OUTPUT_INVALID("--234343"));
}

TEST_CASE("Test float convert")
{
    CHECK(CHECK_OUTPUT("3.f", "Non displayable", "3", "3f", "3"));
}