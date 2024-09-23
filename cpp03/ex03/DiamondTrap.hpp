#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(const std::string n);
        DiamondTrap(DiamondTrap& dT);
        DiamondTrap& operator=(DiamondTrap& dT);
        ~DiamondTrap();
        void attack(const std::string n);
        void whoAmI();
        // getters
        int getHP();
        int getAD();
        int getEP();
        const std::string getName();
        // setters
        void setHP(int hP);
        void setAD(int aD);
        void setEP(int eP);
    private:
        const std::string _name;
};

#endif
