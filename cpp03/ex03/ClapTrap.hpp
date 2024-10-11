#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(const std::string n);
        ClapTrap(ClapTrap& cT);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& cT);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
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
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
};

#endif
