#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat& WrongCat) : WrongAnimal(WrongCat)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&    WrongCat::operator=(const WrongCat& WrongCat)
{
    if (this != &WrongCat)
    {
        this->type = WrongCat.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Default WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "Meooooow" << std::endl;
}
