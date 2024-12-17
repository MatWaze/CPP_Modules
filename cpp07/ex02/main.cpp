#include "Array.tpp"
#include "../../doctest.h"
#include <exception>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

TEST_CASE("Testing Array")
{
    Array<int>  *arr1 = new Array<int>;
    Array<int>  arr2(4);
    Array<int>  arr3(2);

    CHECK(arr3[0] == arr3[1] == 0);

    for (int i = 0; i < 4; i++)
        arr2[i] = i * 2;

    arr3 = arr2;
    Array<int>  arr4 = arr3;

    CHECK_EQ(arr1->size(), 0);
    CHECK(arr2.size() == arr3.size() == arr4.size() == 4);

    CHECK_EQ(arr2[1], 2);

    arr2[1] = 4;

    CHECK_EQ(arr2[1], 4);
    CHECK_NE(arr3[1], 4);
    CHECK_NE(arr4[1], 4);

    CHECK_THROWS_AS(arr2[13], std::exception);

}