#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2 && RPN::isValidExpression(argv[1]))
    {
        try
        {
            int ans = RPN::calculate(argv[1]);
            std::cout << ans << std::endl;
        }
        catch (std::exception &ex)
        {
            std::cout << "Exception: " << ex.what() << std::endl;
        }
    }
    else if (argc != 2)
    {
        std::cout
        << "Usage: ./rpn expression_to_evaluate\nexpression_to_evaluate - expression in RPN format that will be calculated" <<
        std::endl;
    }
}