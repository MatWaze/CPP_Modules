#include "Cat.hpp"
#include "Dog.hpp"

int main2()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    return 0;
}

int main()
{
    main2();
    system("leaks a.out");
}