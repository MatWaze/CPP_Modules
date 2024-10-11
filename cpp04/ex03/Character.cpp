#include "Character.hpp"
#include <iostream>

Character::Character()
{
    std::cout << "Default Character constructor called" << std::endl;
}

Character::Character(std::string name)
{
    this->_name = name;
    std::cout << "Character " << name << " was created" << std::endl;
}

Character::Character(Character& ch)
{
    
}
