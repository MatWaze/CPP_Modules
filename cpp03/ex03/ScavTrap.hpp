#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    protected:
        ScavTrap(int);
    public:
        ScavTrap();
        ScavTrap(const std::string n);
        ScavTrap(ScavTrap& sT);
        ScavTrap& operator=(const ScavTrap& sT);
        ~ScavTrap();
        void guardGate(void);
        void attack(const std::string n);
};

#endif
