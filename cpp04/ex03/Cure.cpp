#include "Cure.hpp"
#include <cstddef>
#include <iostream>
#include <new>

Cure::Cure()
{
    this->_materiaType = "cure";
    std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(Cure& cure)
{
    this->_materiaType = cure.getType();
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure&    Cure::operator=(const Cure& cure)
{
    (void) cure;
    std::cout << "Cure copy assignment operator called" << std::endl;
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called " << std::endl;
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*    Cure::clone() const
{
    std::cout << "Cure: clone: ";
    Cure    *newCure = NULL;
    try
    {
        std::cout << "success" << std::endl;
        newCure = new Cure();
    }
    catch (std::bad_alloc&)
    {
        std::cout << "Memory allocation failed" << std::endl;
    }
    return newCure;
}
