#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class   Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice& ice);
        Ice& operator=(const Ice& ice);
        ~Ice();
        void use(ICharacter& target);
        AMateria* clone() const;
};

#endif