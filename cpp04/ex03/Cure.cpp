#include "Cure.hpp"
#include "ex03/ICharacter.hpp"
#include <iostream>

Cure::Cure()
{
    this->_materiaType = "cure";
    std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(Cure& Cure)
{
    this->_materiaType = Cure._materiaType;
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure&    Cure::operator=(const Cure& Cure)
{
    std::cout << "Cure copy assignment operator called" << std::endl;
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*    Cure::clone() const
{
    Cure    *newCure = new Cure();
    return newCure;
}
