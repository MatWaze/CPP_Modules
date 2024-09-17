#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main2( void )
{
    Point   p(1.0f, 1.0f);
    Point   a(1.0f, 1.0f);
    Point   b(1.0f, 1.0f);
    Point   c(1.0f, 1.0f);

    if (bsp(a, b, c, p) == true)
        std::cout << "Point is inside of a triangle." << std::endl;
    else
        std::cout << "Point is not inside of a triangle." << std::endl;
    return 0;
}

int main()
{
    main2();
    return 0;
}
