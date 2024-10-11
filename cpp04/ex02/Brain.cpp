#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Default Brain constructor called" << std::endl;
}

void    Brain::setIdeas(Brain *brain, const Brain *otherBrain)
{
    for (int i = 0; i < 100; i++)
        brain->ideas[i] = otherBrain->ideas[i];
}

Brain::~Brain()
{
    std::cout << "Default Brain desctructor called" << std::endl;
}

Brain::Brain(Brain& brain)
{
    this->setIdeas(this, &brain);
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain&  Brain::operator=(const Brain& brain)
{
    if (this != &brain)
    {
        this->setIdeas(this, &brain);
    }
    std::cout << "Brain copy assignment operator called" << std::endl;
    return *this;
}
