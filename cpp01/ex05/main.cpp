#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/Users/matevos/CPP_Modules/doctest.h"
#include "Harl.hpp"
#include <iostream>
#include <sstream>
#include <string>

// Test case using doctest
TEST_CASE("Testing Harl class methods")
{
	Harl harl = Harl();
    // Save the original stdout
    std::streambuf* oldBuf = std::cout.rdbuf();
    
    // Create a string stream to capture output
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());
    
    harl.complain("info");

    // Get the captured output
    std::string output = oss.str();

    CHECK(output == "[INFO]\n");

    // Restore the original stdout
    std::cout.rdbuf(oldBuf);
}
