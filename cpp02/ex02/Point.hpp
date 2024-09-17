#include "Fixed.hpp"

class Point
{
    public:
        Point(); // default
        Point(const float xF, const float yF); // constructor 2
        ~Point(); // dest
        Point& operator=(const Point& point); // copy assignment
        Point(const Point& point); // copy constructor
        Fixed getX() const;
        Fixed getY() const;
    private:
        const Fixed _x;
        const Fixed _y;
};
