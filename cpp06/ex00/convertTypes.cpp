#include <cfloat>
#include <climits>
#include <iostream>
#include <cstdlib>

void    printChar(int s)
{
    std::cout << "char: ";
    
    if (s >= 0 && s < 33)
        std::cout << "Non displayable";
    else if (s > 32 && s < 127)
        std::cout << static_cast<char>(s);
    else
        std::cout << "impossible";
    std::cout << std::endl;
}
    double d = 0.;

void    convertInvalid()
{
    std::cout << "str is invalid" << std::endl;
}

void    convertChar(char c)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;

    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void    convertInt(int integer)
{
    printChar(integer);
    std::cout << "int: " << integer << std::endl;
    std::cout << "float: " << static_cast<float>(integer) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(integer) << ".0" << std::endl;
}

void    convertFloat(float flt, std::string &str)
{
    if (flt <= INT_MAX && flt >= INT_MIN)
    {
        int integer = static_cast<int>(flt);
        printChar(integer);

        std::cout << "int: " << integer << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl; 
        std::cout << "int: impossible" << std::endl; 
    }

    std::cout << "float: " << flt << "f" << std::endl;

    if (flt > FLT_MAX || flt < -FLT_MAX)
        std::cout << "double: " << std::atof(str.c_str()) << std::endl;
    else
        std::cout << "double: " << static_cast<double>(flt) << std::endl;
}

void    convertDouble(double db)
{
    if (db <= INT_MAX && db >= INT_MIN)
    {
        int integer = static_cast<int>(db);
        printChar(integer);

        std::cout << "int: " << integer << std::endl;            
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }

    std::cout << "float: " << static_cast<float>(db) << "f" << std::endl;
    std::cout << "double: " << db << std::endl;
}
