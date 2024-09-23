#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("nameless"), _attackDamage(0), _energyPoints(10), _hitPoints(10) 
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string n) : _name(n), _attackDamage(0), _energyPoints(10), _hitPoints(10)
{
    std::cout << "ClapTrap " << n << " created"
    << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& cT) : _attackDamage(cT._attackDamage), _energyPoints(cT._energyPoints), _hitPoints(cT._hitPoints)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap&   ClapTrap::operator=(ClapTrap& cT)
{
    if (this != &cT)
    {
        this->_attackDamage = cT._attackDamage;
        this->_energyPoints = cT._energyPoints;
        this->_hitPoints = cT._hitPoints;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name
    << " was destroyed"
    << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name
        << " is dead. Can't do anything"
        << std::endl;
    }
    else if (this->_energyPoints > 0)
    {
        this->_energyPoints--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target
        << " causing " << this->_attackDamage << " points of damage!"
        << std::endl;
    }
    else
    {
        std::cout << "Not enough energy to attack" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " lost "
    << amount << " health points"
    << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name
        << " is dead. Can't do anything"
        << std::endl;
    }
    else if (this->_energyPoints > 0)
    {
        this->_hitPoints += amount;
        this->_energyPoints--;

        std::cout << "ClapTrap " << this->_name << " restored "
        << amount << " health points"
        << std::endl;
    }
    else
    {
        std::cout << "Not enough energy to repair yourself" << std::endl;
    }
}

void    ClapTrap::changeAttack(unsigned int amount)
{
    this->_attackDamage = amount;
}