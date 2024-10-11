#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Cat : public Animal
{
    public:
        Cat();
        Cat(Cat& Cat);
        Cat& operator=(Cat& Cat);
        ~Cat();
        void makeSound();
    private:
        Brain *_brain;
};

#endif
