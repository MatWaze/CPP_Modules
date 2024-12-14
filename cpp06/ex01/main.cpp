#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data    d("meathead", 1);

    uintptr_t   dataSerialized = Serializer::serialize(&d);
    Data    *dataDeserialized = Serializer::deserialize(dataSerialized);

    std::cout << dataDeserialized->getId() << std::endl;
    std::cout << dataDeserialized->getVal() << std::endl;
}
