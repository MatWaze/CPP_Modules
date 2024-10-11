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
        DiamondTrap& operator=(const DiamondTrap& dT);
        ~DiamondTrap();
        void attack(const std::string n);
        void whoAmI();
        // getters
        std::string getName();
    private:
        std::string _name;
};

#endif
