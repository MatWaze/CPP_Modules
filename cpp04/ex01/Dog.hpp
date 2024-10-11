#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Dog : public Animal
{
    public:
        Dog();
        Dog(Dog& dog);
        Dog& operator=(Dog& dog);
        ~Dog();
        void makeSound();
    private:
        Brain *_brain;
};

#endif
