#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0)
{
    std::cout << "Default Point constructor called" << std::endl;
}

Point::Point(const float xF, const float yF) : _x(xF), _y(yF)
{
    std::cout << "Point constructor called" << std::endl;
}

Point::~Point()
{
    std::cout << "Default Point destructor called" << std::endl;
}

Point::Point(const Point& point) : _x(point._x), _y(point._y)
{
    std::cout << "Point copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& point)
{
    std::cout << "Point copy assignment operator called" << std::endl;
    (void)point;
    return *this;
}

Fixed Point::getX() const
{
    return _x;
}

Fixed Point::getY() const
{
    return _y;
}
