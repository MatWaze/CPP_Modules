#include <iostream>

class Zombie
{	
	public:
		void announce(void);
		~Zombie(void);
		Zombie(std::string name);

	private:
		std::string _name;
};