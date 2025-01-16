#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "RPN.hpp"

# define INCORRECT_FORMAT "Error: Incorrect format\n"

void CHECK_OUTPUT(bool (*f)(const char *), const std::string expr, const std::string error)
{
    std::streambuf* oldBuf = std::cerr.rdbuf();
    
    std::ostringstream oss;
    std::cerr.rdbuf(oss.rdbuf());
    
    f(expr.c_str());

    std::string output = oss.str();
    std::cerr.rdbuf(oldBuf);

    CHECK_EQ(output, error);
}

std::string invalidTokenError(const std::string token)
{
    return "Error: Invalid token [" + token + "]. Expected: 0123456789+-/*\n";
}

TEST_CASE("Testing RPN calculator")
{
    CHECK_EQ(RPN::calculate("  1  2 +  "), 1 + 2);
    CHECK_EQ(RPN::calculate("  1  2 - "), 1 - 2);
    CHECK_EQ(RPN::calculate("  1  2    /"), 1 / 2);
    CHECK_EQ(RPN::calculate("  1  2 *"), 1 * 2);
    CHECK_EQ(RPN::calculate("1  2  + 3 3 * *"), (1 + 2) * 3 * 3); // 27
    CHECK_EQ(RPN::calculate("1   2 + 3 3 * /"), (1 + 2) / (3 * 3)); // 1
    CHECK_EQ(RPN::calculate("4 3 / 1 1 / *"), (4 / 3) / (1 * 1)); // 0
    CHECK_EQ(RPN::calculate("9   9 9  9   *   * *"), 9 * 9 * 9 * 9); // 729
    CHECK_EQ(RPN::calculate("1   1   2 2 - - -"), (1 - 1) - (2 - 2)); // 0
    CHECK_EQ(RPN::calculate("  1 9 + 5 / 2 -"), (1 + 9) / 5 - 2); // 0
    CHECK_EQ(RPN::calculate("  9 9 9 9 9 9 9 9 9 9 * * * * * * * *"), 387420489);
    CHECK_EQ(RPN::calculate("9 9  9 9 9 9 9 9 9 9 9 * * * * * * - * *"), -387419760);
    CHECK_EQ(RPN::calculate("9 9 9  9 9 9 * * * * * 8 2 - /"), (9 * 9 * 9 * 9 * 9 * 9) / (8 - 2)); // 88573
    CHECK_EQ(RPN::calculate("1 1 1 1 - - * 2 4 - -"), ((1 - (1 - 1)) * 1) - (2 - 4)); // 3

    CHECK_EQ(RPN::calculate("5 3 8 4 * 2 + * 3 4 7 2 * + 5 2 * 6 + / - - -"), -95);
    CHECK_EQ(RPN::calculate("4 0 9 * 2 - + 3 9 - + 9 1 - * 4 / 5 5 4 - - * 2 * 3 1 2 9 2 8 - / 9 - - - 4 * - -"), -111);
    CHECK_EQ(RPN::calculate("4 0 9 * 2 - + 3 9 - + 9 1 - * 4 / 5 5 4 - - * 2 * 3 1 2 9 2 8 - / 9 - - - 4 * - - 5 3 8 4 * 2 + * 3 4 7 2 * + 5 2 * 6 + / - - - +"), -111 - 95);
    
    CHECK_EQ(RPN::calculate("3 8 9 2 / - 3 / + 2 * 3 3 3 1 / / / / 9 * 4 - 1 2 3 4 + / 3 4 - - + + 9 - 8 7 5 * * -"), -273);
    CHECK_EQ(RPN::calculate("9 9 * 4 - 1 2 3 4 + / 3 4 - - + + 9 - 8 7 5 * * - 3 8 9 2 / - 3 / + 2 * 3 3 3 1 / / / / /"), -105);
    CHECK_EQ(RPN::calculate("3 8 - 4 2 4 5 6 9 + - / 2 - 4 5 3 - + + / * 3 8 - 4 2 4 5 6 9 + - / 2 - 4 5 3 - + + / * * - - 3 8 - 4 2 4 5 6 9 + - / 2 - 4 5 3 - + + / * 3 8 - 4 2 4 5 6 9 + - / 2 - 4 5 3 - + + * - * + - /  4 5 6 9 + - / 2 - 4 5 3 - + + / 3 8 - 4 2 4 5 6 9 + - / 2 - 4 5 3 - 4 3 9 1 4 / * * * * - /  - - - + "), -7);

    CHECK_THROWS_MESSAGE(RPN::calculate("1 0 /"), "Division by zero");
    CHECK_THROWS_MESSAGE(RPN::calculate("1 1 - 0 /"), "Division by zero");
    CHECK_THROWS_MESSAGE(RPN::calculate("9 2 2 - /"), "Division by zero");
    CHECK_THROWS_MESSAGE(RPN::calculate("0 0 /"), "Division by zero");
}

