#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <dirent.h>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &pardon) : AForm(pardon)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;

    this->_target = pardon._target;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm target constructor called" << std::endl;

    this->_target = target;
}

ShrubberyCreationForm  &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &pardon)
{
    if (this != &pardon)
    {
        AForm::operator=(pardon);

        std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
        this->_target = pardon._target;
    }

    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() == this->getGradeExec())
    {
        std::string fileName = this->getTarget() + "_shrubbery";
        std::ofstream   createFile(fileName.c_str());

        if (createFile.is_open())
        {
	    std::cout << "Writing tree to " << fileName << std::endl;

            createFile << "              v .   ._, |_  ., \n\
           `-._\\/  .  \\ /    |/_ \n\
               \\  _\\, y | \\// \n\
         _\\_.___\\, \\/ -.\\|| \\ \n\
           `7-,--.`._||  / / , \\ \n\
           /'     `-. `./ / |/_.' \\ \n\
                     |    |// \\ \n\
                     |_    / \\ \n\
                     |-   | \\ \n\
                     |   =| \\ \n\
                     |    | \\ \n\
--------------------/ ,  . \\--------._" << std::endl;

            createFile.close();
        }
        else
            std::cout << "Unable to create " << fileName << std::endl;
    }
    else if (executor.getGrade() < this->getGradeExec())
        throw AForm::GradeTooHighException();
    else
        throw  AForm::GradeTooLowException();
}
