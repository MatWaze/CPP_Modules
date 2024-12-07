#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(Animal& animal)
{
    this->type = animal.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Default Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
    if (this != &animal)
    {
        this->type = animal.type;
    }
    std::cout << "Animal copy assignment called" << std::endl;
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}

void    Animal::makeSound() const
{
    std::cout << "*unknown animal sound*" << std::endl;
}