TEST_CASE("Testing RPN validation")
{
    CHECK_OUTPUT(RPN::isValidExpression, "", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "              ", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "+", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "+ +", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "- + / *", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "* -", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "3 + 3", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "3 3 + +", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "+ 3 3", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "3 3", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "3 3 * 6", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "6 + - 3 * 3 *", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "- 3 * 3 *", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "9 9 * 7", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "9 9 * 7 - -", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "9 9 * 7 - 5 8 3 9 - + -", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "9 9 9 9 9 9 - - - - - -", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "9 9 9 9 9 9 - - - -", INCORRECT_FORMAT);
    CHECK_OUTPUT(RPN::isValidExpression, "9 9 9 9 9 9 - - - - - - -", INCORRECT_FORMAT);

    CHECK_OUTPUT(RPN::isValidExpression, "\t", invalidTokenError("\t"));
    CHECK_OUTPUT(RPN::isValidExpression, "?", invalidTokenError("?"));
    CHECK_OUTPUT(RPN::isValidExpression, "3 7 %", invalidTokenError("%"));
    CHECK_OUTPUT(RPN::isValidExpression, "3+7", invalidTokenError("3+7"));
    CHECK_OUTPUT(RPN::isValidExpression, "10 9 -", invalidTokenError("10"));

    CHECK_OUTPUT(RPN::isValidExpression, "9999999999999999999999999999999999999999999999999999999",
        invalidTokenError("9999999999999999999999999999999999999999999999999999999"));
    
    CHECK_OUTPUT(RPN::isValidExpression, "-0", invalidTokenError("-0"));
    CHECK_OUTPUT(RPN::isValidExpression, "1 -1 +", invalidTokenError("-1"));
    CHECK_OUTPUT(RPN::isValidExpression, "1 1+", invalidTokenError("1+"));
    CHECK_OUTPUT(RPN::isValidExpression, "+1 1 +", invalidTokenError("+1"));
    CHECK_OUTPUT(RPN::isValidExpression, "1 2 \\", invalidTokenError("\\"));
    CHECK_OUTPUT(RPN::isValidExpression, "01 2 +", invalidTokenError("01"));
    CHECK_OUTPUT(RPN::isValidExpression, "1088 2 -", invalidTokenError("1088"));
    CHECK_OUTPUT(RPN::isValidExpression, "1 2 3 4 5 6 7 8 9 - 42 +", invalidTokenError("42"));
    CHECK_OUTPUT(RPN::isValidExpression, "5jhhtgj ", invalidTokenError("5jhhtgj"));
    
    CHECK_OUTPUT(RPN::isValidExpression, "1 2 4 5 6 a b c d e f g h  s d z e q l l e e r t", 
        invalidTokenError("a"));
    
    CHECK_OUTPUT(RPN::isValidExpression, "(1 1 +)", invalidTokenError("(1"));
}