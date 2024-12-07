#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include "WrongCat.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

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

TEST_CASE("Testing Animal class")
{
    Animal  *a = new Animal();
    Animal  *b = new Cat();
    Animal  *c = new Dog();
    Animal  &animal2 = *b;
    Animal  &animal3 = *c;

    CHECK_EQ(a->getType(), "Animal");
    CHECK_EQ(b->getType(), "Cat");
    CHECK_EQ(c->getType(), "Dog");

    CHECK_EQ(animal2.getType(), "Cat");
    CHECK_EQ(animal3.getType(), "Dog");
    
    std::streambuf* oldBuf = std::cout.rdbuf();
    
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());
    
    a->makeSound();
    b->makeSound();
    c->makeSound();

    std::string output = oss.str();
    std::cout.rdbuf(oldBuf);
    CHECK_EQ("*unknown animal sound*\nMeooooow\nWoooof\n", output);

    std::ostringstream oss2;
    std::cout.rdbuf(oss2.rdbuf());

    animal2.makeSound();
    animal3.makeSound();

    output = oss2.str();
    std::cout.rdbuf(oldBuf);
    
    CHECK_EQ(output, "Meooooow\nWoooof\n");

    delete a;
    delete b;
    delete c;
}

TEST_CASE("Testing Cat class")
{
    Cat cat;
    Cat *cat2 = new Cat(cat);
    Cat *cat3;
    cat3 = cat2;

    CHECK((cat.getType() == cat2->getType() && cat2->getType() == cat3->getType() \
        && cat.getType() == cat3->getType()));
    std::streambuf* oldBuf = std::cout.rdbuf();
    
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    cat.makeSound();
    cat2->makeSound();
    cat3->makeSound();

    std::string output = oss.str();
    std::cout.rdbuf(oldBuf);
    
    CHECK_EQ(output, "Meooooow\nMeooooow\nMeooooow\n");
    delete cat2;
}

TEST_CASE("Testing Dog class")
{
    Dog dog;
    Dog *dog2 = new Dog(dog);
    Dog *dog3;
    dog3 = dog2;

    CHECK((dog.getType() == dog2->getType() && dog2->getType() == dog3->getType() \
        && dog.getType() == dog3->getType()));
    std::streambuf* oldBuf = std::cout.rdbuf();
    
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    dog.makeSound();
    dog2->makeSound();
    dog3->makeSound();

    std::string output = oss.str();
    std::cout.rdbuf(oldBuf);
    
    CHECK_EQ(output, "Woooof\nWoooof\nWoooof\n");
    delete dog2;
}

TEST_CASE("Testing Wrong classes")
{
    WrongAnimal *wrong1 = new WrongCat();
    WrongAnimal *wrong2 = wrong1;
    WrongAnimal *wrong3;
    wrong3 = wrong2;
    WrongCat wrongCat;

    CHECK_EQ(wrong1->getType(), "WrongCat");
    CHECK_EQ(wrong2->getType(), "WrongCat");
    CHECK_EQ(wrong3->getType(), "WrongCat");

    std::streambuf* oldBuf = std::cout.rdbuf();

    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    wrong1->makeSound();
    wrong2->makeSound();
    wrong3->makeSound();
    wrongCat.makeSound();

    std::string output = oss.str();
    std::string ans = "";
    ans += "*unknown WrongAnimal sound*\n";
    ans += "*unknown WrongAnimal sound*\n";
    ans += "*unknown WrongAnimal sound*\n";
    ans += "Meooooow\n";
    
    std::cout.rdbuf(oldBuf);
    CHECK_EQ(output, ans);
    delete wrong1;
}
