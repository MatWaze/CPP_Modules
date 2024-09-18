#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor " << std::endl;
    this->setHP(100);
    this->setEP(50);
    this->setAD(20);
}

ScavTrap::ScavTrap(const std::string n) : ClapTrap(n)
{
    this->setHP(100);
    this->setEP(50);
    this->setAD(20);
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
        setEP(eP--);
        std::cout << "ScavTrap " << getName() << " attacks " << n
        << " causing " << getAD() << " points of damage!"
        << std::endl;
    }
    else
    {
        std::cout << "Not enough energy to attack" << std::endl;
    }
}