#include "ClapTrap.hpp"

int main()
{
    ClapTrap    matevos("matevos");
    ClapTrap    mat("mat");

    matevos.changeAttack(1);
    matevos.attack("mat");
    matevos.attack("mat");
    matevos.attack("mat");
    matevos.attack("mat");
    matevos.attack("mat");
    matevos.attack("mat");
    matevos.attack("mat");
    matevos.attack("mat");
    matevos.attack("mat");
    matevos.attack("mat");
    matevos.attack("mat");

    mat.takeDamage(10);
    mat.beRepaired(10);

    return 0;
}