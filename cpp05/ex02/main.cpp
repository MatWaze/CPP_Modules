#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b(150, "Mat");
        PresidentialPardonForm  f("house");

        PresidentialPardonForm  f2 = f;
        
        std::cout << f2.getTarget() << std::endl;
        std::cout << f.getTarget() << std::endl;
        // f.beSigned(b);
        std::cout << b << std::endl;
    }
    catch (std::exception &err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}