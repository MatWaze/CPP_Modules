#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string s = argv[1];
        ScalarConverter::convert(s);
        return 0;
    }
    std::cout << "Expected one argument: string literal" << std::endl;
    return 1;
}