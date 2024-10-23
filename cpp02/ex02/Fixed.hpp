#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int32_t _val;
        static const int _bits = 8;
    
    public:
        Fixed();
        Fixed(const int intNumber);
        Fixed(const float floatNumber);
        ~Fixed();
        Fixed(const Fixed& fix);
        Fixed& operator=(const Fixed& fix);
        Fixed operator+(const Fixed& fix);
        Fixed operator-(const Fixed& fix);
        Fixed operator*(const Fixed& fix);
        Fixed operator/(const Fixed& fix);
        Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
        bool operator>(const Fixed&fix) const;
        bool operator<(const Fixed&fix) const;
        bool operator>=(const Fixed&fix) const;
        bool operator<=(const Fixed&fix) const;
        bool operator==(const Fixed&fix) const;
        bool operator!=(const Fixed&fix) const;
        int getRawBits(void) const;
        void setRawBits(const int raw);
        float toFloat(void) const;
        int toInt(void) const;
        static Fixed& min(Fixed& first, Fixed&second);
        static const Fixed& min(const Fixed& first, const Fixed&second);
        static Fixed& max(Fixed& first, Fixed&second);
        static const Fixed& max(const Fixed& first, const Fixed&second);
};


std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif
