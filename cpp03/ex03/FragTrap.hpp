#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class   FragTrap : virtual public ClapTrap
{
    protected:
        FragTrap(int);
    public:
        FragTrap();
        FragTrap(const std::string n);
        FragTrap(FragTrap& sT);
        FragTrap& operator=(const FragTrap& sT);
        ~FragTrap();
        void highFivesGuys();
};

#endif
