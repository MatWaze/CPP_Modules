#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Default Brain constructor called" << std::endl;
}

void    Brain::setIdeas(const Brain *otherBrain)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = otherBrain->ideas[i];
}

Brain::~Brain()
{
    std::cout << "Default Brain desctructor called" << std::endl;
}

Brain::Brain(Brain& brain)
{
    std::cout << "Brain copy constructor called" << std::endl;
    this->setIdeas(&brain);
}

Brain&  Brain::operator=(const Brain& brain)
{
    if (this != &brain)
    {
        this->setIdeas(&brain);
    }
    std::cout << "Brain copy assignment operator called" << std::endl;
    return *this;
}
