#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    std::cout << "Default Animal constructor called" << std::endl;

    this->type = "Animal";
}

Animal::Animal(Animal& animal)
{
    std::cout << "Animal copy constructor called" << std::endl;

    this->type = animal.type;
}

Animal::~Animal()
{
    std::cout << "Default Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &animal)
    {
        this->type = animal.type;
    }
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
