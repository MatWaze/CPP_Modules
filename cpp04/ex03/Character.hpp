#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class   Character : public ICharacter
{
    private:
        int  _index;
        int  _unequipedIndex;
        std::string _name;
        AMateria *_slots[4];
        AMateria *_unequipedInventory[10];
    public:
        Character();
        Character(std::string name);
        Character(Character& ch);
        ~Character();
        Character& operator=(const Character& ch);
        std::string const & getName() const;
        int getIndex() const;
        int getUnIndex() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void    setUnequipedNull(AMateria *mat);
        int findFreeSlot();
        bool    checkIfEquipped(AMateria *mat);
};

#endif