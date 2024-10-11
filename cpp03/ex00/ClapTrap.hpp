#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(const std::string n);
        ~ClapTrap();
        ClapTrap(ClapTrap& cT);
        ClapTrap& operator=(const ClapTrap& cT);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void changeAttack(unsigned int amount);
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
};

#endif