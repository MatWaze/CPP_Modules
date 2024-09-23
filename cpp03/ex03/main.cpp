#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/Users/mamazari/Desktop/42-cursus/CPP_Modules/doctest.h"
#include "DiamondTrap.hpp"

TEST_CASE("Testing DiamondTrap class")
{
    DiamondTrap    mate;
    DiamondTrap    mat("mat");
    DiamondTrap    matevos("matevos");
    DiamondTrap    matevos1 = matevos;
    DiamondTrap    matevos2;
    matevos2 = matevos1;

    SUBCASE("Checking DiamondTrap created with default constructor")
    {
        CHECK_EQ(mate.getName(), "nameless");
        CHECK_EQ(mate.getAD(), 30);
        CHECK_EQ(mate.getEP(), 50);
        CHECK_EQ(mate.getHP(), 100);
    }

    SUBCASE("Checking DiamondTrap created with string constructor")
    {
        CHECK_EQ(mat.getName(), "mat");
        CHECK_EQ(matevos.getName(), "matevos");

        CHECK_EQ(mat.getAD(), 30);
        CHECK_EQ(matevos.getAD(), 30);

        CHECK_EQ(mat.getEP(), 50);
        CHECK_EQ(matevos.getEP(), 50);

        CHECK_EQ(mat.getHP(), 100);
        CHECK_EQ(matevos.getHP(), 100);
    }

    SUBCASE("Checking DiamondTrap created with copy constructor")
    {
        CHECK_EQ(matevos1.getName(), "matevos");
        CHECK_NE(matevos1.getName(), "nameless");

        CHECK_EQ(matevos1.getAD(), 30);
        CHECK_EQ(matevos1.getEP(), 50);
        CHECK_EQ(matevos1.getHP(), 100);
    }
    
    SUBCASE("Checking DiamondTrap created with copy assignment operator")
    {
        CHECK_EQ(matevos2.getName(), "nameless");
        CHECK_NE(matevos2.getName(), "matevos");

        CHECK_EQ(matevos2.getAD(), matevos1.getAD());
        CHECK_EQ(matevos2.getHP(), matevos1.getHP());
        CHECK_EQ(matevos2.getEP(), matevos1.getEP());
    }

    SUBCASE("Checking DiamondTrap methods")
    {
        int i = 0;
        int c = 0;
        for (; i < 3; i++, c++)
            mate.attack("matevos");

        matevos.takeDamage(mate.getAD() * i);
        CHECK_EQ(matevos.getHP(), 100 - (mate.getAD() * i));
        CHECK_EQ(mate.getEP(), 50 - c);

        matevos.beRepaired(mate.getAD() * i);
        CHECK_EQ(matevos.getHP(), 100);
        CHECK_EQ(matevos.getEP(), 49);

        i = 0;
        for (; i < 4; i++, c++)
            mate.attack("matevos");
        matevos.takeDamage(mate.getAD() * i);
        matevos.beRepaired(100);
        CHECK_EQ(100 - mate.getAD() * i, -20);
        CHECK_EQ(matevos.getEP(), 49);
        CHECK_EQ(mate.getEP(), 50 - c);
    }
}
