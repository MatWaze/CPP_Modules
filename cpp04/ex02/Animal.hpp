#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class   Animal
{
    protected:
        Animal();
        Animal(Animal& Animal);
        Animal& operator=(const Animal& Animal);
        std::string type;
    public:
        virtual ~Animal();
        std::string getType();
        virtual void makeSound();
};

#endif