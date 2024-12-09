#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

bool RobotomyRequestForm::_isSeeded = false;

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
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

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
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

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() == this->getGradeExec())
	{
        if (!_isSeeded)
        {
            // need to seed to avoid the same value being 
            // generated after reruning the program
            srand(time(NULL));
            _isSeeded = true;
        }

		int isRobotomized = rand() % 2;

		if (isRobotomized)
			std::cout << this->getTarget() << " has been successfully robotomized" << std::endl;
		else	
			std::cout << this->getTarget() << "'s robotomy has failed" << std::endl;
	}
	else if (executor.getGrade() < this->getGradeExec())
		throw AForm::GradeTooHighException();
	else
		throw AForm::GradeTooLowException();
}

