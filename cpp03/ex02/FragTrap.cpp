#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->setHP(100);
    this->setEP(100);
    this->setAD(30);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->getName()
    << " was destroyed" << std::endl;
}

FragTrap::FragTrap(const std::string n) : ClapTrap(n)
{
    std::cout << "FragTrap " << n << " created"
    << std::endl;
    this->setHP(100);
    this->setEP(100);
    this->setAD(30);
}

FragTrap&   FragTrap::operator=(FragTrap& fT)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(fT);
    return *this;
}

FragTrap::FragTrap(FragTrap& fT) : ClapTrap(fT)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "Give high five!" << std::endl;
}
