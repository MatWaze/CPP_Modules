#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
        int _val;
        static const int _bits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& fix);
        Fixed& operator=(const Fixed& fix);
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif
