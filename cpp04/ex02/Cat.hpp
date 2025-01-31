#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Cat : public Animal
{
    public:
        Cat();
        Cat(Cat& cat);
        Cat& operator=(Cat& cat);
        ~Cat();
        void makeSound() const;
    private:
        Brain *_brain;
};

#endif
