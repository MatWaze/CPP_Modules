#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
    std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
    this->_materiaType = type;
    std::cout << "AMatetia " << type << " is created" << std::endl;
}

AMateria::AMateria(AMateria& materia)
{
    this->_materiaType = materia._materiaType;
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria&   AMateria::operator=(const AMateria& materia)
{
    if (this != &materia)
    {
        this->_materiaType = materia._materiaType;
    }
    std::cout << "AMateria copy assignment operator called" << std::endl;
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->_materiaType;
}

void    AMateria::use(ICharacter& target)
{
    this->_materiaType = target.getName();
}
