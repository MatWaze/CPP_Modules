#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &pardon) : AForm(pardon)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;

    this->_target = pardon._target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
    std::cout << "PresidentialPardonForm target constructor called" << std::endl;

    this->_target = target;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &pardon)
{
    if (this != &pardon)
    {
        AForm::operator=(pardon);

        std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
        this->_target = pardon._target;
    }

    return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->_target;
}