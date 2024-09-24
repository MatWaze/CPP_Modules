#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(1), FragTrap(1), _name("nameless")
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string n) : ClapTrap(n), ScavTrap(1), FragTrap(1), _name(n)
{
    std::cout << "DiamondTrap " << n << " created"
    << std::endl;
    this->setAD(FragTrap::getAD());
    this->setEP(ScavTrap::getEP());
    this->setHP(FragTrap::getHP());
}

DiamondTrap::DiamondTrap(DiamondTrap& dT) : ClapTrap(dT), ScavTrap(1), FragTrap(1), _name(dT._name)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap&    DiamondTrap::operator=(DiamondTrap& dT)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(dT);
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name
    << " was destroyed"
    << std::endl;
}

void    DiamondTrap::attack(const std::string n)
{
    ScavTrap::attack(n);
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name is " << this->_name << std::endl;
    std::cout << "ClapTrap name is " << ScavTrap::getName() << std::endl;
}
std::string    DiamondTrap::getName()
{
    return this->_name;
}
