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
    
    // Call the function that prints
    harl.complain("info");

    // Get the captured output
    std::string output = oss.str();
    
    // Assert the expected output
    CHECK(output == "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n");
    
    // Restore the original stdout
    std::cout.rdbuf(oldBuf);
}
