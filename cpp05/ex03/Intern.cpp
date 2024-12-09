#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern default destructor called" << std::endl;
}

Intern::Intern(Intern &i)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void) i;
}

Intern  &Intern::operator=(const Intern &i)
{
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void) i;

    return *this;
}

AForm   *Intern::makeForm(std::string formName, std::string formTarget)
{
    std::string formNames[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};

    AForm   *(Intern::*formFunctions[3])(std::string) = {&Intern::createShrubbery, &Intern::createPardon, &Intern::createRobotomy};

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formFunctions[i])(formTarget);
        }
    }
    std::cout << formName << " isn't valid form" << std::endl;

    return NULL;
}

AForm   *Intern::createShrubbery(std::string formTarget)
{
    AForm   *shrub = new ShrubberyCreationForm(formTarget);

    return shrub;
}

AForm   *Intern::createRobotomy(std::string formTarget)
{
    AForm   *robo = new RobotomyRequestForm(formTarget);

    return robo;
}

AForm   *Intern::createPardon(std::string formTarget)
{
    AForm   *pardon = new PresidentialPardonForm(formTarget);

    return pardon;
}
