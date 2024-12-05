#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b(150, "Mat");
        std::cout << b << std::endl;
    }
    catch (std::exception &err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}