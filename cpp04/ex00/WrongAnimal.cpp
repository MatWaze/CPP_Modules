#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
    this->type = "WrongAnimal";
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& WrongAnimal)
{
    this->type = WrongAnimal.type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Default WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WrongAnimal)
{
    if (this != &WrongAnimal)
    {
        this->type = WrongAnimal.type;
    }
    std::cout << "WrongAnimal copy assignment called" << std::endl;
    return *this;
}

std::string WrongAnimal::getType()
{
    return this->type;
}

void    WrongAnimal::makeSound()
{
    std::cout << "*unknown WrongAnimal sound*" << std::endl;
}
