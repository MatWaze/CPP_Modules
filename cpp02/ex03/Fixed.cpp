#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default Fixed constructor called" << std::endl;
    this->_val = 0;
}

Fixed::~Fixed()
{
    std::cout << "Fixed Destructor called" << std::endl;
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

Fixed Fixed::operator+(const Fixed& fix)
{
    Fixed   n;

    n.setRawBits(static_cast<int64_t>(this->_val) + static_cast<int64_t>(fix._val));
    return n;
}

Fixed Fixed::operator-(const Fixed& fix)
{
    Fixed   n;

    n.setRawBits(static_cast<int64_t>(this->_val) - static_cast<int64_t>(fix._val));
    return n;
}

Fixed Fixed::operator*(const Fixed& fix)
{
    Fixed   n;

    n.setRawBits((static_cast<int64_t>(this->_val) * static_cast<int64_t>(fix._val)) >> this->_bits);
    return n;
}

Fixed Fixed::operator/(const Fixed& fix)
{
    Fixed   n;

    if (fix._val == 0)
        throw std::runtime_error("Division by zero");
    else
        n.setRawBits((static_cast<int64_t>(this->_val) << this->_bits) / (fix._val));
    return n;
}

Fixed& Fixed::operator++(void)
{
    ++(this->_val);
    return *this;
}

Fixed& Fixed::operator--(void)
{
    --(this->_val);
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(this->_val);
    return temp; 
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(this->_val);
    return temp;
}

bool Fixed::operator>(const Fixed& fix) const
{
    return _val > fix._val;
}

bool Fixed::operator<(const Fixed& fix) const
{
    return _val < fix._val;
}

bool Fixed::operator>=(const Fixed& fix) const
{
    return _val >= fix._val;
}

bool Fixed::operator<=(const Fixed& fix) const
{
    return _val <= fix._val;
}

bool Fixed::operator==(const Fixed& fix) const
{
    return _val == fix._val;
}

bool Fixed::operator!=(const Fixed& fix) const
{
    return !(Fixed::operator==(fix));
}

Fixed& Fixed::min(Fixed& first, Fixed&second)
{
    if (first._val <= second._val)
        return first;
    return second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed&second)
{
    if (first._val <= second._val)
        return first;
    return second;
}

Fixed& Fixed::max(Fixed& first, Fixed&second)
{
    if (first._val >= second._val)
        return first;
    return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed&second)
{
    if (first._val >= second._val)
        return first;
    return second;
}
