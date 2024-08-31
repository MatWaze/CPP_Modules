#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int	main(void)
{
	Zombie *zom1 = newZombie("mat");
	zom1->announce();

	randomChump("mart");
	delete zom1;
}
