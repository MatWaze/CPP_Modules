#include "ScavTrap.hpp"
#include <iostream>
int main()
{
    ScavTrap    matevos("matevos");
    ScavTrap    mat("mat");

    matevos.attack("mat");
    matevos.attack("mat");
    matevos.attack("mat");
    matevos.attack("mat");

    mat.takeDamage(80);
    mat.beRepaired(10);
    std::cout << "mat has " << mat.getHP() << std::endl;
}
