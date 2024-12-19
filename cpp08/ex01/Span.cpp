#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

Span::Span()
{
    std::cout << "Span default constructor called" << std::endl;

    this->_list = NULL;
    this->_size = 0;
    this->_counter = 0;
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;

    delete [] this->_list;
}

Span::Span(unsigned int N)
{
    std::cout << "Span parameter constructor called" << std::endl;

    this->_list = new int[N];
    this->_size = N;
    this->_counter = 0;
}

Span::Span(const Span &sp)
{
    std::cout << "Span copy constructor called" << std::endl;

    int spSize = sp.getSize();

    this->_size = spSize;
    this->_list = new int[spSize];
    this->_counter = sp._counter;

    for (int i = 0; i < spSize; i++)
        this->_list[i] = sp._list[i];
}

Span    &Span::operator=(const Span &sp)
{
    std::cout << "Span copy assignment operator called" << std::endl;

    if (this != &sp)
    {
        int spSize = sp.getSize();

        int *temp = new int[spSize];
        int i = 0;

        for (; i < spSize; i++)
            temp[i] = sp._list[i];

        delete [] this->_list;
        this->_counter = sp._counter;
        this->_list = temp;
        this->_size = spSize;
    }
    return *this;
}

int Span::getSize() const
{
    return this->_size;
}

void    Span::addNumber(int num)
{
    if (this->_counter < this->getSize())
    {
        this->_list[this->_counter] = num;
        this->_counter++;
    }
    else
        throw std::out_of_range("The span is full");
}

int Span::shortestSpan()
{
    if (this->_counter > 1)
    {
        std::sort(this->_list, this->_list + this->_counter);

        int mx = this->_list[this->_counter - 1];
        int lessMx = this->_list[this->_counter - 2];

        return mx - lessMx;
    }
    else
        throw std::out_of_range("The span has less than 2 elements");
}

int Span::longestSpan()
{
    if (this->_counter > 1)
    {
        int *mx = std::max_element(this->_list, this->_list + this->_counter);
        int *mn = std::min_element(this->_list, this->_list + this->_counter);

        return *mx - *mn;
    }
    else
        throw std::out_of_range("The span has less than 2 elements");
}
