#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(Dog& Dog) : Animal(Dog)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog&    Dog::operator=(const Dog& Dog)
{
    if (this != &Dog)
    {
        this->type = Dog.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Default Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Woooof" << std::endl;
}
