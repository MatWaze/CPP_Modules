#include <string>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <string>

bool    isInff(std::string &str);
bool    isInf(std::string &str);
bool    isNumeric(std::string &str);
std::pair<bool, double>    isDouble(std::string &str);
std::pair<bool, float>    isFloat(std::string &str);
std::pair<bool, int>    isInt(std::string &str);

bool    isInff(std::string &str)
{
    if (str == "inff" || str == "-inff" || str == "+inff")
        return true;
    return false;
}

bool    isInf(std::string &str)
{
    if (str == "inf" || str == "-inf" || str == "+inf")
        return true;
    return false;
}

std::pair<bool, double>    isDouble(std::string &str)
{
    int pointC = 0;
    int digitC = 0;
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;

    int len = str.length() - i;

    for (; i < len + 1; i++)
    {
        if (str[i] == '.')
            pointC++;
        else if (std::isdigit(str[i]))
            digitC++;
    }

    bool    isDouble = pointC == 1 && digitC == len - 1;
    bool    isSpecialz = str == "nan" || isInf(str);

    double d = std::atof(str.c_str());

    return std::pair<bool, double> (isSpecialz || isDouble, d);
}

bool    isNumeric(std::string &str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;

    for (; i < static_cast<int>(str.length()); i++)
        if (!std::isdigit(str[i]))  return false;
    return true;
}

std::pair<bool, int>    isInt(std::string &str)
{
    long    num = std::atol(str.c_str());

    if (isNumeric(str) && !(str.length() > 11 ||\
        num > INT_MAX || \
        num < INT_MIN))
        return std::pair<bool, int> (true, num);
    
    return std::pair<bool, int> (false, -1);
}

std::pair<bool, float>    isFloat(std::string &str)
{
    int pointC = 0;
    int fC = 0;
    int digitC = 0;
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;

    int strLen = str.length() - i;

    for (; i < strLen + 1; i++)
    {
        switch (str[i])
        {
            case '.':
                pointC++;
                break;
            case 'f':
                fC++;
                break;
            default:
                if (isdigit(str[i]))
                    digitC++;
                break;
        }
    }

    bool isFloat = digitC == strLen - 2 && fC == 1 && pointC == 1 && str[str.length() - 1] == 'f';
    bool isSpecialz = str == "nanf" || isInff(str);

    float f = static_cast<float>(std::atof(str.c_str()));
    return std::pair<bool, float> (isSpecialz || isFloat, f);
}

