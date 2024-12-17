#include "min.hpp"
#include "max.hpp"
#include "swap.hpp"
#include <iostream>

class Awesome
{
public:
Awesome(void) : _n(0) {}
Awesome( int n ) : _n( n ) {}
Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
int get_n() const { return _n; }
private:
int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main()
{
    int a = ::min(3, 5);
    int b = ::max(3, 5);

    std::string x = "hi";
    std::string y = "aloha";
    ::swap(x, y);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    const std::string s = "d";
    const std::string w = "d";

    ::max(s, w);

    Awesome r(2), z(4);
    ::swap(r, z);
    std::cout << r << " " << z << std::endl;
    std::cout << max(r, z) << std::endl;
}