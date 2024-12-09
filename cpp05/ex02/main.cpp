#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
    try
    {
        // Bureaucrat b(5, "Matevos");
        // Bureaucrat c(137, "Mat");
        // Bureaucrat d(45, "Ma");
        Bureaucrat e(45, "Ma");

        // PresidentialPardonForm  f("house");
        // RobotomyRequestForm  g("house");
        ShrubberyCreationForm  h("house");

        e.executeForm(h);
    }
    catch (std::exception &err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}
