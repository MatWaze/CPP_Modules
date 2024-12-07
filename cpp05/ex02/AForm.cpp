#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() 
    : _gradeExec(1), _gradeSign(1), _name("default form")
{
    std::cout << "AForm default constructor called" << std::endl;
    
    this->_isSigned = false;
}

AForm::~AForm()
{
    std::cout << "AForm default destructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec)
    : _gradeExec(gradeExec), _gradeSign(gradeSign), _name(name)
{
    std::cout << "AForm parameter constructor called" << std::endl;

    this->_isSigned = false;
    if (this->getGradeExec() < 1 || this->getGradeSign() < 1)
        throw AForm::GradeTooHighException();
    if (this->getGradeExec() > 150 || this->getGradeExec() > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm &f) 
    : _gradeExec(f.getGradeExec()), _gradeSign(f.getGradeSign()), _name(f.getFormName())
{
    std::cout << "AForm copy constructor called" << std::endl;

    if (this->getGradeExec() < 1 || this->getGradeSign() < 1)
        throw AForm::GradeTooHighException();
    if (this->getGradeExec() > 150 || this->getGradeExec() > 150)
        throw AForm::GradeTooLowException();

    this->_isSigned = f.getIsSigned();
}

AForm    &AForm::operator=(const AForm &f)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    
    if (this != &f)
    {
        this->_isSigned = f.getIsSigned();
    }
    return *this;
}

std::ostream    &operator<<(std::ostream &os, const AForm &f)
{
    os << f.getFormName() << ", execute grade " << f.getGradeExec()
    << ", sign grade " << f.getGradeSign() << ", is signed "
    << f.getIsSigned() << ".";

    return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high to sign the form";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low to sign the form";
}

void    AForm::beSigned(Bureaucrat &b)
{
    std::cout << "Trying to sign form" << std::endl;

    // if b's grade is lower than the grade to sign of the form
    if (b.getGrade() >= this->getGradeSign())
        throw AForm::GradeTooLowException();
    else
        this->_isSigned = true;
}

bool    AForm::getIsSigned() const
{
    return this->_isSigned;
}

std::string AForm::getFormName() const
{
    return this->_name;
}

int AForm::getGradeExec() const
{
    return this->_gradeExec;
}

int AForm::getGradeSign() const
{
    return this->_gradeSign;
}
