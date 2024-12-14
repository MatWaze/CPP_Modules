#include "ScalarConverter.hpp"
#include "../../doctest.h"
#include <iostream>
#include <sstream>
#include <string>

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

    return os.str() == ans;
}

TEST_CASE("Testing convert")
{
    std::string s1 = "1";
    std::string e1;

    bool a = CHECK_OUTPUT(s1, "c", "1", "1f", "1");

    CHECK(a == true);
}

