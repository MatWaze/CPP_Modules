#include "Serializer.hpp"
#include "Data.hpp"

uintptr_t    Serializer::serialize(Data *ptr)
{
    uintptr_t   ans = reinterpret_cast<uintptr_t>(ptr);

    return ans;
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data    *ans = reinterpret_cast<Data*>(raw);

    return ans;
}