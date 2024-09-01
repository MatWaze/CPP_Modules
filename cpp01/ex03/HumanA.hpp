#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

// References must be initialized when they are created and cannot be changed to refer to another object later.
// Using reference here since HumanA must always carry a weapon

class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon;
	public:
		HumanA(std::string n, Weapon& w);
		void attack();
};

#endif
