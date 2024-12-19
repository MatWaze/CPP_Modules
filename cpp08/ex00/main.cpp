#include <deque>
#include <exception>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "easyfind.hpp"
#include <list>
#include <vector>

TEST_CASE("easyfind with vector")
{
    std::vector<int> v;
    CHECK_THROWS_AS(::easyfind(v,-4), std::exception);
    
    v.push_back(1);
    v.push_back(34);
    v.push_back(5);

    std::vector<int>::iterator it = ::easyfind(v, 34);

    CHECK_EQ(*it, 34);
    CHECK_THROWS_AS(::easyfind(v, 244), std::exception);
}

TEST_CASE("easyfind with list")
{
    std::list<int>  lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(-1);
    lst.push_front(1233);
    lst.push_front(0);

    std::list<int>::iterator    it = ::easyfind(lst, 1);
    std::list<int>::iterator    it2 = ::easyfind(lst, 1233);

    CHECK_EQ(*it, 1);
    CHECK_EQ(*it2, 1233);

    CHECK_THROWS_AS(::easyfind(lst, 243434), std::exception);
    CHECK_THROWS_AS(::easyfind(lst, -2), std::exception);
}

TEST_CASE("easyfind with deque")
{
    std::deque<int> dq;
    dq.push_back(1);
    dq.push_back(132);
    dq.push_back(-32);
    dq.push_back(0);

    std::deque<int>::iterator    it = ::easyfind(dq, 1);
    std::deque<int>::iterator    it2 = ::easyfind(dq, 132);

    CHECK_EQ(*it, 1);
    CHECK_EQ(*it2, 132);

    CHECK_THROWS_AS(::easyfind(dq, 243434), std::exception);
    CHECK_THROWS_AS(::easyfind(dq, -2), std::exception);
}
