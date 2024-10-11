#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/Users/mamazari/Desktop/42-cursus/CPP_Modules/doctest.h"
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }
    return result;
}

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
    CHECK_EQ(output, "Meooooow\nWoooof\n");
    std::cout.rdbuf(oldBuf);

    for (int i = 0; i < 10; i++)
        delete animals[i];
    
    output = exec("leaks animal");
    CHECK_NE(output.find("0 leaks"), std::string::npos);
}
