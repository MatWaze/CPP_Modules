#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Character::Character()
{
    std::cout << "Default Character constructor called" << std::endl;
    _index = 0;
    _unequipedIndex = 0;
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
    for (int j = 0; j < 10; j++)
        this->_unequipedInventory[j] = NULL;
}

Character::~Character()
{
    std::cout << "Character " << getName()
    << " destructor called" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i] != NULL)
        {
            delete this->_slots[i];
            this->_slots[i] = NULL;
        }
    }
    for (int j = 0; j < 10; j++)
    {
        if (this->_unequipedInventory[j] != NULL)
        {
            delete this->_unequipedInventory[j];
            this->_unequipedInventory[j] = NULL;
        }
    }
}

Character::Character(std::string name)
{
    std::cout << "Character " << name << " was created" << std::endl;

    _index = 0;
    _unequipedIndex = 0;
    this->_name = name;
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
    for (int j = 0; j < 10; j++)
        this->_unequipedInventory[j] = NULL;
}

Character::Character(Character& ch)
{
    std::cout << "Character copy constructor called" << std::endl;
    if (this != &ch)
    {
        this->_name = ch._name;
        _index = 0;
        _unequipedIndex = 0;
        for (int i = 0; i < 4; i++)
        {
            if (ch._slots[i])
                this->_slots[i] = ch._slots[i]->clone();
            else
                this->_slots[i] = NULL;
        }
        for (int j = 0; j < 10; j++)
        {
            if (ch._unequipedInventory[j])
                this->_unequipedInventory[j] = ch._unequipedInventory[j]->clone();
            else
                this->_unequipedInventory[j] = NULL;
        }
    }
}

Character&  Character::operator=(const Character& ch)
{
    std::cout << "Character assignment operator called" << std::endl;
    this->_name = ch._name;
    _index = ch.getIndex();
    _unequipedIndex = ch.getUnIndex();
    for (int i = 0; i < 4; i++)
    {
        delete this->_slots[i];
        if (this->_slots[i])
            this->_slots[i] = ch._slots[i]->clone();
        else
            this->_slots[i] = NULL;
    }
    for (int i = 0; i < 10; i++)
    {
        delete this->_unequipedInventory[i];
        if (this->_unequipedInventory[i])
            this->_unequipedInventory[i] = ch._slots[i]->clone();
        else
            this->_unequipedInventory[i] = NULL;
    }
    return *this;
}

bool    Character::checkIfEquipped(AMateria *mat)
{
    bool    ans = false;

    if (_index != 0)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_slots[i] == mat)
            {
                ans = true;
                break;
            }
        }
    }
    return ans;
}

void    Character::setUnequipedNull(AMateria *mat)
{
    if (mat)
    {
        for (int i = 0; i < _unequipedIndex; i++)
        {
            if (this->_unequipedInventory[i] == mat)
                this->_unequipedInventory[i] = NULL;
        }
    }
    else
        std::cout << "Materia is NULL" << std::endl;
}

int    Character::findFreeSlot()
{
    int i = 0;

    for (; i < 4 && this->_slots[i] != NULL; i++) ;
    if (i == 4)
        i--;
    return i;
}

void    Character::equip(AMateria *m)
{
    std::cout << getName() << ": equip: ";
    if (m == NULL)
        std::cout << "Materia is NULL" << std::endl;
    else if (checkIfEquipped(m))
        std::cout << "The materia was already eqipped" << std::endl;
    else if (_index < 4 && this->_slots[_index] == NULL)
    {
        std::cout << "Equiping " << m->getType()
        << " at index " << _index << std::endl;
        this->_slots[_index] = m;
        setUnequipedNull(this->_slots[_index]);
        _index = findFreeSlot();
    }
    else if (_index < 4 && this->_slots[_index] != NULL)
        std::cout << "The slot is occupied" << std::endl;
    else
        std::cout << "No free slots left to equip a materia" << std::endl;
}

void    Character::unequip(int idx)
{
    std::cout << getName() << ": unequip: ";
    if (_unequipedIndex < 10)
    {
        if (this->_slots[idx] == NULL)
            std::cout << "The materia was already dropped" << std::endl;
        else if (idx >= 0 && idx < 4)
        {
            std::cout << "Dropping " << this->_slots[idx]->getType()
            << " at index " << idx << std::endl;
            this->_unequipedInventory[_unequipedIndex] = this->_slots[idx];
            _unequipedIndex++;
            this->_slots[idx] = NULL;
            if (idx > 2)
                _index = 0;
            else
                _index = idx;
        }
        else
            std::cout << "Index must be in range (0, 4)" << std::endl;
    }
    else
        std::cout << "Can't have more than 10 materias on the floor" << std::endl;
}

int    Character::getUnIndex() const
{
    return this->_unequipedIndex;
}

int    Character::getIndex() const
{
    return this->_index;
}

std::string const&    Character::getName() const
{
    return this->_name;
}

void    Character::use(int idx, ICharacter& target)
{
    if (this->_slots[idx] == NULL)
        std::cout << "No materia for this index" << std::endl;
    else if (idx >= 0 && idx < 4)
        this->_slots[idx]->use(target);
    else
        std::cout << "use: Index must be in range (0, 4)" << std::endl;
}
