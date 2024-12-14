#include "ScalarConverter.hpp"

void    convertInvalid();
void    convertChar(char c);
void    convertInt(int integer);
void    convertFloat(float flt, std::string &str);
void    convertDouble(double db);

bool    isInff(std::string &str);
bool    isInf(std::string &str);
bool    isNumeric(std::string &str);

std::pair<bool, double>    isDouble(std::string &str);
std::pair<bool, float>    isFloat(std::string &str);
std::pair<bool, int>    isInt(std::string &str);

void    ScalarConverter::convert(std::string &str)
{
    if (!isdigit(*str.c_str()) && str.length() == 1)
    {
        char    c = *(str.c_str());
        convertChar(c);
        return;
    }

    std::pair<bool, int> i = isInt(str);
    
    if (i.first == true)
    {
        int integer = i.second;
        convertInt(integer);
        return;
    }

    std::pair<bool, float> f = isFloat(str);
    
    if (f.first)
    {
        float   flt = f.second;
        convertFloat(flt, str);
        return;
    }

    std::pair<bool, double> d = isDouble(str);
    
    if (d.first == true)
    {
        double db = d.second;
        convertDouble(db);
        return;
    }

    convertInvalid();
}
