#include "Form.hpp"
#include "ex01/Bureaucrat.hpp"
#include <iostream>

Form::Form() 
    : _gradeExec(1), _gradeSign(1), _name("default form")
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form default destructor called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec)
    : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    std::cout << "Form parameter constructor called" << std::endl;

    if (this->getGradeExec() < 1 || this->getGradeSign() < 1)
        throw Form::GradeTooHighException();
    if (this->getGradeExec() > 150 || this->getGradeExec() > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form &f) 
    : _gradeExec(f.getGradeExec()), _gradeSign(f.getGradeSign()), _name(f.getName())
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

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade can't be greater than 1";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade can't be less than 150";
}

void    Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= this->getGradeSign())
    {
        
    }
}