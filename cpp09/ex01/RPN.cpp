#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

bool    isSign(const std::string &str);
bool    isNumber(const std::string &str);

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(int val)
{
    this->_value = val;
}

RPN::RPN(const RPN &rpn)
{
    this->_value = rpn._value;
}

RPN &RPN::operator=(const RPN &rpn)
{
    if (this != &rpn)
    {
        this->_value = rpn._value;
    }

    return *this;
}

int RPN::operator+(const RPN &rpn)
{
    return this->_value + rpn._value;
}

int RPN::operator-(const RPN &rpn)
{
    return this->_value - rpn._value;
}

int RPN::operator/(const RPN &rpn)
{
    if (rpn._value == 0)
        throw std::runtime_error("Division by zero");
    else
        return this->_value / rpn._value;
}

int RPN::operator*(const RPN &rpn)
{
    return this->_value * rpn._value;
}

bool    isSign(const std::string &str)
{
    if (str == "+" || str == "-" || str == "*" || str == "/")
        return true;
    return false;
}

bool    isNumber(const std::string &str)
{
    unsigned int i = 0;

    for (; i < str.length() && std::isdigit(str[i]); i++) ;

    return str.length() != 0 && str.length() < 2 && str.length() == i;
}

bool    RPN::isValidExpression(const char *str)
{
    std::istringstream  is;
    is.str(str);

    int count = 0;
    for (std::string token; std::getline(is, token, ' '); )
    {
        if (!token.empty())
        {
            if (!(isNumber(token) || isSign(token)))
            {
                std::cerr << "Error: Invalid token " << "[" << token << "]. Expected: 0123456789+-/*" << std::endl; 
                return false;
            }
            else if (isNumber(token))
                count++;
            else if (isSign(token))
                count--;

            if (count < 1)
            {
                std::cerr << "Error: Incorrect format" << std::endl;
                return false;
            }
        }
    }

    if (count != 1)
    {
        std::cerr << "Error: Incorrect format" << std::endl;
        return false;
    }
    return true;
}

void    RPN::calculate(const char *str)
{
    std::istringstream  is;
    is.str(str);

    std::stack<int> st;

    for (std::string token; std::getline(is, token, ' '); )
    {
        if (!token.empty())
        {
            if (isNumber(token))
                st.push(atoi(token.c_str()));
            else
            {
                char c = token[0];

                RPN first(st.top());
                st.pop();

                RPN second(st.top());
                st.pop();

                switch (c)
                {
                    case Addition:
                        st.push(second + first);
                        break;
                    case Subtraction:
                        st.push(second - first);
                        break;
                    case Multiplication:
                        st.push(second * first);
                        break;
                    case Division:
                        st.push(second / first);
                        break;
                }
            }
        }
    }

    std::cout << st.top() << std::endl;
}