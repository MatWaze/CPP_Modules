#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &pardon) : AForm(pardon)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;

    this->_target = pardon._target;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
    std::cout << "RobotomyRequestForm target constructor called" << std::endl;

    this->_target = target;
}

RobotomyRequestForm  &RobotomyRequestForm::operator=(const RobotomyRequestForm &pardon)
{
    if (this != &pardon)
    {
        AForm::operator=(pardon);

        std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
        this->_target = pardon._target;
    }

    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}