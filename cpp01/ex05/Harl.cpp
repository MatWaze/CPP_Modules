#include "Harl.hpp"

void Harl::complain(std::string level)
{
    std::string array[4] = {"debug", "info", "warning", "error"};

    for (int i = 0; i < 4; i++)
    {
        if (array[i] == level)
        {
            (this->*_memberPtrs[i])();
            break;
        }
    }
}

void Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl;      
}

Harl::Harl()
{
    this->_memberPtrs[0] = &Harl::debug;
    this->_memberPtrs[1] = &Harl::info;
    this->_memberPtrs[2] = &Harl::warning;
    this->_memberPtrs[3] = &Harl::error;
}
