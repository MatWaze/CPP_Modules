#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->setHP(100);
    this->setEP(50);
    this->setAD(20);
}

ScavTrap::ScavTrap(ScavTrap& sT) : ClapTrap(sT)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& sT)
{
    ClapTrap::operator=(sT);
    return *this;
}

ScavTrap::ScavTrap(const std::string n) : ClapTrap(n)
{
    std::cout << "ScavTrap " << n << " created"
    << std::endl;
    this->setHP(100);
    this->setEP(50);
    this->setAD(20);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->getName()
    << " was destroyed"
    << std::endl;
}

void    ScavTrap::attack(const std::string n)
{
    int hP = getHP();
    int eP = getEP();

    if (hP <= 0)
    {
        std::cout << "ScavTrap " << getName()
        << " is dead. Can't do anything"
        << std::endl;
    }
    else if (eP > 0)
    {
        eP--;
        setEP(eP);
        std::cout << "ScavTrap " << getName() << " attacks " << n
        << " causing " << getAD() << " points of damage!"
        << std::endl;
    }
    else
    {
        std::cout << "Not enough energy to attack" << std::endl;
    }
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}
