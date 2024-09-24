#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_val = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fix)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_val = fix._val;
}

Fixed& Fixed::operator=(const Fixed& fix)
{
    if (this != &fix)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->_val = fix._val;
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_val;
}

void Fixed::setRawBits(int const raw)
{
    this->_val = raw;
}
