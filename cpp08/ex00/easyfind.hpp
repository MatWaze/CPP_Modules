#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>

template<typename T>
typename T::iterator  easyfind(T& container, int toFind)
{
    // The typename is needed to inform the compiler 
    // that iterator is supposed to be a type
    // and not a value of some type
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);

    if (it != container.end())
        return it;
    throw std::exception();
}

#endif