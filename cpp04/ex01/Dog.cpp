#include "Dog.hpp"
#include <iostream>

Dog::Dog() : _brain(new Brain())
{
    this->type = "Dog";
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(Dog& Dog) : Animal(Dog), _brain(new Brain())
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog&    Dog::operator=(Dog& Dog)
{
    if (this != &Dog)
    {
        this->type = Dog.type;
    }
    return *this;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Default Dog destructor called" << std::endl;
}

void    Dog::makeSound()
{
    std::cout << "Woooof" << std::endl;
}
