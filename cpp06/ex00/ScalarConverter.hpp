#ifndef SCALAR_CONVERTER
# define SCALAR_CONVERTER

#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        static void convert(std::string &str);
};

#endif