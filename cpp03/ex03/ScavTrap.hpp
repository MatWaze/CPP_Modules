#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string n);
        ScavTrap(ScavTrap& sT);
        ScavTrap& operator=(ScavTrap& sT);
        ~ScavTrap();
        void guardGate(void);
        void attack(const std::string n);
         // getters
        int getHP();
        int getAD();
        int getEP();
        const std::string getName();
        // setters
        void setHP(int hP);
        void setAD(int aD);
        void setEP(int eP);
};

#endif
