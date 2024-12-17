#ifndef SWAP_HPP
# define SWAP_HPP

template<typename T>
void    swap(T& first, T& second)
{
    T  tmp = first;
    first = second;
    second = tmp;
}

#endif