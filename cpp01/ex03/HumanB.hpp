#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

// Using ptr here since HumanB may not have a weapon

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(std::string n);
		~HumanB();
		void setWeapon(Weapon& w);
		void attack();
};

#endif

