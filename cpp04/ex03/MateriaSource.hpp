#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class   MateriaSource : public IMateriaSource
{
    private:
        int _matIndex;
        AMateria    *_memory[4];
    public:
        int getIndex();
        MateriaSource();
        ~MateriaSource();
        MateriaSource(MateriaSource& ms);
        MateriaSource&  operator=(const MateriaSource& ms);
        void    learnMateria(AMateria *ma);
        bool    checkIfLearned(AMateria *ma);
        AMateria    *createMateria(std::string const &type);
};

#endif