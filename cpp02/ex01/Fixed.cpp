#include "Fixed.hpp"
#include <cmath>

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

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
    os << fix.toFloat();
    return os;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_val;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_val = raw;
}

Fixed::Fixed(const int intNumber)
{
    std::cout << "Int constructor called" << std::endl;
    this->_val = intNumber * (1 << this->_bits);
}

Fixed::Fixed(const float floatNumber)
{
    std::cout << "Float constructor called" << std::endl;
    this->_val = roundf(floatNumber * (1 << this->_bits));
}

int Fixed::toInt(void) const
{
    return this->_val / (1 << this->_bits);
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_val) / (1 << this->_bits);
}
