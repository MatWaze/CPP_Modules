#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string n)
{
	this->_name = n;
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->_name
	<< " was destroyed" << std::endl;
}

void HumanB::attack(void)
{
	std::cout << this->_name
	<< " attacks with their " 
	<< this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& w)
{
	this->_weapon = &w;
}
