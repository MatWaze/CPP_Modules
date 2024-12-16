#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    std::cout << "Fixed default constructor called" << std::endl;
    this->_val = 0;
}

Fixed::~Fixed()
{
    std::cout << "Fixed destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fix)
{
    std::cout << "Fixed copy constructor called" << std::endl;
    this->_val = fix._val;
}

Fixed& Fixed::operator=(const Fixed& fix)
{
    if (this != &fix)
    {
        std::cout << "Fixed copy assignment operator called" << std::endl;
        this->_val = fix._val;
    }
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_val;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_val = raw;
}
