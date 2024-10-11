#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class   ICharacter;

#include <string>

class AMateria
{
    protected:
        std::string _materiaType;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria& materia);
        AMateria& operator=(const AMateria& materia);
        virtual ~AMateria();
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif