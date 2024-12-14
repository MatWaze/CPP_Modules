#include "Data.hpp"
#include <iostream>

Data::Data()
{
    std::cout << "Data default constructor called" << std::endl; 
}

Data::Data(std::string val, int id)
{
    std::cout << "Data parameter constructor called" << std::endl;

    this->_id = id;
    this->_val = val;
}

Data::~Data()
{
    std::cout << "Data default destructor called" << std::endl;
}

Data::Data(Data &d)
{
    std::cout << "Data copy constructor called" << std::endl;

    this->_id = d.getId();
    this->_val = d.getVal();
}

Data    &Data::operator=(const Data &d)
{
    std::cout << "Data copy assignment operator called" << std::endl;
    
    if (this != &d)
    {
        this->_id = d.getId();
        this->_val = d.getVal();
    }

    return *this;
}

std::string Data::getVal() const
{
    return this->_val;
}

int Data::getId() const
{
    return this->_id;
}
