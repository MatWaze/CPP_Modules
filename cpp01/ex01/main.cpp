#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Zombie.hpp"
#include <iostream>

Zombie  *zombieHorde(int N, std::string name);

TEST_CASE("Checking zombieHorde function")
{
	std::string	name = "mat";
	int	n = 5;

	Zombie	*zom1 = zombieHorde(n, name);
	Zombie	*temp = NULL;
	Zombie	*first = zom1;

	std::streambuf* oldBuf = std::cout.rdbuf();

	std::ostringstream oss;
	std::cout.rdbuf(oss.rdbuf());

	for (int i = 0; i < n; i++) 
	{
		temp = zom1;
		zom1++;
		temp->announce();
	}
	std::string output = oss.str();
	std::string ans = "mat: BraiiiiiiinnnzzzZ...\nmat: BraiiiiiiinnnzzzZ...\nmat: BraiiiiiiinnnzzzZ...\nmat: BraiiiiiiinnnzzzZ...\nmat: BraiiiiiiinnnzzzZ...\n";
	std::cout.rdbuf(oldBuf);
	
	CHECK_EQ(output, ans);
	delete[] first;
}

TEST_CASE("Negative number hanling for zombieHorde")
{
	std::streambuf* oldBuf = std::cout.rdbuf();

	std::ostringstream oss;
	std::cerr.rdbuf(oss.rdbuf());

	Zombie*	mat = zombieHorde(-443, "Mat");
	(void) mat;
	std::string output = oss.str();
	std::cout.rdbuf(oldBuf);

	CHECK_EQ("Exception caught: std::bad_alloc\n", output);

	delete[] mat;
}
