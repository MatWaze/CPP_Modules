#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <string>

TEST_CASE("Testing Animal class")
{
    Animal  *b = new Cat();
    Animal  *c = new Dog();

    Animal&  animal2 = *b;
    Animal&  animal3 = *c;

    Cat cat;
    Cat cat2 = cat;

    Dog dog;
    Dog dog2 = dog;

    CHECK_EQ(b->getType(), "Cat");
    CHECK_EQ(c->getType(), "Dog");
    CHECK_EQ(cat.getType(), cat2.getType());
    CHECK_EQ(dog.getType(), dog2.getType());
    
    CHECK_EQ(animal2.getType(), "Cat");
    CHECK_EQ(animal3.getType(), "Dog");
    
    std::streambuf* oldBuf = std::cout.rdbuf();
    
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());
    
    b->makeSound();
    c->makeSound();

    std::string output = oss.str();
    CHECK_EQ("Meooooow\nWoooof\n", output);
    std::cout.rdbuf(oldBuf);

    std::ostringstream oss2;
    std::cout.rdbuf(oss2.rdbuf());

    animal2.makeSound();
    animal3.makeSound();

    output = oss2.str();
    CHECK_EQ(output, "Meooooow\nWoooof\n");
    std::cout.rdbuf(oldBuf);
    std::cout << output << std::endl;
    delete b;
    delete c;
}
