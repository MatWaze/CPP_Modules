#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "Span.hpp"
#include <vector>

// int main(int, char **)
// {
//     Span    s(5);
//     std::vector<int> v;

//     v.push_back(1); 
//     v.push_back(2); 
//     v.push_back(3); 
//     v.push_back(4);
//     v.push_back(4);

//     s.addRange(v.begin(), v.end());

//     return 0;
// }
TEST_CASE("Span test")
{
    Span    sp(4);
    Span    sp2;

    sp.addNumber(10);
    sp.addNumber(20);
    sp.addNumber(30);
    sp.addNumber(100);

    sp2 = sp;
    Span    sp3 = sp;

    CHECK_EQ(sp.getSize(), 4);
    CHECK_EQ(sp2.getSize(), 4);
    CHECK_EQ(sp3.getSize(), 4);

    CHECK_EQ(sp.longestSpan(), 100 - 10);
    CHECK_EQ(sp.shortestSpan(), 100 - 30);

    CHECK_THROWS_MESSAGE(sp.addNumber(343),
        "The span is full");

    Span    s;
    Span    s2;

    CHECK_THROWS_MESSAGE(s.addNumber(1),
        "The span is full");

    CHECK_THROWS_MESSAGE(s.longestSpan(),
        "The span has less than 2 elements");

    CHECK_THROWS_MESSAGE(s.shortestSpan(),
        "The span has less than 2 elements");

    CHECK_THROWS_MESSAGE(s2.longestSpan(),
        "The span has less than 2 elements");

    CHECK_THROWS_MESSAGE(s2.shortestSpan(),
        "The span has less than 2 elements");
}