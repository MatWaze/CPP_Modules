#include "Weapon.hpp"

void Weapon::setType(std::string newType)
{
	this->_type = newType;
}

// const member function communicates to users
// of the class that calling getType 
// does not change the state of the object

const std::string& Weapon::getType() const
{
	return this->_type;
}

Weapon::Weapon(std::string name)
{
	this->_type = name;
}

Weapon::Weapon(void)
{

}
