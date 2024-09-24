#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
    std::cout << "Default ScavTrap constructor called" << std::endl;
    ClapTrap::setAD(20);
    ClapTrap::setEP(50);
    ClapTrap::setHP(100);
}

ScavTrap::ScavTrap(int)
{
    std::cout << "Protected ScavTrap constructor called" << std::endl;
    ClapTrap::setEP(50);
}

ScavTrap::ScavTrap(ScavTrap& sT) : ClapTrap(sT)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&   ScavTrap::operator=(ScavTrap& sT)
{
    ClapTrap::operator=(sT);
    return *this;
}

ScavTrap::ScavTrap(const std::string n) : ClapTrap(n)
{
    std::cout << "ScavTrap " << n << " created"
    << std::endl;
    ClapTrap::setHP(100);
    ClapTrap::setEP(50);
    ClapTrap::setAD(20);
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
        std::cout << "ScavTrap " << ClapTrap::getName()
        << " is dead. Can't do anything"
        << std::endl;
    }
    else if (eP > 0)
    {
        eP--;
        setEP(eP);
        std::cout << "ScavTrap " << ClapTrap::getName() << " attacks " << n
        << " causing " << this->getAD() << " points of damage!"
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
