#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float xF, const float yF) : _x(xF), _y(yF) {}

Point::~Point() {}

Point::Point(const Point& point) : _x(point._x), _y(point._y) {}

Point& Point::operator=(const Point& point)
{
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
