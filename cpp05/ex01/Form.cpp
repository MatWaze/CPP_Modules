#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

Form::Form() 
    : _gradeExec(1), _gradeSign(1), _name("default form")
{
    std::cout << "Form default constructor called" << std::endl;
    
    this->_isSigned = false;
}

Form::~Form()
{
    std::cout << "Form default destructor called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec)
    : _gradeExec(gradeExec), _gradeSign(gradeSign), _name(name)
{
    std::cout << "Form parameter constructor called" << std::endl;

    this->_isSigned = false;
    if (this->getGradeExec() < 1 || this->getGradeSign() < 1)
        throw Form::GradeTooHighException();
    if (this->getGradeExec() > 150 || this->getGradeExec() > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form &f) 
    : _gradeExec(f.getGradeExec()), _gradeSign(f.getGradeSign()), _name(f.getFormName())
{
    std::cout << "Form copy constructor called" << std::endl;

    if (this->getGradeExec() < 1 || this->getGradeSign() < 1)
        throw Form::GradeTooHighException();
    if (this->getGradeExec() > 150 || this->getGradeExec() > 150)
        throw Form::GradeTooLowException();

    this->_isSigned = f.getIsSigned();
}

Form    &Form::operator=(const Form &f)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    
    if (this != &f)
    {
        this->_isSigned = f.getIsSigned();
    }
    return *this;
}

std::ostream    &operator<<(std::ostream &os, const Form &f)
{
    os << f.getFormName() << ", execute grade " << f.getGradeExec()
    << ", sign grade " << f.getGradeSign() << ", is signed "
    << f.getIsSigned() << ".";

    return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high to sign the form";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low to sign the form";
}

void    Form::beSigned(Bureaucrat &b)
{
    std::cout << "Trying to sign form" << std::endl;

    // if b's grade is lower than the grade to sign of the form
    if (b.getGrade() >= this->getGradeSign())
        throw Form::GradeTooLowException();
    else
        this->_isSigned = true;
}

bool    Form::getIsSigned() const
{
    return this->_isSigned;
}

std::string Form::getFormName() const
{
    return this->_name;
}

int Form::getGradeExec() const
{
    return this->_gradeExec;
}

int Form::getGradeSign() const
{
    return this->_gradeSign;
}
