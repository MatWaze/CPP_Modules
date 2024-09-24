#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string n, Weapon &w) : _weapon(w)
{
	this->_name = n;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " <<
	this->_name << " was destroyed"
	<< std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->_name
	<< " attacks with their " 
	<< this->_weapon.getType() << std::endl;
}
