#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sys/dirent.h>
#include <unistd.h>
#include <dirent.h>

ShrubberyCreationForm::ShrubberyCreationForm()
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

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
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

void    ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
    if (executor.getGrade() == 137)
    {
        std::string fileName = this->getTarget() + "_shrubbery";
        std::ofstream   createFile(fileName);

        if (createFile.is_open())
        {
            createFile << "              v .   ._, |_  ., \
           `-._\\/  .  \\ /    |/_ \
               \\  _\\, y | \\// \
         _\\_.___\\, \\/ -.\\|| \
           `7-,--.`._||  / / , \
           /'     `-. `./ / |/_.' \
                     |    |// \
                     |_    / \
                     |-   | \
                     |   =| \
                     |    | \
--------------------/ ,  . \\--------._" << std::endl;

            createFile.close();
        }
        else
            std::cout << "Unable to create " << fileName << std::endl;
    }
    else if (executor.getGrade() < 137)
        throw AForm::GradeTooHighException();
    else
        throw  AForm::GradeTooLowException();
}
