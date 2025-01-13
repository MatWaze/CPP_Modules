#ifndef RPN_HPP
# define RPN_HPP

enum Sign
{
    Addition = '+',
    Subtraction = '-',
    Multiplication = '*',
    Division = '/'
};

class RPN
{
    private:
        int _value;
    public:
        RPN();
        RPN(int val);
        RPN(const RPN &rpn);
        ~RPN();

        RPN &operator=(const RPN &rpn);

        int operator+(const RPN &rpn);
        int operator-(const RPN &rpn);
        int operator/(const RPN &rpn);
        int operator*(const RPN &rpn);

        static bool isValidExpression(const char *str);
        static void calculate(const char *str);
};

#endif