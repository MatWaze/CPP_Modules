#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class   FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string n);
        FragTrap(FragTrap& fT);
        FragTrap& operator=(const FragTrap& fT);
        ~FragTrap();
        void highFivesGuys(void);
};

#endif
