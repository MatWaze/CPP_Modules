#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name);

int	main2(void)
{
	int	n = 5;
	Zombie	*zom1 = zombieHorde(n, "mat");
	Zombie	*temp = NULL;
	Zombie	*first = zom1;

	for (int i = 0; i < n; i++) 
	{
		temp = zom1;
		zom1++;
		temp->announce();
    }
	delete[] first;
	return (0);
}


int	main(void)
{
	main2();
	system("leaks zombieHorde");
	return (0);
}
