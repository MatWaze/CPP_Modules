#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b(150, "Mat");
        Form    f("super form", 120, 122);
        
        f.beSigned(b);
        std::cout << b << std::endl;
    }
    catch (std::exception &err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}