#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class   Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *slots[4] = {};
    public:
        Character();
        Character(std::string name);
        Character(Character& ch);
        ~Character();
        Character& operator=(const Character& ch);
        std::string const & getName() const;
        void eqip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif