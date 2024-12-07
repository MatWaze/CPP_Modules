#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class   Animal
{
    public:
        Animal();
        Animal(Animal& Animal);
        Animal& operator=(const Animal& Animal);
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const;
    protected:
        std::string type;
};

#endif
