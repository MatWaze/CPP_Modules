#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <cstddef>
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;

    _matIndex = 0;
    for (int i = 0; i < 4; i++)
        this->_memory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource& ms)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;

    if (this != &ms)
    {
        _matIndex = ms._matIndex;
        for (int i = 0; i < 4; i++)
        {
            if (ms._memory[i])
                this->_memory[i] = ms._memory[i]->clone();
            else
                this->_memory[i] = NULL;
        }
    }
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& ms)
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;

    _matIndex = ms._matIndex;
    for (int i = 0; i < 4; i++)
    {
        delete this->_memory[i];
        if (ms._memory[i])
            this->_memory[i] = ms._memory[i]->clone();
        else
            this->_memory[i] = NULL;
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (this->_memory[i] != NULL)
        {
            delete this->_memory[i];
            this->_memory[i] = NULL;
        }
    }
}

bool    MateriaSource::checkIfLearned(AMateria *ma)
{
    bool    ans = false;

    for (int i = 0; i < 4; i++)
    {
        if (this->_memory[i]->getType() == ma->getType())
        {
            ans = true;
            break;
        }
    }
    return ans;
}

void    MateriaSource::learnMateria(AMateria *ma)
{
    if (_matIndex < 4)
    {
        std::cout << "Learned new materia: " << ma->getType() << std::endl;
        this->_memory[_matIndex] = ma;
        _matIndex++;
    }
    else
    {
        std::cout
        << "MateriaSource: learnMateria: Can't learn more than 4 materias" <<
        std::endl;
    }
}

AMateria    *MateriaSource::createMateria(std::string const &type)
{
    AMateria    *newMat = 0;

    for (int i = 0; i < _matIndex; i++)
    {
        if (this->_memory[i]->getType() == type)
        {
            newMat = this->_memory[i]->clone();
            break;
        }
    }
    if (newMat == 0)
        std::cout << "MateriaSource: createMateria: Unknown materia" << std::endl;
    return newMat;
}

int    MateriaSource::getIndex()
{
    return this->_matIndex;
}
