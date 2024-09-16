#include <iostream>
#include "Fixed.hpp"

int main2( void )
{
    Fixed a(20.01f);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << a.toInt() << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

int main()
{
    main2();
    return 0;
}
