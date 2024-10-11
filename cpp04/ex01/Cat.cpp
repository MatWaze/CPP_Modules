#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : _brain(new Brain())
{
    this->type = "Cat";
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(Cat& cat) : Animal(cat), _brain(new Brain())
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat&    Cat::operator=(Cat& cat)
{
    if (this != &cat)
    {
        this->type = cat.type;
    }
    return *this;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Default Cat destructor called" << std::endl;
}

void    Cat::makeSound()
{
    std::cout << "Meooooow" << std::endl;
}
