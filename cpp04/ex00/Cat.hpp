#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class   Cat : public Animal
{
    public:
        Cat();
        Cat(Cat& Cat);
        Cat& operator=(const Cat& Cat);
        ~Cat();
        void makeSound() const;
};

#endif
