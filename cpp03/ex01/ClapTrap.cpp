#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()// : _attackDamage(0), _energyPoints(10), _hitPoints(10) 
{
    // std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string n) : _name(n)//, _attackDamage(0), _energyPoints(10), _hitPoints(10)
{
    // std::cout << "ClapTrap " << n << " created"
    // << std::endl;
}

ClapTrap::~ClapTrap()
{
    // std::cout << "ClapTrap " << this->_name
    // << " was destroyed"
    // << std::endl;
}

int ClapTrap::getAD()
{
    return this->_attackDamage;
}

int ClapTrap::getEP()
{
    return this->_energyPoints;
}

int ClapTrap::getHP()
{
    return this->_hitPoints;
}

void    ClapTrap::setEP(int eP)
{
    this->_energyPoints = eP;
}

void    ClapTrap::setAD(int aD)
{
    this->_attackDamage = aD;
}

void    ClapTrap::setHP(int hP)
{
    this->_hitPoints = hP;
}

const std::string ClapTrap::getName()
{
    return this->_name;
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
