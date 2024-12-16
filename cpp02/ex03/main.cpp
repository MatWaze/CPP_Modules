#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

TEST_CASE("Testing Point class")
{
    Point   a;
    Point   b(4.5f, 5.6f);
    Point   c(b);

    CHECK_EQ(a.getX(), 0);
    CHECK_EQ(a.getY(), 0);

    CHECK_EQ(b.getX(), 4.5f);
    CHECK_EQ(b.getY(), 5.6f);

    CHECK(b.getX() == c.getX());
    CHECK(b.getY() == c.getY());

    c = a;
    CHECK_EQ(c.getX(), 4.5f);
    CHECK_EQ(c.getY(), 5.6f);
}

TEST_CASE("Testing bsp function")
{
    Point a0(0.0f, 0.0f);
    Point b0(5.0f, 0.0f);
    Point c0(2.5f, 5.0f);
    Point p0(2.5f, 2.0f); // Inside

    Point a1(1.0f, 1.0f);
    Point b1(4.0f, 1.0f);
    Point c1(2.0f, 3.0f);
    Point p1(3.0f, 1.5f); // Inside

    Point a2(-1.0f, -1.0f);
    Point b2(1.0f, -1.0f);
    Point c2(0.0f, 1.0f);
    Point p2(0.0f, 0.0f); // Inside

    Point a3(1.0f, 2.0f);
    Point b3(4.0f, 2.0f);
    Point c3(2.5f, 5.0f);
    Point p3(3.5f, 4.0f); // Inside

    Point a4(0.0f, 0.0f);
    Point b4(3.0f, 0.0f);
    Point c4(1.5f, 3.0f);
    Point p4(2.0f, 1.0f); // Outside

    Point a5(0.0f, 0.0f);
    Point b5(4.0f, 0.0f);
    Point c5(2.0f, 4.0f);
    Point p5(5.0f, 2.0f); // Outside
    
    Point a6(1.0f, 1.0f);
    Point b6(3.0f, 1.0f);
    Point c6(2.0f, 4.0f);
    Point p6(2.0f, 2.5f); // Inside
    
    Point a7(0.0f, 0.0f);
    Point b7(3.0f, 0.0f);
    Point c7(1.5f, 2.0f);
    Point p7(3.5f, 1.0f); // Outside
    
    Point a8(1.0f, 1.0f);
    Point b8(6.0f, 1.0f);
    Point c8(3.5f, 5.0f);
    Point p8(4.0f, 3.0f); // Inside

    Point a9(0.0f, 0.0f);
    Point b9(2.0f, 0.0f);
    Point c9(1.0f, 2.0f);
    Point p9(1.5f, 0.5f); // Inside

    Point a10(0.0f, 0.0f);
    Point b10(0.0f, 0.0f);
    Point c10(0.0f, 0.0f);
    Point p10(0.0f, 0.0f); // Not inside

    Point a11(1.0f, 1.0f);
    Point b11(5.0f, 1.0f);
    Point c11(3.0f, 4.0f);
    Point p11(3.0f, 1.0f); // On the edge

    CHECK_EQ(bsp(a0, b0, c0, p0), true);
    CHECK_EQ(bsp(a1, b1, c1, p1), true);
    CHECK_EQ(bsp(a2, b2, c2, p2), true);
    CHECK_EQ(bsp(a3, b3, c3, p3), false);
    CHECK_EQ(bsp(a4, b4, c4, p4), true);
    CHECK_EQ(bsp(a5, b5, c5, p5), false);
    CHECK_EQ(bsp(a6, b6, c6, p6), true);
    CHECK_EQ(bsp(a7, b7, c7, p7), false);
    CHECK_EQ(bsp(a8, b8, c8, p8), true);
    CHECK_EQ(bsp(a9, b9, c9, p9), true);
    CHECK_EQ(bsp(a10, b10, c10, p10), false);
    CHECK_EQ(bsp(a11, b11, c11, p11), false);
}
