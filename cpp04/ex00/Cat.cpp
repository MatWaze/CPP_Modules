#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(Cat& cat) : Animal(cat)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat&    Cat::operator=(const Cat& cat)
{
    if (this != &cat)
    {
        this->type = cat.type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Default Cat destructor called" << std::endl;
}

void    Cat::makeSound()
{
    std::cout << "Meooooow" << std::endl;
}
