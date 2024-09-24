#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/Users/mamazari/Desktop/42-cursus/CPP_Modules/doctest.h"
#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

TEST_CASE("Testing newZombie function")
{
	Zombie	*z1 = newZombie("matevos");

	std::streambuf* oldBuf = std::cout.rdbuf();
	
	std::ostringstream oss;
	std::cout.rdbuf(oss.rdbuf());
	
	z1->announce();

	std::string output = oss.str();

	CHECK_EQ(output, "matevos: BraiiiiiiinnnzzzZ...\n");
	std::cout.rdbuf(oldBuf);
	delete z1;
	system("leaks zombie");
}

TEST_CASE("Testing Zombie class")
{
	Zombie	*z2 = new Zombie("mat");

	std::streambuf* oldBuf = std::cout.rdbuf();
	
	std::ostringstream oss;
	std::cout.rdbuf(oss.rdbuf());
	
	z2->announce();

	std::string output = oss.str();
	CHECK_EQ(output, "mat: BraiiiiiiinnnzzzZ...\n");
	std::cout.rdbuf(oldBuf);
	delete z2;
	system("leaks zombie");
}

TEST_CASE("Testing randomChump function")
{
	std::streambuf* oldBuf = std::cout.rdbuf();
	
	std::ostringstream oss;
	std::cout.rdbuf(oss.rdbuf());
	
	randomChump("mate");
	
	std::string output = oss.str();
	std::string ans = "mate: BraiiiiiiinnnzzzZ...\nmate died\n";

	CHECK(output == ans);

	std::cout.rdbuf(oldBuf);
}
