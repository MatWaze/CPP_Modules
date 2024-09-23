#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string n);
        ScavTrap(ScavTrap& sT);
        ScavTrap& operator=(ScavTrap& sT);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string n);
};

#endif
