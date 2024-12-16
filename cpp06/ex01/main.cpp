#include <cstdint>
#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data    d("meathead", 1);

    uintptr_t   dataSerialized = Serializer::serialize(&d);
    Data    *dataDeserialized = Serializer::deserialize(dataSerialized);

    // Not allowed - int is not a pointer type
    // int r = reinterpret_cast<int>(&d);
    
    // Allowed
    // long double *dub = reinterpret_cast<long double*>(&d);
    // Data    *fromDub = reinterpret_cast<Data*>(dub);
    // std::cout << fromDub->getVal() << std::endl;
    
    short *sh = reinterpret_cast<short*>(&d);
    Data    *fromSh = reinterpret_cast<Data*>(sh);
    std::cout << fromSh->getId() << std::endl;
    std::cout << fromSh->getVal() << std::endl;
    
    std::cout << dataDeserialized->getId() << std::endl;
    std::cout << dataDeserialized->getVal() << std::endl;
}
