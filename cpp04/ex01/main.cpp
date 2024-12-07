#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"


// int main2()
// {
//     Animal  *animals[10];

//     for (int i = 0; i < 5; i++)
//         animals[i] = new Cat();

//     for (int i = 5; i < 10; i++)
//         animals[i] = new Dog();

//     for (int i = 0; i < 10; i++)
//         delete animals[i];
//     return (0);
// }

TEST_CASE("Creating array of Animals and filling it with Cats and Dogs")
{
    Animal  *animals[10];

    for (int i = 0; i < 5; i++)
        animals[i] = new Cat();

    for (int i = 5; i < 10; i++)
        animals[i] = new Dog();

    CHECK((animals[0]->getType() == "Cat" && animals[1]->getType() == "Cat" && \
    animals[2]->getType() == "Cat" && animals[3]->getType() == "Cat" && \
    animals[4]->getType() == "Cat"));

    CHECK((animals[5]->getType() == "Dog" && animals[6]->getType() == "Dog" && \
    animals[7]->getType() == "Dog" && animals[8]->getType() == "Dog" && \
    animals[9]->getType() == "Dog"));

    std::streambuf *oldBuf = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());
    
    animals[0]->makeSound();
    animals[5]->makeSound();

    std::string output = oss.str();
    std::cout.rdbuf(oldBuf);
    
    CHECK_EQ(output, "Meooooow\nWoooof\n");

    for (int i = 0; i < 10; i++)
        delete animals[i];
}
