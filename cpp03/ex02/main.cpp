#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/Users/mamazari/Desktop/42-cursus/CPP_Modules/doctest.h"
#include "FragTrap.hpp"

TEST_CASE("Testing FragTrap class")
{
    FragTrap    mate;
    FragTrap    mat("mat");
    FragTrap    matevos("matevos");
    FragTrap    matevos1 = matevos;
    FragTrap    matevos2;
    matevos2 = matevos1;

    SUBCASE("Checking FragTrap created with default constructor")
    {
        CHECK_EQ(mate.getName(), "nameless");
        CHECK_EQ(mate.getAD(), 30);
        CHECK_EQ(mate.getEP(), 100);
        CHECK_EQ(mate.getHP(), 100);
    }

    SUBCASE("Checking FragTrap created with string constructor")
    {
        CHECK_EQ(mat.getName(), "mat");
        CHECK_EQ(matevos.getName(), "matevos");

        CHECK_EQ(mat.getAD(), 30);
        CHECK_EQ(matevos.getAD(), 30);

        CHECK_EQ(mat.getEP(), 100);
        CHECK_EQ(matevos.getEP(), 100);

        CHECK_EQ(mat.getHP(), 100);
        CHECK_EQ(matevos.getHP(), 100);
    }

    SUBCASE("Checking FragTrap created with copy constructor")
    {
        CHECK_EQ(matevos1.getName(), "matevos");
        CHECK_NE(matevos1.getName(), "nameless");

        CHECK_EQ(matevos1.getAD(), 30);
        CHECK_EQ(matevos1.getEP(), 100);
        CHECK_EQ(matevos1.getHP(), 100);
    }
    
    SUBCASE("Checking FragTrap created with copy assignment operator")
    {
        CHECK_EQ(matevos2.getName(), "nameless");
        CHECK_NE(matevos2.getName(), "matevos");

        CHECK_EQ(matevos2.getAD(), matevos1.getAD());
        CHECK_EQ(matevos2.getHP(), matevos1.getHP());
        CHECK_EQ(matevos2.getEP(), matevos1.getEP());
    }

    SUBCASE("Checking FragTrap methods")
    {
        int i = 0;
        for (; i < 4; i++)
            matevos.attack("mat");

        mat.takeDamage(matevos.getAD() * i);
        CHECK_EQ(mat.getHP(), 100 - (matevos.getAD() * i));

        mat.beRepaired(120);
        CHECK_EQ(mat.getHP(), 100 - (matevos.getAD() * i));
        CHECK_EQ(matevos.getEP(), 100 - i);
    }
}
