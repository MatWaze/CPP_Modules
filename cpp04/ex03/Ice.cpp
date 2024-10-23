#include "Ice.hpp"
#include "ex03/ICharacter.hpp"
#include <iostream>

Ice::Ice()
{
    this->_materiaType = "ice";
    std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(Ice& ice)
{
    this->_materiaType = ice._materiaType;
    std::cout << "Ice copy constructo called" << std::endl;
}

Ice&    Ice::operator=(const Ice& ice)
{
    std::cout << "Ice copy assignment operator called" << std::endl;
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

AMateria*   Ice::clone() const
{
    Ice *newIce = new Ice();
    return newIce;
}
