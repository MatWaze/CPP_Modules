#include "Fixed.hpp"
#include <climits>
#include <cmath>

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
    this->_val = raw;
}

Fixed::Fixed(const int intNumber)
{
    std::cout << "Int constructor called" << std::endl;
    long int    longNum = (long int) intNumber;
    std::cout << longNum << "\n";
    if (longNum >= INT_MAX)
        this->_val = INT_MAX / 256;
    else if (longNum <= INT_MIN)
        this->_val = INT_MIN / 256;
    else
        this->_val = longNum * (1 << this->_bits);
}

Fixed::Fixed(const float floatNumber)
{
    std::cout << "Float constructor called" << std::endl;
    this->_val = floatNumber * (1 << this->_bits);
}

int Fixed::toInt(void) const
{
    return roundf(float(this->_val) / (1 << this->_bits));
}

float Fixed::toFloat(void) const
{
    return float(this->_val) / (1 << this->_bits);
}


