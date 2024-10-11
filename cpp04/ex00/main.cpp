#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <string>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/Users/mamazari/Desktop/42-cursus/CPP_Modules/doctest.h"
#include <iostream>

TEST_CASE("Testing Animal class")
{
    Animal  *a = new Animal();
    Animal  *b = new Cat();
    Animal  *c = new Dog();
    Animal&  animal2 = *b; // if b was Cat() instead of new Cat(), then animal2 wouldn't have had makeSound of Cat
    Animal&  animal3 = *c;

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
    CHECK_EQ("*unknown animal sound*\nMeooooow\nWoooof\n", output);
    std::cout.rdbuf(oldBuf);

    std::ostringstream oss2;
    std::cout.rdbuf(oss2.rdbuf());

    animal2.makeSound();
    animal3.makeSound();

    output = oss2.str();
    CHECK_EQ(output, "Meooooow\nWoooof\n");
    std::cout.rdbuf(oldBuf);

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
    CHECK_EQ(output, "Meooooow\nMeooooow\nMeooooow\n");
    std::cout.rdbuf(oldBuf);
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
    CHECK_EQ(output, "Woooof\nWoooof\nWoooof\n");
    std::cout.rdbuf(oldBuf);
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
    CHECK_EQ(output, ans);
    std::cout.rdbuf(oldBuf);
    delete wrong1;
}