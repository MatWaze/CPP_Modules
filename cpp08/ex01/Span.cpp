#include "Span.hpp"
#include <algorithm>
#include <climits>
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
    this->_counter = sp.getCounter();

    for (int i = 0; i < sp.getCounter(); i++)
        this->_list[i] = sp._list[i];
}

Span    &Span::operator=(const Span &sp)
{
    std::cout << "Span copy assignment operator called" << std::endl;

    if (this != &sp)
    {
        int spSize = sp.getSize();

        int *temp = new int[spSize];

        for (int i = 0; i < sp.getCounter(); i++)
            temp[i] = sp._list[i];

        delete [] this->_list;
        this->_counter = sp.getCounter();
        this->_list = temp;
        this->_size = spSize;
    }
    return *this;
}

int Span::getSize() const
{
    return this->_size;
}

int Span::getCounter() const
{
    return this->_counter;
}

void    Span::addNumber(int num)
{
    if (this->_counter < this->getSize())
    {
        this->_list[this->_counter] = num;
        this->_counter++;
    }
    else
        throw std::out_of_range("Attempting to add to full span");
}

int Span::shortestSpan()
{
    if (this->_counter > 1)
    {
        // temp Span so that I don't end up sorting the original one
        Span    sorted = *this;

        std::sort(sorted._list, sorted._list + sorted.getCounter());

        int diff = INT_MAX;

        for (int i = 1; i < sorted.getCounter(); i++)
        {
            int newDiff = std::abs(sorted._list[i - 1] - sorted._list[i]);
            diff = std::min(diff, newDiff);
        }

        return diff;
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
