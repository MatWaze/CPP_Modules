#include "Zombie.hpp"
#include <cstddef>

Zombie  *zombieHorde(int N, std::string name)
{
	if (N > 0)
	{
		Zombie	*zombies = new Zombie[N];

		for (int i = 0; i < N; i++) 
			zombies[i] = Zombie(name);
		return zombies;
	}
	else
		std::cerr << "Exception caught: std::bad_alloc"<< std::endl;
	return NULL;
}
