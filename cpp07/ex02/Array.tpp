#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"
#include <iostream>

template<class T>
Array<T>::Array() 
{
    std::cout << "Array default constructor called" << std::endl;
    _container = 0;
    _size = 0;
}

template<class T>
Array<T>::~Array()
{
    std::cout << "Array destructor called" << std::endl;

    delete[] _container;
}

template<class T>
Array<T>::Array(unsigned int n)
{
    std::cout << "Array parameter constructor called" << std::endl;

    // init container with default values
    _container = new T[n]();
    _size = n;
}

template<class T>
Array<T>::Array(const Array& ar)
{
    std::cout << "Array copy constructor called" << std::endl;

    _container = new T[ar._size];
    _size = ar._size;

    for (int i = 0; i < _size; i++)
        _container[i] = ar._container[i];
}

template<class T>
T&  Array<T>::operator=(const Array &ar)
{
    if (this != &ar)
    {
        // first allocate temporary array
        // then delete the old one
        // and assign to it the temp
        T   *temp = new T[ar._size];

        for (int i = 0; i < _size; i++)
            temp[i] = ar._container[i];
        
        delete[] _container;
        _size = ar._size;
        _container = temp;
    }
    return *this;
}

template<class T>
T&  Array<T>::operator[](int i)
{
    if (i >= _size || i < 0)
        throw std::exception();
    return _container[i];
}

template<class T>
const T&  Array<T>::operator[](int i) const
{
    if (i >= _size || i < 0)
        throw std::exception();
    return _container[i];
}

template<class T>
int Array<T>::size() const
{
    return _size;
}

#endif