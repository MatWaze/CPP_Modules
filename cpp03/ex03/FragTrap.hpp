#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class   FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string n);
        FragTrap(FragTrap& sT);
        FragTrap& operator=(FragTrap& sT);
        ~FragTrap();
        void highFivesGuys();
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
