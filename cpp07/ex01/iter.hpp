#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void    iter(T *address, int length, void (func)(T&))
{
    for (int i = 0; i < length; i++)
        func(address[i]);
}
template<typename T>
void    iter(T const *address, int length, void (func)(T const &))
{
    for (int i = 0; i < length; i++)
        func(address[i]);
}


#endif