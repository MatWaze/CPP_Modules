#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <new>

Cat::Cat()
{
    std::cout << "Default Cat constructor called" << std::endl;

    this->type = "Cat";
    try
    {
        this->_brain = new Brain();
    }
    catch (std::bad_alloc&)
    {
        std::cout << "Memory allocation failed" << std::endl;
    }
}

Cat::Cat(Cat& cat) : Animal(cat)
{
    std::cout << "Cat copy constructor called" << std::endl;

    this->type = "Cat";
    try
    {
        this->_brain = new Brain(*cat._brain);
    }
    catch (std::bad_alloc&)
    {
        std::cout << "Memory allocation failed" << std::endl;
    }
}

Cat&    Cat::operator=(Cat& cat)
{
    std::cout << "Cat assignment operator called" << std::endl;

    if (this != &cat)
    {
        try
        {
            delete this->_brain;
            this->_brain = new Brain(*cat._brain);
        }
        catch (std::bad_alloc&)
        {
           std::cout << "Memory allocation failed" << std::endl;
        }
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Default Cat destructor called" << std::endl;

    delete this->_brain;
}

void    Cat::makeSound() const
{
    std::cout << "Meooooow" << std::endl;
}
