#include "Harl.hpp"

void Harl::complain(std::string level)
{
    std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int j = 0;
    for (int i = 0; i < 4; i++)
    {
        if (array[i] == level)
        {
            j = i;
            break;
        }
    }
    std::cout << "index: " << j << std::endl;
    switch (j)
    {
        case 0:
            for (int i = 0; i < 4; i++)
            {
                std::cout << "[ " << array[i] << " ]" << std::endl;
                (this->*_memberPtrs[i])();
            }
            break;
        case 1:
            for (int i = 1; i < 4; i++)
            {
                std::cout << "[ " << array[i] << " ]" << std::endl;
                (this->*_memberPtrs[i])();
            }
            break;
        case 2:
            for (int i = 2; i < 4; i++)
            {
                std::cout << "[ " << array[i] << " ]" << std::endl;
                (this->*_memberPtrs[i])();
            }
            break;
        case 3:
            std::cout << "here" << std::endl;
            std::cout << "[ " << "ERROR" << " ]" << std::endl;
            (this->*_memberPtrs[3])();
            break;
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
