#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), _name("nameless")
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->setAD(FragTrap::getAD());
    this->setEP(ScavTrap::getEP());
    this->setHP(FragTrap::getHP());
}

DiamondTrap::DiamondTrap(const std::string n) : ClapTrap(n), _name(n)
{
    std::cout << "DiamondTrap " << n << " created"
    << std::endl;
    this->setAD(FragTrap::getAD());
    this->setEP(ScavTrap::getEP());
    this->setHP(FragTrap::getHP());
}

DiamondTrap::DiamondTrap(DiamondTrap& dT) : ClapTrap(dT), _name(dT.getName())
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

void    DiamondTrap::setAD(int aD)
{
    FragTrap::setAD(aD);
}

void    DiamondTrap::setHP(int hP)
{
    FragTrap::setHP(hP);
}

void    DiamondTrap::setEP(int eP)
{
    ScavTrap::setEP(eP);
}

int    DiamondTrap::getAD()
{
    return FragTrap::getAD();
}

int    DiamondTrap::getHP()
{
    return FragTrap::getHP();
}

int    DiamondTrap::getEP()
{
    return ScavTrap::getEP();
}

const std::string   DiamondTrap::getName()
{
    return this->_name;
}
