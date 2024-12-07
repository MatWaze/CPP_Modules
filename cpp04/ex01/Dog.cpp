#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>
#include <new>

Dog::Dog()
{
    std::cout << "Default Dog constructor called" << std::endl;

    this->type = "Dog";
    try
    {
        this->_brain = new Brain();
    }
    catch (std::bad_alloc&)
    {
        std::cout << "Memory allocation failed" << std::endl;
    }
}

Dog::Dog(Dog& dog) : Animal(dog)
{
    std::cout << "Dog copy constructor called" << std::endl;

    this->type = "Dog";
    try
    {
        this->_brain = new Brain(*dog._brain);
    }
    catch (std::bad_alloc&)
    {
        std::cout << "Memory allocation failed" << std::endl;
    }
}

Dog&    Dog::operator=(Dog& dog)
{
    std::cout << "Dog assignment operator called" << std::endl;

    if (this != &dog)
    {
        try
        {
            delete this->_brain;
            this->_brain = new Brain(*dog._brain);
        }
        catch (std::bad_alloc&)
        {
            std::cout << "Memory allocation failed" << std::endl;
        }
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Default Dog destructor called" << std::endl;

    delete this->_brain;
}

void    Dog::makeSound() const
{
    std::cout << "Woooof" << std::endl;
}
