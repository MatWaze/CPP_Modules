#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{	
	public:
		void announce();
		~Zombie();
		Zombie(std::string name);

	private:
		std::string _name;
};

#endif
