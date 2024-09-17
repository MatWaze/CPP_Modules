#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _val;
        static const int _bits = 8;
    
    public:
        Fixed();
        Fixed(const int intNumber);
        Fixed(const float floatNumber);
        ~Fixed();
        Fixed(const Fixed& fix);
        Fixed& operator=(const Fixed& fix);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};


std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif
