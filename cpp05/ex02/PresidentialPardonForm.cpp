#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
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

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) 
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

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() == this->getGradeExec())
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else if (executor.getGrade() < this->getGradeExec())
		throw AForm::GradeTooHighException();
	else
		throw AForm::GradeTooLowException();
}



