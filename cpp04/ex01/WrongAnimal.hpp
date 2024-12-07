#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class   WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal& WrongAnimal);
        WrongAnimal& operator=(const WrongAnimal& WrongAnimal);
        virtual ~WrongAnimal();
        std::string getType() const;
        void makeSound() const;
    protected:
        std::string type;
};

#endif
