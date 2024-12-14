#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        static void convert(std::string &str);
};

#endif