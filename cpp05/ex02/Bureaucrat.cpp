#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat default destructor called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade can't be greater than 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade can't be less than 150";
}


Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{
    std::cout << "Bureaucrat grade and name contructor called" << std::endl;

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();

    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &b)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;

    this->_grade = b.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &b)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &b)
    {
        this->_grade = b.getGrade();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " 
    << b.getGrade() << ".";

    return os;
}

std::string    Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void    Bureaucrat::incrementGrade()
{
    std::cout << "Incrementing " << this->getName()
    << "'s grade" << std::endl;

    int newGrade = this->_grade - 1;

    if (newGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade = newGrade;
}

void    Bureaucrat::decrementGrade()
{
    std::cout << "Decreasing " << this->getName()
    << "'s grade" << std::endl;

    int newGrade = this->_grade + 1;

    if (newGrade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = newGrade;
}

void    Bureaucrat::signForm(AForm &f)
{
    if (f.getIsSigned())
        std::cout << this->getName() << " signed " << f.getFormName() << std::endl;
    else
        std::cout << this->getName() << " couldn't sign " << f.getFormName()
        << " because the grade is outside the boundaries" << std::endl;
}

void    Bureaucrat::executeForm(AForm &f) const
{
	try
	{
		f.execute(*this);
		std::cout << this->getName() << " executed " << f.getFormName() << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << "Can't execute the "
        << f.getFormName() << " form: " 
        << ex.what() << std::endl;
	}	
}

