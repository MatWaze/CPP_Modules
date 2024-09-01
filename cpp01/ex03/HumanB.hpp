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
		void setWeapon(Weapon& w);
		void attack();
};
