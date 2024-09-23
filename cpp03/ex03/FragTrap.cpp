#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap()
{
    std::cout << "Default FragTrap constructor called" << std::endl;
    ClapTrap::setHP(100);
    ClapTrap::setAD(30);
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
    ClapTrap::setHP(100);
    ClapTrap::setEP(100);
    ClapTrap::setAD(30);
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

void    FragTrap::setAD(int aD)
{
    ClapTrap::setAD(aD);
}

void    FragTrap::setHP(int hP)
{
    ClapTrap::setHP(hP);
}

void    FragTrap::setEP(int eP)
{
    ClapTrap::setEP(eP);
}

int    FragTrap::getAD()
{
    return ClapTrap::getAD();
}

int    FragTrap::getHP()
{
    return ClapTrap::getHP();
}

int    FragTrap::getEP()
{
    return ClapTrap::getEP();
}

const std::string   FragTrap::getName()
{
    return ClapTrap::getName();
}
