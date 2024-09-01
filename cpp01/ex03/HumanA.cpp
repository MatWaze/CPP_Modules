#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string n, Weapon &w) : _weapon(w)
{
	this->_name = n;
}

void HumanA::attack(void)
{
	std::cout << this->_name
	<< " attacks with their " 
	<< this->_weapon.getType() << std::endl;
}
