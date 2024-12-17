#ifndef MAX_HPP
# define MAX_HPP

template<typename T>
T&  max(T& first, T& second)
{
    if (first > second)
        return first;
    return second;
}

template<typename T>
const T&  max(const T& first, const T& second)
{
    if (first > second)
        return first;
    return second;
}

#endif