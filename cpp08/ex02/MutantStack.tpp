#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"
#include <iostream>

// Iterator

template<typename T>
Iterator<T>::Iterator()
{
    this->_dq = NULL;
}

template<typename T>
Iterator<T>::Iterator(const Iterator &it)
{
    this->_dq = it._dq;
}

template<typename T>
Iterator<T>::Iterator(T* element)
{
    this->_dq = element;
}

template<typename T>
Iterator<T>  &Iterator<T>::operator=(const Iterator &it)
{
    this->_dq = it._dq;
    return *this;
}

template<typename T>
T   Iterator<T>::operator*() const
{
    return *this->_dq;
}

template<typename T>
Iterator<T>    &Iterator<T>::operator++()
{
    ++this->_dq;
    return *this;
}

template<typename T>
Iterator<T>    Iterator<T>::operator++(int)
{
    Iterator t = *this;

    ++(*this);
    return t;
}

template<typename T>
Iterator<T>    &Iterator<T>::operator--()
{
    --this->_dq;
    return *this;
}

template<typename T>
Iterator<T>    Iterator<T>::operator--(int)
{
    Iterator t = *this;

    --(*this);
    return t;
}

template<typename T>
bool    Iterator<T>::operator==(const Iterator &it) const
{
    return this->_dq == it._dq;
}

template<typename T>
bool    Iterator<T>::operator!=(const Iterator &it) const
{
    return !(*this == it);
}

template<typename T>
bool    Iterator<T>::operator>(const Iterator &it) const
{
    return this->_dq > it._dq;
}

template<typename T>
bool    Iterator<T>::operator>=(const Iterator &it) const
{
    return this->_dq >= it._dq;
}

template<typename T>
bool    Iterator<T>::operator<(const Iterator &it) const
{
    return this->_dq < it._dq;
}

template<typename T>
bool    Iterator<T>::operator<=(const Iterator &it) const
{
    return this->_dq <= it._dq;
}

// MutantStack

template<typename T>
MutantStack<T>::MutantStack()
{
    std::cout << "MutantStack default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "MutantStack destructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &mt) : std::stack<T>::stack(mt)
{
    std::cout << "MutantStack copy constructor called" << std::endl;
}

template<typename T>
MutantStack<T>  MutantStack<T>::operator=(const MutantStack<T> &mt)
{
    std::cout << "MutantStack copy assignment operator called" << std::endl;

    if (this != &mt)
        std::stack<T>::operator=(mt);
    return *this;
}

template<typename T>
Iterator<T> MutantStack<T>::begin()
{
    return Iterator<T>(&this->c[0]);
}

template<typename T>
Iterator<T> MutantStack<T>::end()
{
    return Iterator<T>(&this->c[this->size()]);
}

#endif