#include "Fixed.hpp"
#include "Point.hpp"

float getCP(Point u, Point v)
{
    float ans;

    ans = u.getX().toFloat() * v.getY().toFloat() - u.getY().toFloat() * v.getX().toFloat();
    return ans;
}

bool    crossProduct(Point const a, Point const b, Point const c, Point const p)
{
    float   abX = b.getX().toFloat() - a.getX().toFloat();
    float   abY = b.getY().toFloat() - a.getY().toFloat();

    float   bcX = c.getX().toFloat() - b.getX().toFloat();
    float   bcY = c.getY().toFloat() - b.getY().toFloat();

    float   caX = a.getX().toFloat() - c.getX().toFloat();
    float   caY = a.getY().toFloat() - c.getY().toFloat();

    Point   ab(abX, abY);
    Point   bc(bcX, bcY);
    Point   ca(caX, caY);
    
    float   apX = p.getX().toFloat() - a.getX().toFloat();
    float   apY = p.getY().toFloat() - a.getY().toFloat();
    
    float   bpX = p.getX().toFloat() - b.getX().toFloat();
    float   bpY = p.getY().toFloat() - b.getY().toFloat();
    
    float   cpX = p.getX().toFloat() - c.getX().toFloat();
    float   cpY = p.getY().toFloat() - c.getY().toFloat();
    
    Point   ap(apX, apY);
    Point   bp(bpX, bpY);
    Point   cp(cpX, cpY);

    float   abAP = getCP(ab, ap);
    float   bcBP = getCP(bc, bp);
    float   caCP = getCP(ca, cp);

    bool    ans;

    ans = (abAP > 0 && bcBP > 0 && caCP > 0) || (abAP < 0 && bcBP < 0 && caCP < 0);
    return ans;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    bool    ans = crossProduct(a, b, c, point);
    return ans;
}
